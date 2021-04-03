/* SYDE121
  a4_q1.cpp
  Assignment 4, Question 1
  10/30/20
  Curtis Franz & Tiffany Ngai
 
  The purpose of this program is to run a Tic Toc Toe game for the users displayed in the console
 
  Verification/testing:
  Test case 1:
  Step 1  Input: 1,5,2,6,3,7,4,8
            Purpose: see if the program can indicate a row with four Xs and output the specified statement
            Expected output: X is the winner! Congratulations!
            Output is consistent to the expected output
  Step 2  Input: y
            Purpose: check if the program will continue running and loop again for the next round
            Expected result: the program goes to round #2
            Result is consistent to the expected result
  Step 3  Input: 1,2,5,6,9,10,13
            Purpose: check if the program can indicate a column with four Os and output the specified statement
            Expected output: O is the winner! Congratulations!
            Output is consistent to the expected result
  Step 4  Input: n
            Purpose: see if the program will end the game
            Expected result/output: output the game status
                    Game Stats:
                    Player X wins: 1
                    Player O Wins: 1
                    Ties: 0
            Output is consistent to the expected result
  Test case 2:
  Step 1  Input: 6,2,11,3,1,4,16
            Purpose: see if the program can indicate a diagonal combination with four Xs and output the specified statement
            Expected output: X is the winner! Congratulations!
            Output is consistent to the expected result
  Step 2  Input: 1
            Purpose: check if the program will ask for another input if the input is invalid
            Expected output: Would you like to keep playing? (y/n)
            Output is consistent to the expected result
  Test case 3:
  Step 1  Input: 0
            Purpose: check if the program will ask for another input if the input is not in range
            Expected output: Player X, please pick a cell:
            Output is consistent to the expected result
  Test case 4:
  Step 1  Input: 1,2,3,4,5,6,7,8,10,9,12,11,13,14,15,16
            Purpose: see if the program can indicate a tie game and output the specified statement
            Expected output: It's a tie! No winner this time.
            Output is consistent to the expected result
 
 Limitations to this simulation:
 1. code have to be rewritten if the table have different number of elements (e.g. a 5x5 table)
 2. players cannot undo their move if they accidentally entered a wrong integer
 3. players have to enter the element number instead of tapping directly on the desired location
 
 */

#include <iostream>
#include <cstring>
using namespace std;

//declare and initialize array size to avoid magic number
const int BOARD_SIZE = 4; // 4 x 4 board size

void display_chart (string table[][BOARD_SIZE]);
//PURPOSE: Display the tic tac toe chart to the users
//        INPUT: table - array of string values
//        RETURN: Outputs the contents of the table to the console

void update_chart (string table[][BOARD_SIZE], char& turn);
//PURPOSE: Update an element in the vector with an X or O depending on the player
//        INPUT: cell_num - An integer value 1 - 16 representing a table element
//        RETURN: Output user prompts to the console

void check_combination (string table[][BOARD_SIZE], int& x_win, int& o_win, int& tie, int turn_count, bool& game_over);
//PURPOSE: Check if there is a winning combination
//        INPUT: table - array of string values to be evaluated
//        RETURN: if_win - x_win - number of time X player wins, o_win - number of time O player wins

void tic_tac_toe_simulation ();
// PURPOSE: Run the steps of the specified program

void display_chart (string table[][BOARD_SIZE]) {
    // output the contents of the table
    cout << table[0][0] << "\t\t" << table[0][1] << "\t\t" << table[0][2] << "\t\t" << table[0][3] << endl;
    cout << table[1][0] << "\t\t" << table[1][1] << "\t\t" << table[1][2] << "\t\t" << table[1][3] << endl;
    cout << table[2][0] << "\t\t" << table[2][1] << "\t\t" << table[2][2] << "\t\t" << table[2][3] << endl;
    cout << table[3][0] << "\t\t" << table[3][1] << "\t\t" << table[3][2] << "\t\t" << table[3][3] << endl;
}

void update_chart (string table[][BOARD_SIZE], char& turn) {
    // declare and initialize variable
    int cell_num = 0;
    
    // keep asking for user to input an integer 1 - 16 until it is provided
    while (cell_num < 1 || cell_num > 16) {
        if(turn == 'X') {
            cout << "Player X, please pick a cell: ";
        }
        else
            cout << "Player O, please pick a cell: ";
        cin >> cell_num;
    }
    // compute the position of the cell selected by the user
    int row = cell_num / BOARD_SIZE;
    int col = (cell_num % BOARD_SIZE) - 1;
    
    // update the cell selected to be X or O depending on the player
    // do not update the cell if it has already been changed
    if (turn == 'X' && table[row][col] != "X" && table[row][col] != "O") {
        table[row][col] = "X";
        turn = 'O';
    }
    else if (turn == 'O' && table[row][col] != "X" && table[row][col] != "O") {
        table[row][col] = "O";
        turn = 'X';
    }
    
    else {
        //Invalid input (already contains an X or O)
        cout << "Please try again!" << endl;
        update_chart(table, turn);
    }
}
    
