#include "PolygonCreator.hpp"
#include "ShapeLoaderException.hpp"
#include "../Shape/Polygon.hpp"

#include <iostream>
#include <cstdlib>

using std::atoi;
using std::atof;

PolygonCreator::PolygonCreator(ShapeCreatorLink *next) : ShapeCreatorLink(next)
{
    
}

Shape* PolygonCreator::createShapeSpe(const string & shapeString) const
{
    vector<string> shapeStrings = func::split(shapeString, ',');
    
    if(shapeStrings[0] != "polygon")
    {
        throw ShapeLoaderException("Not a Polygon");
    }
    else
    {
        unsigned char r = (unsigned char)atoi(shapeStrings[1].c_str()),
                    g = (unsigned char)atoi(shapeStrings[2].c_str()),
                    b = (unsigned char)atoi(shapeStrings[3].c_str());
        
        Color color(r, g, b);
        
        vector<double> coor;
        
        for (int i = 4; i < shapeStrings.size(); i++)
        {
            coor.push_back(atof(shapeStrings[i].c_str()));
        }
        
        vector<Vector2D> points;
        
        for (int i = 0; i < coor.size(); i += 2)
        {
            points.push_back(Vector2D(coor[i], coor[i+1]));
        }
        
        Polygon *P = new Polygon(color);
        
        for (int i = 0; i < points.size(); i++)
        {
            P->addPoint(points[i]);
        }
        
        return P;
    }
}
