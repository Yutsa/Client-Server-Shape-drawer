#include "ShapeCreatorLink.hpp"
#include "ShapeLoaderException.hpp"

#include <iostream>

ShapeCreatorLink::ShapeCreatorLink(ShapeCreatorLink* next)
{
    _next = next;
}

Shape* ShapeCreatorLink::createShape(const string & shapeString) const
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

vector<string> func::split(const string & s, char sep)
{
    vector<string> Strings;

    string::size_type prev_pos = 0, pos = 0;

    while((pos = s.find(sep, pos)) != string::npos)
    {
        string substring(s.substr(prev_pos, pos-prev_pos));
        Strings.push_back(substring);
        prev_pos = ++pos;
    }
    Strings.push_back(s.substr(prev_pos, pos-prev_pos)); // Last word

    return Strings;
}