void check_combination(string table[][BOARD_SIZE], int& x_win, int& o_win, int& tie, int turn_count, bool& game_over) {
    //declare and initialize variables
    bool if_x_win = false;
    bool if_o_win = false;
    
    //the turn_count is set to be greater than or equal six because the turn count starts by zero
    if (turn_count >= 6) {
        //check if there is any horizontal combination of four Xs
        for (int i = 0; i < BOARD_SIZE && !if_x_win; i++) {
            bool continue_checking = true;
            for (int j = 0; j < 3; j++) {
                string temp = table[i][j];
                if (temp == table[i][j+1] && temp == "X" && continue_checking) {
                    continue_checking = true;
                }
                else {
                    continue_checking = false;
                }
            }
            if_x_win = continue_checking;
        }
        //check if there is any vertical combination of four Xs
        for (int j = 0; j < BOARD_SIZE && !if_x_win; j++) {
            bool continue_checking = true;
            for (int i = 0; i < 3; i++) {
                string temp = table[i][j];
                if (temp == table[i+1][j] && temp == "X" && continue_checking) {
                    continue_checking = true;
                }
                else {
                    continue_checking = false;
                }
            }
            if_x_win = continue_checking;
        }
        //check if there is any diagonal combination of four Xs
        if (!if_x_win) {
            if_x_win = table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[2][2] == table[3][3] && table[3][3] == "X";
            if_x_win = if_x_win || (table[0][3] == table[1][2] && table[1][2] == table[2][1] && table[2][1] == table[3][0] && table[3][0] == "X");
        }
        
        
        //check if there is any horizontal combination of four Os
        for (int i = 0; i < BOARD_SIZE && !if_o_win; i++) {
            bool continue_checking = true;
            for (int j = 0; j < 3; j++) {
                string temp = table[i][j];
                if (temp == table[i][j+1] && temp == "O" && continue_checking) {
                    continue_checking = true;
                }
                else {
                    continue_checking = false;
                }
            }
            if_o_win = continue_checking;
        }
        //check if there is any vertical combination of four Os
        for (int j = 0; j < BOARD_SIZE && !if_o_win; j++) {
            bool continue_checking = true;
            for (int i = 0; i < 3; i++) {
                string temp = table[i][j];
                if (temp == table[i+1][j] && temp == "O" && continue_checking) {
                    continue_checking = true;
                }
                else {
                    continue_checking = false;
                }
            }
            if_o_win = continue_checking;
        }
        //check if there is any diagonal combination of four Os
        if (!if_o_win) {
            if_o_win = table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[2][2] == table[3][3] && table[3][3] == "O";
            if_o_win = if_o_win || (table[0][3] == table[1][2] && table[1][2] == table[2][1] && table[2][1] == table[3][0] && table[3][0] == "O");
        }
    }
    //output statement if X or O player wins
    if (if_x_win) {
        cout << "X is the winner! Congratulations!" << endl;
        x_win ++;
        game_over = true;
    }
    if (if_o_win) {
        cout << "O is the winner! Congratulations!" << endl;
        o_win ++;
        game_over = true;
    }
    //output statement if ties
    if (!if_x_win && !if_o_win && turn_count == 16) {
        cout << "It's a tie! No winner this time. " << endl;
        game_over = true;
        tie ++;
    }
}

void tic_tac_toe_simulation() {
    // [SETUP] declare and initialize variables
    // initialize the chart to be a 4 x 4 array with values 1 - 16
    bool keep_playing = true;
    bool game_over = false;
    // variables representing the game statistics
    int turn_count = 0;
    int x_win = 0;
    int o_win = 0;
    int tie = 0;
    int round_num = 0;
    
    char turn = 'X'; // char to keep track of whose turn it is
    char answer; // user response to keep playing
    // [PROCESSING] - start the game
    while (keep_playing == true) {
        // initilize the game board to the default string representations
        string table[BOARD_SIZE][BOARD_SIZE] = {
                            {"1", "2", "3", "4"},
                            {"5", "6", "7", "8"},
                            {"9", "10", "11", "12"},
                            {"13", "14", "15", "16"}
                            };
        // increase the round number each game played
        round_num++;
        // reset game variables to default values at the start of each game
        turn_count = 0;
        game_over = false;
        answer = 0;
        // determine which player gets the first turn
        if (round_num % 2 == 1)
            turn = 'X';
        else
            turn = 'O';
        // [OUTPUT] display a header with the game board, when the program starts
        cout << "Tic Tac Toe - Round # " << round_num << "\n" << endl;
        display_chart(table);
        // continue to give players turns until the game is over
        while (game_over == false) {
            // update the chart to represent the players' inputs
            update_chart(table, turn);
            // output the updated table to the console
            display_chart(table);
            turn_count++; // increment the turn number after each turn is completed
            // check if a player has won, or if it was a tie
            check_combination(table, x_win, o_win, tie, turn_count, game_over);
        }
        // ask the user if they would like to play another round
        while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
            cout << "Would you like to keep playing? (y/n)  ";
            cin >> answer;
        }
        if (answer == 'N' || answer == 'n')
            keep_playing = false;
    }
    // Display the number of ties and wins that each player has
    cout << "\nGame Stats:" << endl;
    cout << "Player X wins: " << x_win << endl;
    cout << "Player O Wins: " << o_win << endl;
    cout << "Ties: " << tie << endl;
}

int main() {
    tic_tac_toe_simulation(); // invoke the execute function
    return 0;
}
