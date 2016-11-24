#include "ComposedShapeCreator.hpp"
#include "ShapeLoaderException.hpp"
#include "../Shape/ComposedShape.hpp"

#include <iostream>
#include <cstdlib>

using std::atoi;
using std::atof;

ComposedShapeCreator::ComposedShapeCreator(ShapeCreatorLink *next) : ShapeCreatorLink(next)
{
    
}

Shape* ComposedShapeCreator::createShapeSpe(const string & shapeString) const
{
    vector<string> shapeStrings = func::split(shapeString, '|');

    if(shapeStrings[0] != "composedShape")
    {
        throw ShapeLoaderException("Not a ComposedShape");
    }
    else
    {
        ComposedShape *cp = new ComposedShape();
        
        for(int i = 1; i < shapeStrings.size(); i++)
        {
            std::cout << "i : " << i << " -> " << shapeStrings[i] << std::endl;
            cp->addShape(createShape(shapeStrings[i]));
        }
        
        return cp;
    }
}