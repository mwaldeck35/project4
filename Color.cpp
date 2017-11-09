/**
 * Color.cpp
 *
 * EECS 183, Fall 2017
 * Project 4: CoolPics
 *
 * matt waldeck, annmarie zheng
 * mwaldeck, annzheng
 *
 * color file for eecs183 project 4
 */

#include "Color.h"





Color::Color(){
    red = 0;
    green = 0;
    blue = 0;
}

Color::Color(int redVal, int greenVal, int blueVal){
    
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

void Color::setRed(int redVal){
    red = checkRange(redVal);
    return;
}

int Color::getRed(){
    return red;
}

void Color::setGreen(int greenVal){
    green = checkRange(greenVal);
    return;
}

int Color::getGreen(){
    return green;
}

void Color::setBlue(int blueVal){
    blue = checkRange(blueVal);
    return;
}

int Color::getBlue(){
    return blue;
}

void Color::read(istream& ins){
    
    ins >> red;
    ins >> green;
    ins >> blue;
    
    red = checkRange(red);
    green = checkRange(green);
    blue = checkRange(blue);
    return;
}

void Color::write(ostream& outs){
    //writing colors in RGB format
    outs << red << " ";
    outs << green << " ";
    outs << blue << " ";
}




int Color::checkRange(int val){
    if (val < 0){
        return 0;
    }
    else if (val > 255){
        return 255;
    }
    return val;
}




istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
