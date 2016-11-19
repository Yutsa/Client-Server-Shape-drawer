#include <iostream>
#include <cstring>
#include <fstream>
#include "SaveTextVisitor.hpp"
#include "../Shape/Circle.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"
#include "../Shape/Polygon.hpp"

using std::string;
using std::ofstream;

void SaveTextVisitor::save(const Circle *circle,
    const string & filename) const
{
    char* path;
    ofstream file;
    string textShape = (string) *circle;
    path = getenv("HOME");
    if (path != NULL)
    {
        strcat(path, "/");
        strcat(path, filename.c_str());
        file.open(path);
        file << textShape << "\n";
        file.close();
    }
}

void SaveTextVisitor::save(const Segment *segment,
    const string & filename) const
{
    char* path;
    ofstream file;
    string textShape = (string) *segment;
    path = getenv("HOME");
    if (path != NULL)
    {
        strcat(path, "/");
        strcat(path, filename.c_str());
        file.open(path);
        file << textShape << "\n";
        file.close();
    }
}

void SaveTextVisitor::save(const Triangle *triangle,
    const string & filename) const
{
    char* path;
    ofstream file;
    string textShape = (string) *triangle;
    path = getenv("HOME");
    if (path != NULL)
    {
        strcat(path, "/");
        strcat(path, filename.c_str());
        file.open(path);
        file << textShape << "\n";
        file.close();
    }
}

void SaveTextVisitor::save(const Polygon *polygon,
    const string & filename) const
{
    char* path;
    ofstream file;
    string textShape = (string) *polygon;
    path = getenv("HOME");
    if (path != NULL)
    {
        strcat(path, "/");
        strcat(path, filename.c_str());
        file.open(path);
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
