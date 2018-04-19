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

//#include <iostream>
#include "ringMatrix.h"
//#include "Arduino.h"

//using namespace std;

ringMatrix::ringMatrix(int elements)
{
    size = elements;
    matrix = new int [size];
    position = 0;

    for(int i = 0; i < size; i++)
        matrix[i] = 10000;
}

void ringMatrix::increase()
{
    if(matrix[position] > 0 && matrix[position] < 9999)
    {
        moveLeft();
        matrix[position] = matrix[lookRight()] + 1;
    }
    else if(matrix[position] == 10000)
        matrix[position] = 1;
    else if(matrix[position] == -1)
    {
        matrix[position] = 10000;
        position = 0;
    }
    else if(matrix[position] < -1)
    {
        moveLeft();
        matrix[position] = matrix[lookRight()] + 1;
        if(matrix[lookRight()] < (size) * -1)
            matrix[lookRight()] = matrix[lookRight()] + size;
        else
            matrix[lookRight()] = 10000;
    }
}

void ringMatrix::decrease()
{
    if(matrix[position] < 0)
    {
        moveRight();
        matrix[position] = matrix[lookLeft()]  - 1;
    }
    else if(matrix[position] == 10000)
        matrix[position] = -1;
    else if(matrix[position] == 1)
    {
        matrix[position] = 10000;
        position = 0;
    }
    else if(matrix[position] > 1)
    {
        moveRight();
        matrix[position] = matrix[lookLeft()] - 1;
        if(matrix[lookLeft()] > size)
            matrix[lookLeft()] = matrix[lookLeft()] - size;
        else
            matrix[lookLeft()] = 10000;
    }
}

inline int ringMatrix::getSize()
{return size;}

inline int ringMatrix::getPosition()
{return position;}

void ringMatrix::moveTo(int value)
{
    while(value != matrix[position])
    {
        if(value > matrix[position])
            increase();
        else
            decrease();
    }
}

void ringMatrix::moveLeft()
{
    if(position == 0)
        position = size - 1;
    else position--;
}

void ringMatrix::moveRight()
{
    if(position == size - 1)
        position = 0;
    else
        position++;
}


int ringMatrix::lookLeft()
{
    if(position == 0)
        return size - 1;
    else
        return position - 1;
}

int ringMatrix::lookRight()
{
    if(position == size - 1)
        return 0;
    else
        return position + 1;
}

int ringMatrix::getValue(int location)
{return matrix[location];}


void ringMatrix::print()
{
    for(int i = 0; i < size; i++)
        cout << "[" << i << "]: " <<  matrix[i] << endl;
}
/*
int main()
{
    char input;
    ringMatrix ringMatrix1(16);

    while(true) {
        cout << "select input\n";
        cin >> input;

        switch (input) {
            case 'i': {
                ringMatrix1.increase();
                ringMatrix1.print();
                break;
            }
            case 'd': {
                ringMatrix1.decrease();
                ringMatrix1.print();
                break;
            }
            default: {
                cout << "nothing happened\n";
                ringMatrix1.print();
                break;
            }

        }
    }*/
}
