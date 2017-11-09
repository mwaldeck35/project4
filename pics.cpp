/**
 * pics.cpp
 *
 * EECS 183, Fall 2017
 * Project 4: CoolPics
 *
 * matt waldeck, annmarie zheng
 * mwaldeck, annzheng
 *
 * creates images for eecs183 project4
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints an opening message.
 */
void printOpener();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a closing message.
 */
void printCloser();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a menu.
 */
void printMenu();

/**
 * Requires: ins is in good state.
 * Modifies: cin, ins.
 * Effects:  Closes ins if it is open. Keeps reading filename from the user
 *           (and appends .txt) until the file is successfully opened.
 *           Returns the name of the file that was opened.
 */
string openFile(ifstream& ins);

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns str with all of its alphabetical characters lowercased.
 */
string tolower(string str);

/**
 * Requires: Nothing.
 * Modifies: cin, drawer.
 * Effects:
 *     Opens a file
 *     Start with a blank canvas (drawer)
 *     Start reading from file.  For each line....
 *        Read the 1st character to determine shape
 *        Read the shape:  L reads a line, C reads a circle, T read a triangle
 *            R reads a rectangle.
 *            For any other character, clears drawer and prints
 *            "Error in input file: " << [character already read]
 *            << [all chars remaining on the line] << endl;
 *        Draw shape on canvas
 *     Close file
 *     Print "[Loaded filename]"
 */
void loadFile(Graphics& drawer);

/**
 * Requires: Nothing.
 * Modifies: cout, drawer.
 * Effects:
 *     Read filename from user
 *     concatenate filename with .bmp
 *     Write image to file.
 *     Print "[Wrote filename]"
 */
void writeFile(const Graphics& drawer);

int main()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();
}

void writeFile(const Graphics& drawer)
{
    // TODO: implement
    // This will make use of Graphics::writeFile()
    string fileName;
    cin >> fileName;
    fileName += ".bmp";
    drawer.writeFile(fileName);
    cout << "[Wrote " << fileName << "]" << endl;
}

void loadFile(Graphics& drawer)
{
    drawer.clear();
    string fileName;
    ifstream inputFile;
    fileName = openFile(inputFile);
    
    
    char shape;
    while(inputFile >> shape){
        
        if (shape == 'L'){
            Line current;
            current.read(inputFile);
            current.draw(drawer);
        }
        else if (shape == 'T'){
            Triangle current;
            current.read(inputFile);
            current.draw(drawer);
            
        }
        else if (shape == 'R'){
            
            Rectangle current;
            current.read(inputFile);
            current.draw(drawer);
            
        }
        else if (shape == 'C'){
        
            Circle current;
            current.read(inputFile);
            current.draw(drawer);
             
            
            
            
        }
        else {
            string remainingLine;
            getline(inputFile, remainingLine);
            
            cout << "Error in input file: " << shape << " " << remainingLine
            << endl;
            
        }
    }
    inputFile.close();
    cout << "[Loaded " << fileName << "]" << endl;
    
    // TODO: implement
}

string tolower(string str)
{
    
    for (int i = 0; i < str.length(); i++){
        str.at(i) = tolower(str.at(i));
    }
    

    return str;
}


// Don't change the implementations below!

void printMenu()
{
    cout << "Command:            Description:" << endl
         << "--------            ------------" << endl
         << "load filename       Loads data from a txt file" << endl
         << "write filename      Creates a bmp image from data" << endl
         << "quit                Quits the program" << endl << endl;
}


void printOpener()
{
    cout << "=================================================" << endl
         << "               Welcome to CoolPics" << endl
         << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
         << "            Thanks for using CoolPics!" << endl
         << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;

    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }

    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);

    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";
        ins.open(fileName);
    }

    return fileName;
}
