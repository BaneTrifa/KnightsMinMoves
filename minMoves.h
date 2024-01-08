#ifndef MINMOVES_H
#define MINMOVES_H

#include <iostream>
#include <vector>

using namespace std;

class Field {
public:
    int xCoordinate, yCoordinate, distance; // distance is the distance from the starting field
    Field* previous;

    Field(int x, int y, int dis, Field* prev) {
        xCoordinate = x;
        yCoordinate = y;
        distance = dis;
        previous = prev;
    }
};

extern char table[17][18];

void PrintTable();
bool isInTable(int x, int y); // method that checks if the Field exits the board frame, returns true if it exists
Field* FindMinimum(int startPosition[2], int finalPosition[2]); // method that returns the address of the end field which contains the distance from the starting field and all previous moves
void markField(int x, int y, char mark); // serves to put a certain mark on a certain Field

#endif