#include "Color.hpp"
#include <sstream>

#include "UtilsException.hpp"

using std::ostringstream;

map<string, Color> Color::_colors;

Color::Color(unsigned char red, unsigned char green, unsigned char blue) : _red(red), _green(green), _blue(blue)
{
    
}



void Color::initColorMap()
{
    Color::_colors.insert(pair<string, Color>("red", Color(255, 0, 0)));
    Color::_colors.insert(pair<string, Color>("green", Color(0, 255, 0)));
    Color::_colors.insert(pair<string, Color>("blue", Color(0, 0, 255)));
    Color::_colors.insert(pair<string, Color>("black", Color(0, 0, 0)));
    Color::_colors.insert(pair<string, Color>("white", Color(255, 255, 255)));
    Color::_colors.insert(pair<string, Color>("grey", Color(127, 127, 127)));
}

Color Color::getColor(const string & color)
{
    // Initialize the map only if it hasn't already be done.
    if (_colors.empty())
        initColorMap();

    map<string, Color>::iterator it;

    it = _colors.find(color);
    if (it != _colors.end())
    {
        return _colors.find(color)->second;
    }
    else
    {
        throw UtilsException("La couleur n'a pas été trouvée.");
    }
}

unsigned char Color::getRed() const
{
    return _red;
}

unsigned char Color::getGreen() const
{
    return _green;
}

unsigned char Color::getBlue() const
{
    return _blue;
}

Color::operator string() const
{
    ostringstream os;
    os << (int) _red << "," << (int)_green << "," << (int)_blue;
    return os.str();
}

ostream & operator<<(ostream & os, const Color & color)
{
    os << (string) color;
    return os;
}
