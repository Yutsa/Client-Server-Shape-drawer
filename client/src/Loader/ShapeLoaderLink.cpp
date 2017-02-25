#include "ShapeLoaderLink.hpp"
#include "ShapeLoaderException.hpp"

ShapeLoaderLink::ShapeLoaderLink(const ShapeLoaderLink* next,
    const ShapeCreator* shapeCreator) : ShapeLoader(shapeCreator)
{
    _next = next;
}

ShapeLoaderLink::~ShapeLoaderLink()
{
    delete _next;
}

Shape* ShapeLoaderLink::load(const string &filename) const
{
    try
    {
        return loadShape(filename);
    }
    catch (ShapeLoaderException e)
    {
        if (_next != NULL)
        {
            return _next->load(filename);
        }
        throw ShapeLoaderException("La forme n'a pas été reconnue.");
    }
}
