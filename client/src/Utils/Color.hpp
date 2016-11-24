#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <map>

using std::string;
using std::map;
using std::pair;
using std::ostream;


/**
* Represents RGB Color
*/
class Color
{
private:
    unsigned char _red;
    unsigned char _green;
    unsigned char _blue;

    static map<string, Color> _colors;

public:
    /**
    * Constructor for Color
    * @param red unsigned char for red intensity
    * @param green unsigned char for green intensity
    * @param blue unsigned char for blue intensity
    */
    Color(unsigned char red, unsigned char green, unsigned char blue);


    /**
    * Initialize map of color
    */
    static void initColorMap();

    /**
    * Gets color in map with a string
    * @param color string of the color
    * @throws UtilsException When color isn't found in the array of colors
    * @return The corresponding Color object
    */
    static Color getColor(const string & color);


    /**
    * Gets _red intensity
    * @return red intensity
    */
    unsigned char getRed() const;

    /**
    * Gets _green intensity
    * @return green intensity
    */
    unsigned char getGreen() const;

    /**
    * Gets _blue intensity
    * @return blue intensity
    */
    unsigned char getBlue() const;

    /**
    * Operator cast to string
    */
    operator string() const;

    friend ostream & operator<<(ostream & os, const Color & color);
};

extern ostream & operator<<(ostream & os, const Color & color);

#endif
