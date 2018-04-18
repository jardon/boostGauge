// Written by Jarred Wilson
//
// DESCRIPTION: THIS LIBRARY IS DESIGNED TO FACILITATE DATA MANIPULATION FOR AN ADAFRUIT NEOPIXEL.
// THIS DATA STRUCTURE RESEMBLES THAT OF A CIRCULAR ARRAY THAT IS ABLE TO ADD NUMBERS TO THE ARRAY
// EVEN IF THERE IS NO SPACE.  NUMBERS ARE STORED SEQUENTIALLY SO THERE IS NO NEED FOR RANDOM ACCESS
// TO USE THIS LIBRARY YOU WILL US THE MOVETO() FUNCTION TO FORCE THE ARRAY TO ADD NUMBERS ON TOP OF
// EXISTING NUMBERS UNTIL THE DESIRED NUMBER HAS BEEN ADDED.  VALUES ARE TAKEN OUT OF THE STRUCTURE
// WITH THE GETVALUE() FUNCTION.  ALL LED IMPLEMENTATION IS TO BE HANDLED IN THE .INO FILE FOR THE
// ARDUINO.
//
// INSTRUCTIONS:
// 1) PLACE RINGMATRIX.H AND RINGMATRIX.CPP IN THE ARDUINO LIBRARY FOLDER (CREATE A RINGMATRIX FOLDER INSIDE)
// 2) "#INCLUDE 'RINGMATRIX.H'" IN THE .INO FILE TO USE THIS CLASS
// 3) PROFIT
//
// PRECONDITION: elements has to be an integer.  will determine the size of the structure
// POSTCONDITION: new structure created
// ringMatrix(int elements);
//
// PRECONDITION: NONE
// POSTCONDITION: returns the cursor (index)
// int getPosition();
//
// PRECONDITION: value must be an integer value
// POSTCONDITION: structure increments to the desired integer
// void moveTo(int value);
//
// PRECONDITION: NONE
// POSTCONDITION: returns the size of the structure
// int getSize();
//
// PRECONDITION: location must be a valid index
// POSTCONDITION: value of index returned
// int getValue(int location);
//
// PRECONDITION: NONE
// POSTCONDITION: temp print function
// void print();

#ifndef RINGMATRIX_RINGMATRIX_H
#define RINGMATRIX_RINGMATRIX_H

//#include "Arduino.h"

class ringMatrix
{
public:
    ringMatrix(int elements);
    int getPosition();
    void moveTo(int value);
    int getSize();
    int getValue(int location);
    void print();

private:
    int position;
    int previous;
    int size;
    int matrix [16];
    void increase();
    void decrease();
    void moveLeft();
    void moveRight();
    int lookLeft();
    int lookRight();

};


#endif //RINGMATRIX_RINGMATRIX_H
