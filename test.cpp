//
//  test.cpp
//  project4
//
//  Matt Waldeck, Annmarie Zheng
//  mwaldeck, annzheng
//

#include <iostream>
#include "Graphics.h"
#include "Color.h"
#include "Point.h"
#include "Line.h"
#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include <fstream>
#include <iostream>
using namespace std;

void test_graphics();
void test_color();
void test_circle();
void test_triangle();
void test_rectangle();
void test_line();
void test_point();
void test_rw();

int main(void){
    test_graphics();
    test_color();
    test_circle();
    test_triangle();
    test_rectangle();
    test_line();
    test_point();
    test_rw();
}

void test_graphics(){
    Graphics draw1;
    Color color1(999,-100,2);
    draw1.setPixel(99,0, color1);
    
}

void test_color(){
    Color color;
    cout << color.getGreen() << endl;
    cout << color.getRed() << endl;
    cout << color.getBlue() << endl;
    Color color2(50,50,-100);
    cout << color.getGreen() << endl;
    cout << color.getBlue() << endl;
    cout << color.getRed() << endl;
    color.setRed(100);
    color.setGreen(900);
    color.setBlue(-100);
    cout << color.getRed() << endl;
    cout << color.getGreen() << endl;
    cout << color.getBlue() << endl;
    
    ofstream file;
    ifstream file2;
    file2.open("data1.txt");
    file.open("data1.txt");
    color.write(file);
    color2.read(file2);
    file.close();
}

