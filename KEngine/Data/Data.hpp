#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <iostream>
#include <string>
#include <sstream>

#define PI 3.14159265358979323846

namespace ke
{

enum Pos
{
    LEFT_TOP,           //  |--------------------------------------------|
    MIDDLE_TOP,         //  | LEFT_TOP      MIDDLE_TOP      RIGHT_TOP    |
    RIGHT_TOP,          //  |                                            |
    LEFT_MIDDLE,        //  |                                            |
    MIDDLE_MIDDLE,      //  | LEFT_MIDDLE   MIDDLE_MIDDLE   RIGHT_MIDDLE |
    RIGHT_MIDDLE,       //  |                                            |
    LEFT_BOTTOM,        //  |                                            |
    MIDDLE_BOTTOM,      //  | LEFT_MIDDLE   MIDDLE_BOTTOM   RIGHT_BOTTOM |
    RIGHT_BOTTOM        //  |--------------------------------------------|
};

enum Font
{
    Arial,
    Arial_Uni,
    Calibri,
    ComicSans,
    CourierNew,
    TimesNewRoman,
    TrebuchetMS,
    Verdana
};

enum TextScope
{
    Everything,
    ASCII_Everything, // English letters only
    Letters_PMarks, // letters and punctuation marks (,.;'[]/-=+? etc...)
    Numbers,
    Letters,
    Math,
};

}

#endif // DATA_HPP_INCLUDED
