/**
 * Point.cpp
 *
 * EECS 183
 * Lab 6: Classes and File I/O
 * Taken from Project 4: CoolPics
 *
 * matt waldeck, annmarie zheng
 * mwaldeck, annzheng
 *
 * lab 6 for eecs 183
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"


Point::Point() {
    x = 0;
    y = 0;
}
    
Point::Point(int xVal, int yVal) {
    x = xVal;
    y = yVal;
}

void Point::setX(int xVal) {
    x = checkRange(xVal);
    return;
}

int Point::getX() {
    
    return checkRange(x);
}    

void Point::setY(int yVal) {
    y = checkRange(yVal);
    
    return;
}
    
int Point::getY() {
    
    return checkRange(y);
}

void Point::read(istream& ins) {
    
    ins >> x;
    while (ins.fail()){
        ins.clear();
        ins.ignore(1);
        ins >> x;
    }
    ins >> y;
    while (ins.fail()){
        ins.clear();
        ins.ignore(1);
        ins >> y;
    }
    ins.ignore(1);

    return;
}    

void Point::write(ostream& outs) {
    outs << "(";
    outs << checkRange(x);
    outs << ",";
    outs << checkRange(y);
    outs << ")";
    
    
    return;
}

int Point::checkRange(int val) {
    if (val < 0){
        return 0;
    }
    if (val > DIMENSION - 1){
        return DIMENSION - 1;
    }
    return val;
}

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}

