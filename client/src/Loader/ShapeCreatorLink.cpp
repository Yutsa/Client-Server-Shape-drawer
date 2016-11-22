#include "ShapeCreatorLink.hpp"

#include <vector>


ShapeCreatorLink::ShapeCreatorLink(const ShapeCreatorLink* next)
{
    _next = next;
}

const Shape* ShapeCreatorLink::createShape(const string & shapeString) const
{
    try 
    {
        return createShapeSpe(shapeString);
    }
    catch (ShapeLoaderException e)
    {
        if (_next != NULL)
        {
            return _next->createShape(shapeString);
        }
        else
        {
            throw ShapeLoaderException("La forme n'a pas pus être chargée");
        }
    }
}