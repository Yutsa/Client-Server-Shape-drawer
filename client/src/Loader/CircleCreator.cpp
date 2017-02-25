#include "CircleCreator.hpp"
#include "ShapeLoaderException.hpp"
#include "../Shape/Circle.hpp"

#include <iostream>
#include <cstdlib>

using std::atoi;
using std::atof;

CircleCreator::CircleCreator(ShapeCreatorLink *next) : ShapeCreatorLink(next)
{
    
}

Shape* CircleCreator::createShapeSpe(const string & shapeString) const
{
    vector<string> shapeStrings = func::split(shapeString, ',');
        
    if(shapeStrings[0] != "circle")
    {
        throw ShapeLoaderException("Not a Circle");
    }
    else
    {

        unsigned char r = (unsigned char)atoi(shapeStrings[1].c_str()),
                    g = (unsigned char)atoi(shapeStrings[2].c_str()),
                    b = (unsigned char)atoi(shapeStrings[3].c_str());
        
        Color color(r, g, b);
        
        double px1 = atof(shapeStrings[4].c_str()),
                py1 = atof(shapeStrings[5].c_str()),
                diameter = atof(shapeStrings[6].c_str());
        
        Vector2D point1(px1, py1);
        
        Circle *C = new Circle(point1, diameter, color);
                
        return C;
    }
}