void test_circle(){
    Circle circ1;
    cout << circ1.getCenter() << endl;
    cout << circ1.getRadius() << endl;
    cout << circ1.getColor().getGreen() << endl;
    cout << circ1.getColor().getRed() << endl;
    cout << circ1.getColor().getBlue() << endl;
    Point pt1(20,30);
    Color color1(100,100,100);
    Circle circ2(pt1, -100, color1);
    cout << circ2.getCenter() << endl;
    cout << circ2.getRadius() << endl;
    cout << circ2.getColor() << endl;
    Circle circ3(pt1,2,color1);
    circ1.setCenter(pt1);
    cout << circ1.getCenter() << endl;
    circ1.setRadius(2);
    cout << circ1.getRadius() << endl;
    circ1.setColor(color1);
    cout << circ1.getColor() << endl;
    
}
void test_triangle(){
    Triangle tri1;
    cout << tri1.getVertexOne() << endl;
    cout << tri1.getVertexTwo() << endl;
    cout << tri1.getVertexThree() << endl;
    cout <<  tri1.getVertexOneColor() << endl;
    cout << tri1.getVertexTwoColor() << endl;
    cout << tri1.getVertexThreeColor().getGreen() << endl;
    cout << tri1.getVertexThreeColor().getBlue() << endl;
    cout << tri1.getVertexThreeColor().getRed() << endl;
    Point pt1;
    Color color(900,900,900);
    Color color2(100,100,100);
    Triangle tri2(pt1, pt1, pt1, color);
    cout << tri2.getVertexOne() << endl;
    cout << tri2.getVertexTwo() << endl;
    cout << tri2.getVertexThree().getX() << endl;
    cout << tri2.getVertexThree().getY() << endl;
    cout <<  tri2.getVertexOneColor() << endl;
    cout << tri2.getVertexTwoColor() << endl;
    cout << tri2.getVertexThreeColor() << endl;
    Triangle tri3(pt1,color,pt1,color,pt1,color2);
    cout << tri3.getVertexOne() << endl;
    cout << tri3.getVertexTwo() << endl;
    cout << tri3.getVertexThree() << endl;
    cout <<  tri3.getVertexOneColor() << endl;
    cout << tri3.getVertexTwoColor() << endl;
    cout << tri3.getVertexThreeColor() << endl;
    tri1.setColor(color2);
    cout << tri1.getVertexOneColor() << endl;
    tri1.setVertexOne(pt1);
    cout << tri1.getVertexOne() << endl;
    tri1.setVertexTwo(pt1);
    cout << tri1.getVertexTwo() << endl;
    tri1.setVertexThree(pt1);
    cout << tri1.getVertexThree() << endl;
    cout << tri1.getVertexTwoColor() << endl;
    cout << tri1.getVertexThreeColor() << endl;
}
void test_line(){
    Line line;
    cout << line.getStart() << endl;
    cout << line.getEnd() << endl;
    cout << line.getColor() << endl;

    Point pt;
    Point pt2(2,2);
    Point pt3(5,5);
    Color col(900,900,900);
    Line line2(pt,pt2, col);
    cout << line2.getStart() << endl;
    cout << line2.getEnd() << endl;
    cout << line2.getColor() << endl;
    line.setStart(pt2);
    cout << line.getStart() << endl;
    line.setEnd(pt3);
    cout << line.getEnd() << endl;
    Color color(100,44,100);
    line.setColor(color);
    cout << line.getColor() << endl;
    
}
void test_rectangle(){
    Rectangle rect;
    Point pt1;
    Color col(900,900,900);
    Color col2(30,30,30);
    Color col3(15,15,15);
    Rectangle rect2(pt1,pt1,col);
    cout << rect2.getStart() << endl;
    cout << rect2.getEnd() << endl;
    cout << rect2.getColorTopLeft().getGreen() << endl;
    cout << rect2.getColorTopLeft().getBlue() << endl;
    cout << rect2.getColorTopLeft().getRed() << endl;
    cout << rect2.getColorTopRight().getGreen() << endl;
    cout << rect2.getColorTopRight().getRed() << endl;
    cout << rect2.getColorTopRight().getBlue() << endl;
    cout << rect2.getColorBottomRight().getGreen() << endl;
    cout << rect2.getColorBottomRight().getBlue() << endl;
    cout << rect2.getColorBottomRight().getRed() << endl;
    cout << rect2.getColorBottomLeft().getGreen() << endl;
    cout << rect2.getColorBottomLeft().getBlue() << endl;
    cout << rect2.getColorBottomLeft().getRed() << endl;
    Rectangle rect3(pt1,pt1,col,col,col,col);
    cout << rect3.getStart() << endl;
    cout << rect3.getEnd() << endl;
    cout << rect3.getColorTopLeft() << endl;
    cout << rect3.getColorTopRight() << endl;
    cout << rect3.getColorBottomRight() << endl;
    cout << rect3.getColorBottomLeft() << endl;
    rect.setStart(pt1);
    cout << rect.getStart() << endl;
    rect.setEnd(pt1);
    cout << rect.getEnd() << endl;
    rect2.setColor(col2);
    cout << rect2.getColorTopLeft() << endl;
    cout << rect2.getColorTopRight() << endl;
    cout << rect2.getColorBottomLeft() << endl;
    cout << rect2.getColorBottomRight() << endl;
    rect2.setColorTopLeft(col3);
    rect2.setColorTopRight(col3);
    rect2.setColorBottomLeft(col3);
    rect2.setColorBottomRight(col3);
    cout << rect2.getColorTopLeft() << endl;
    cout << rect2.getColorTopRight() << endl;
    cout << rect2.getColorBottomLeft() << endl;
    cout << rect2.getColorBottomRight() << endl;
    
}
void test_point(){
    Point pt1;
    Point pt(100, -1);
    pt.setX(101);
    pt.setY(-2);
    pt.setX(50);
    pt.setY(25);
    cout << pt.getX() << endl;
    cout << pt.getY() << endl;
}
void test_rw(){
    Point pt(1,2);
    Point pt2(3,4);
    Point pt3(4,5);
    Color col(30,30,30);
    Line line(pt, pt2, col);
    Rectangle rect(pt, pt3, col);
    Triangle tri(pt,pt2,pt3, col);
    Circle circ(pt3,20, col);
    
    ofstream file1;
    file1.open("data2.txt");
    
    pt.write(file1);
    line.write(file1);
    rect.write(file1);
    tri.write(file1);
    circ.write(file1);
    
    file1.close();
    
    ifstream file2;
    file2.open("data2.txt");
    
    pt.read(file2);
    line.read(file2);
    rect.read(file2);
    tri.read(file2);
    circ.read(file2);
    
    file2.close();
    
    cout << pt.getX() << endl;
    cout << pt.getY() << endl;
    cout << rect.getStart() << endl;
    cout << rect.getEnd() << endl;
    cout << tri.getVertexOne() << endl;
    cout << tri.getVertexTwo() << endl;
    cout << tri.getVertexThree() << endl;
    cout << circ.getCenter() << endl;
    cout << circ.getRadius() << endl;
    
    
    
    
}
