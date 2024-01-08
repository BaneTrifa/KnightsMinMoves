#include "minMoves.h"

int main() {
    int startPosition[2]; // initial coordinates of the knight
    int finalPosition[2]; // coordinates of the field where the knight should come

    PrintTable();

    cout << "\nEnter the x-coordinate of the knight's starting field: "; cin >> startPosition[0];
    cout << "Enter the y-coordinate of the knight's starting field: "; cin >> startPosition[1];

    if( !isInTable(startPosition[0],startPosition[1]) ) { // We check whether the initial coordinates entered are valid
        cout << "You have entered invalid coordinates!!!";
        exit(0);
    }

    cout << "\nEnter the x-coordinate of the knight's final field: "; cin >> finalPosition[0];
    cout << "Enter the y-coordinate of the knight's final field:"; cin >> finalPosition[1];

    if( !isInTable(finalPosition[0],finalPosition[1]) ) { // We check whether the final coordinates entered are valid
        cout << "You have entered invalid coordinates!!!";
        exit(0);
    }


    Field* minimum = FindMinimum(startPosition,finalPosition); // We search for the shortest path and return the address of the last (requested) field

    system("cls");

    cout << "The minimum number of moves is: " << minimum->distance << endl;

    vector<Field*> moves;
    while(minimum->previous != NULL) { // Since each Field contains the address of the previous field,
        moves.push_back(minimum);      // we place the fields from the last (end) into the vector
        minimum = minimum->previous;   // towards the first (initial) and we get the knight's movement path in the moves vector
    }

    // We print the entire path of the knight (from the starting field to the final one)
    cout << "\nPath: " << endl;
    cout << "[" << startPosition[0] << "," << startPosition[1] << "]" << endl; // Print the coordinates of the first (initial) field

    while(!moves.empty()) { // we print the coordinates of all fields that are in vector<Field*>moves starting from the last one
        cout << "[" << moves.back()->xCoordinate << "," << moves.back()->yCoordinate << "]" << endl; 
        markField(moves.back()->xCoordinate,moves.back()->yCoordinate,'X'); // we mark each Field over which the knight crossed with an 'X'
        moves.pop_back();
    }

    moves.clear();

    markField(startPosition[0],startPosition[1],'S'); 
    markField(finalPosition[0],finalPosition[1],'F');

    cout << "\n";
    PrintTable();
    cout << "\nS - starting position of the knight" << endl;
    cout << "F - final position of the knight" << endl;
    cout << "X - fields over which the knight reached the final position" << endl;

    return 0;
}

