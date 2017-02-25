#include "SegmentCreator.hpp"
#include "ShapeLoaderException.hpp"
#include "../Shape/Segment.hpp"

#include <iostream>
#include <cstdlib>

using std::atoi;
using std::atof;

SegmentCreator::SegmentCreator(ShapeCreatorLink *next) : ShapeCreatorLink(next)
{

}

Shape* SegmentCreator::createShapeSpe(const string & shapeString) const
{
    vector<string> shapeStrings = func::split(shapeString, ',');

    if(shapeStrings[0] != "segment")
    {
        throw ShapeLoaderException("Not a segment");
    }
    else
    {
        unsigned char r = (unsigned char)atoi(shapeStrings[1].c_str()),
                    g = (unsigned char)atoi(shapeStrings[2].c_str()),
                    b = (unsigned char)atoi(shapeStrings[3].c_str());

        Color color(r, g, b);

        double px1 = atof(shapeStrings[4].c_str()),
                py1 = atof(shapeStrings[5].c_str()),
                px2 = atof(shapeStrings[6].c_str()),
                py2 = atof(shapeStrings[7].c_str());

        Vector2D point1(px1, py1),
                point2(px2, py2);

        Segment *S = new Segment(point1, point2, color);

        return S;
    }
}
