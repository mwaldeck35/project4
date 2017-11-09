/**
 * Rectangle.cpp
 *
 * EECS 183, Fall 2017
 * Project 4: CoolPics
 *
 * matt waldeck, annmarie zheng
 * mwaldeck, annzheng
 *
 * eecs183 project 4 rectangle class
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;



Rectangle::Rectangle(){
    
}

Rectangle::Rectangle(Point pt1, Point pt2, Color color){
    start.setX(pt1.getX());
    start.setY(pt1.getY());
    
    end.setX(pt2.getX());
    end.setY(pt2.getY());
    
    colorTopLeft.setRed(color.getRed());
    colorTopLeft.setGreen(color.getGreen());
    colorTopLeft.setBlue(color.getBlue());
    
    colorTopRight.setRed(color.getRed());
    colorTopRight.setGreen(color.getGreen());
    colorTopRight.setBlue(color.getBlue());
    
    colorBottomLeft.setRed(color.getRed());
    colorBottomLeft.setGreen(color.getGreen());
    colorBottomLeft.setBlue(color.getBlue());
    
    
    colorBottomRight.setRed(color.getRed());
    colorBottomRight.setGreen(color.getGreen());
    colorBottomRight.setBlue(color.getBlue());
    
}

Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight, Color cBottomRight, Color cBottomLeft){
    
    start.setX(pt1.getX());
    start.setY(pt1.getY());
    
    end.setX(pt2.getX());
    end.setY(pt2.getY());
    
    colorTopLeft.setRed(cTopLeft.getRed());
    colorTopLeft.setGreen(cTopLeft.getGreen());
    colorTopLeft.setBlue(cTopLeft.getBlue());
    
    colorTopRight.setRed(cTopRight.getRed());
    colorTopRight.setGreen(cTopRight.getGreen());
    colorTopRight.setBlue(cTopRight.getBlue());
    
    colorBottomLeft.setRed(cBottomLeft.getRed());
    colorBottomLeft.setGreen(cBottomLeft.getGreen());
    colorBottomLeft.setBlue(cBottomLeft.getBlue());
    
    
    colorBottomRight.setRed(cBottomRight.getRed());
    colorBottomRight.setGreen(cBottomRight.getGreen());
    colorBottomRight.setBlue(cBottomRight.getBlue());
    
}

void Rectangle::setStart(Point pt){
    start.setX(pt.getX());
    start.setY(pt.getY());
    return;
}

Point Rectangle::getStart(){
    return start;
}

void Rectangle::setEnd(Point pt){
    end.setX(pt.getX());
    end.setY(pt.getY());
    return;
}

Point Rectangle::getEnd(){
    return end;
}

void Rectangle::setColor(Color color){
    
    colorTopLeft.setRed(color.getRed());
    colorTopLeft.setGreen(color.getGreen());
    colorTopLeft.setBlue(color.getBlue());
    
    colorTopRight.setRed(color.getRed());
    colorTopRight.setGreen(color.getGreen());
    colorTopRight.setBlue(color.getBlue());
    
    colorBottomLeft.setRed(color.getRed());
    colorBottomLeft.setGreen(color.getGreen());
    colorBottomLeft.setBlue(color.getBlue());
    
    
    colorBottomRight.setRed(color.getRed());
    colorBottomRight.setGreen(color.getGreen());
    colorBottomRight.setBlue(color.getBlue());
    
    return;
    
}

void Rectangle::setColorTopLeft(Color color){
    
    colorTopLeft.setRed(color.getRed());
    colorTopLeft.setGreen(color.getGreen());
    colorTopLeft.setBlue(color.getBlue());
    return;
}

Color Rectangle::getColorTopLeft(){
    return colorTopLeft;
}
void Rectangle::setColorTopRight(Color color){

    
    colorTopRight.setRed(color.getRed());
    colorTopRight.setGreen(color.getGreen());
    colorTopRight.setBlue(color.getBlue());
    
    return;
}

Color Rectangle::getColorTopRight(){
    return colorTopRight;
}

void Rectangle::setColorBottomRight(Color color){
    
    
    colorBottomRight.setRed(color.getRed());
    colorBottomRight.setGreen(color.getGreen());
    colorBottomRight.setBlue(color.getBlue());
    
    return;
}
Color Rectangle::getColorBottomRight(){
    return colorBottomRight;
}
void Rectangle::setColorBottomLeft(Color color){
    
    colorBottomLeft.setRed(color.getRed());
    colorBottomLeft.setGreen(color.getGreen());
    colorBottomLeft.setBlue(color.getBlue());
    
    return;
}

Color Rectangle::getColorBottomLeft(){
    return colorBottomLeft;
}

void Rectangle::read(istream& ins){
 
    
    start.read(ins);
    end.read(ins);
    colorTopLeft.read(ins);
    colorTopRight.read(ins);
    colorBottomRight.read(ins);
    colorBottomLeft.read(ins);
    
    
    
    if(ins.fail()){
        ins.clear();
        
        colorTopRight.setRed(colorTopLeft.getRed());
        colorTopRight.setBlue(colorTopLeft.getBlue());
        colorTopRight.setGreen(colorTopLeft.getGreen());
    
        colorBottomRight.setRed(colorTopLeft.getRed());
        colorBottomRight.setBlue(colorTopLeft.getBlue());
        colorBottomRight.setGreen(colorTopLeft.getGreen());
    
        colorBottomLeft.setRed(colorTopLeft.getRed());
        colorBottomLeft.setBlue(colorTopLeft.getBlue());
        colorBottomLeft.setGreen(colorTopLeft.getGreen());
    }
    
}

void Rectangle::write(ostream& outs){
    
    start.write(outs);
    end.write(outs);
    colorTopLeft.write(outs);
    colorTopRight.write(outs);
    colorBottomRight.write(outs);
    colorBottomLeft.write(outs);
    
    return;
}





istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
