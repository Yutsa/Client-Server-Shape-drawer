#include "ShapeLoaderText.hpp"
#include "ShapeLoaderException.hpp"
#include "ShapeCreator.hpp"
#include <iostream>
#include <string> // std::string
#include <cstddef> // std::size_t
#include <fstream> // file handling
#include <sstream> // stringstream

using std::string;
using std::size_t;
using std::ifstream;
using std::stringstream;

ShapeLoaderText::ShapeLoaderText(const ShapeLoaderLink* next,
    const ShapeCreator* shapeCreator) :
ShapeLoaderLink(next, shapeCreator)
{

}

Shape* ShapeLoaderText::loadShape(const string & filename) const
{
    // We get the extension of the file
    size_t pointPos = filename.find_last_of(".");
    string extension = filename.substr(pointPos);

    // If this is the correct extension
    if (extension.compare(".save") != 0)
    {
        std::cout << "format not recognized" << std::endl;
        throw ShapeLoaderException("Save format not recognized.");
    }

    string line;
    ifstream myfile (filename);
    stringstream ss;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            ss << line;
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

    std::cout << "Contenu fichier: " << ss.str() << std::endl;
    return _shapeCreator->createShape(ss.str());
    
}
