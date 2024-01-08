#include "minMoves.h"

char table[17][18] = { {'8', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'}, //18x17
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'7', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'6', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'5', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'4', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'3', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'2', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'1', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {' ', '|', '1', '|', '2', '|', '3', '|', '4', '|', '5', '|', '6', '|', '7', '|', '8', '|'}   };


Field* FindMinimum(int startPosition[2], int finalPosition[2]) {
    int xOsa[] = {-2,-1,1,2,-2,-1,1,2};
    int yOsa[] = {-1,-2,-2,-1,1,2,2,1};

    vector<Field*> possiblePositions; // all the fields where the knight can go
    possiblePositions.push_back(new Field(startPosition[0], startPosition[1],0,NULL));

    bool visitedFields[9][9]; // fields where the knight has already been

    for(int i=1;i<9;i++) { // we initialize all fields as unvisited
        for(int j=1;j<9;j++) {
                visitedFields[i][j] = false;
        }
    }

    visitedFields[startPosition[0]][startPosition[1]] = true; // we mark the starting Field as visited

    Field* current;
    int x,y;
    while(!possiblePositions.empty()) {
           current = possiblePositions.front();
           possiblePositions.erase(possiblePositions.begin());


           if(current->xCoordinate == finalPosition[0] && current->yCoordinate == finalPosition[1]) { //we check if we have reached the target Field
				return current;
				possiblePositions.clear();
			}

            for(int i=0;i<8;i++) {
                x = current->xCoordinate + xOsa[i];
                y = current->yCoordinate + yOsa[i];

                if(isInTable(x,y) && !visitedFields[x][y] ) {
                    visitedFields[x][y] = true;
                    possiblePositions.push_back(new Field(x,y,current->distance+1,current));
                }
            }

    }

    return NULL;
}

void PrintTable() {
    for(int i=0;i<17;i++) {
        for(int j=0;j<18;j++) {
            cout << table[i][j];
        }
        cout << "\n";
    }
}

bool isInTable(int x, int y) {
    if(x<=8 && x>0 && y<=8 && y>0) return true;

    return false;
}

void markField(int x, int y, char mark) {

    switch(y) {
        case 1:
            y = 14;
            break;
        case 2:
            y = 12;
            break;
        case 3:
            y = 10;
            break;
        case 4:
            y = 8;
            break;
        case 5:
            y = 6;
            break;
        case 6:
            y = 4;
            break;
        case 7:
            y = 2;
            break;
        case 8:
            y = 0;
            break;
    }

    table[y][x*2] = mark;
}
