#include <iostream>
#include <cstring>
#include <fstream>
#include "SaveTextVisitor.hpp"
#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"

using std::string;
using std::ofstream;

void SaveTextVisitor::save(const Circle *circle,
    const string & filename) const
{
    this->save((Shape*) circle, filename);
}

void SaveTextVisitor::save(const Segment *segment,
    const string & filename) const
{
    this->save((Shape*) segment, filename);
}

void SaveTextVisitor::save(const Triangle *triangle,
    const string & filename) const
{
    this->save((Shape*) triangle, filename);
}

void SaveTextVisitor::save(const Polygon *polygon,
    const string & filename) const
{
    this->save((Shape*) polygon, filename);
}

void SaveTextVisitor::save(const Shape* shape,
     const string & filename) const
{
    // Doesn't use HOME anymore!!!
    char* path;
    ofstream file;
    string textShape = (string) *shape;
    path = getenv("HOME");
    if (path != NULL)
    {
        strcat(path, "/");
        strcat(path, filename.c_str());
	//file.open(path);
	file.open(filename);
        file << textShape << "\n";
        file.close();
    }
}

SaveTextVisitor::SaveTextVisitor() : SaveVisitor()
{

}

SaveTextVisitor::~SaveTextVisitor()
{

}
