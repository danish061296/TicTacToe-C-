//
//  main.cpp
//  TicTacToe
//
//  Created by Danish Siddiqui on 9/18/19.
//  Copyright © 2019 Danish Siddiqui. All rights reserved.
//

#include <iostream>
using namespace std;
bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {
    //
    //    PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);
    
    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
        
        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);
        
        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }
    
    return 0;
}

//this method will iterate through the board
//it will declare a winner based on the followinf conditions
bool isWon(char input, char board[][3]){
    
    //if any one of the rows has the same character
    if (board[0][0] == input &&
        board[0][1] == input &&
        board[0][2] == input)
        return true;
    else if (board[1][0] == input &&
             board[1][1] == input &&
             board[1][2] == input)
        return true;
    else if (board[2][0] == input &&
             board[2][1] == input &&
             board[2][2] == input)
        return true;
    // if any one of the columns has the same character
    else if (board[0][0] == input &&
             board[1][0] == input &&
             board[2][0] == input)
        return true;
    else if (board[0][1] == input &&
             board[1][1] == input &&
             board[2][1] == input)
        return true;
    else if (board[0][2] == input &&
             board[1][2] == input &&
             board[2][2] == input)
        return true;
    
    //if the charaters are same diagonally
    if (board[0][2] == input &&
        board[1][1] == input &&
        board[2][0] == input)
        return true;
    else if (board[0][0] == input &&
             board[1][1] == input &&
             board[2][2] == input)
        return true;
    else
        return false;
}

bool isDraw(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            //If an empty field (no X and no O exists on the field)
            //not a draw yet
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
    }
    //else it's a draw
    return true;
    
}

//this method will display the tic tac toe board on the screen
//it will take input from both players and will insert a character
//in an assigned position in the 2d array
void displayBoard(char board[][3]){
    
    cout << "_______________\n";
    cout << "| " << board[0][0] << "| " << board[0][1] << "| " << board[0][2] << "| " << endl;
    cout << "_______________\n";
    cout << "| " << board[1][0] << "| " << board[1][1] << "| " << board[1][2] << "| " << endl;
    cout << "_______________\n";
    cout << "| " << board[2][0] << "| " << board[2][1] << "| " << board[2][2] << "| " << endl;
    cout << "_______________\n";
    cout << endl;
    
}

//this method will allow both players to make their move
//it will take turns to get the input from both players
void makeAMove(char board[][3], char input){
    
    while(true){
        //Asking players to input number from 0-2
        cout << "Enter a row(0,1,2) for player " << input << ":";
        int t_1;
        cin >> t_1;
        cout << "Enter a column(0,1,2) for player " << input << ":";
        int t_2;
        cin >> t_2;
        string prompt = "Invalid Numbers";
        string suggest = "Please put numbers 0, 1, or 2 in each turn";
        //shows invalid move if a player inputs an invalid number
        if ( t_1 < 0 || t_1 > 2 || t_2 < 0 || t_2 > 2){
            
            cin.clear(); //clear the invalid input
            cin.ignore(1000,'\n');
            //print the message
            cout << prompt << endl;
            cout << suggest << endl;
        }
        else {
            //if a space in the board has not been filled with a character
            if (board[t_1][t_2] != 'X' && board[t_1][t_2] != 'O') {
                
                //fill that spack with a character
                board[t_1][t_2] = input;
                break;
            }
            else {
                cout << "This cell is already occupied. Try a different cell" << endl;
            }
            
        }
    }
}

