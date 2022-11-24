#include <iostream>
#include <cstring>
using namespace std;
/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
    FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
    INSTRUCTIONS TO NAVIGATE MENU:
    PRESS 1 1 TO START
    Press 1 2 TO OPTIONS AND COMMANDS
    Press 1 3 TO RETURN TO THE MENU
    Press 1 4 4 TO EXIT
    1 - decision true
    choices:1,2,3,4
**********************************************/

char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };

class TicTacToe
{
private:
    string player_first;
    string player_second;

public:
    void display_start() {
        cout << "\n\n\t1. Start" << endl;
    }
    void display_option() {
        cout << "\n\n\t2. Option(command:1 2)" << endl;
    }
    void display_back_in_main_menu() {
        cout << "\n\n\t3. Back to the menu" << endl;
    }
    void display_exit() {
        cout << "\n\n\t4. Exit" << endl;
    }
    void title_game() {
        cout << "\n\n\t Tic Tac Toe" << endl << "\t_____________" << endl;
        cout << endl;
    }
    void detail_option() {
        system("cls");
        cout << "FUNCTION TO RETURN GAME STATUS" << endl;
        cout << " 1 FOR GAME IS OVER WITH RESULT" << endl;
        cout << " - 1 FOR GAME IS IN PROGRESS" << endl;
        cout << " O GAME IS OVER AND NO RESULT " << endl;
        cout << "FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK" << endl;
        cout << endl;
        cout << "INSTRUCTIONS TO NAVIGATE MENU" << endl;
        cout << "________________________" << endl;
        cout << "Press 1 1 to start" << endl;
        cout << "Press 1 2 to options" << endl;
        cout << "Press 1 3 to return to the menu" << endl;
        cout << "Press 1 4 4 to exit" << endl;
    }
    void display_presentation_player1() {
        cout << "The first player is : ";
        cin >> player_first;
        cout << endl;
    }
    void display_presentation_player2() {
        cout << "The second player is : ";
        cin >> player_second;
        cout << endl;
    }

    void main_menu() {
        int choice;
        cout << "\n\n\tYour choice is : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            lets_begin();
            game_main();
            break;
        case 2: detail_option();
            break;
        case 3: display_menu();
            break;
        case 4:
            break;
        }
    }

    void display_menu() {
        system("cls");
        title_game();
        display_start();
        display_option();
        display_back_in_main_menu();
        display_exit();

    }
    int checkwin()
    {
        if (square[1] == square[2] && square[2] == square[3])

            return true;
        else if (square[4] == square[5] && square[5] == square[6])

            return true;
        else if (square[7] == square[8] && square[8] == square[9])

            return true;
        else if (square[1] == square[4] && square[4] == square[7])

            return true;
        else if (square[2] == square[5] && square[5] == square[8])

            return true;
        else if (square[3] == square[6] && square[6] == square[9])

            return true;
        else if (square[1] == square[5] && square[5] == square[9])

            return true;
        else if (square[3] == square[5] && square[5] == square[7])

            return true;
        else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
            && square[4] != '4' && square[5] != '5' && square[6] != '6'
            && square[7] != '7' && square[8] != '8' && square[9] != '9')

            return false;
        else
            return -true;
    }

    void begin_game() {

        board();
        int play = checkwin();
        cout << play;
    }

    void lets_begin() {
        system("cls");
        display_presentation_player1();
        display_presentation_player2();
    }


    void game_main() {
        begin_game();
        int player = 1, i, choice;
        char mark;
        do
        {
            board();
            player = (player % 2) ? 1 : 2;

            cout << "Player " << player << ", enter a number:  ";
            cin >> choice;

            mark = (player == 1) ? 'X' : 'O';

            if (choice == 1 && square[1] == '1')

                square[1] = mark;
            else if (choice == 2 && square[2] == '2')

                square[2] = mark;
            else if (choice == 3 && square[3] == '3')

                square[3] = mark;
            else if (choice == 4 && square[4] == '4')

                square[4] = mark;
            else if (choice == 5 && square[5] == '5')

                square[5] = mark;
            else if (choice == 6 && square[6] == '6')

                square[6] = mark;
            else if (choice == 7 && square[7] == '7')

                square[7] = mark;
            else if (choice == 8 && square[8] == '8')

                square[8] = mark;
            else if (choice == 9 && square[9] == '9')

                square[9] = mark;
            else
            {
                cout << "Invalid move ";

                player--;
                cin.ignore();
                cin.get();
            }
            i = checkwin();

            player++;
        } while (i == -1);
        board();
        if (i == 1)
        {
            cout << "==>\aPlayer " << --player << " win ";
        }
        else
            cout << "==>\aGame draw";
        cin.ignore();
        cin.get();
    }
    void board()
    {
        system("cls");
        title_game();
        cout << "Player 1 " << this->player_first << " (X)" << " - Player 2 " << this->player_second << " (O)" << endl << endl;
        cout << endl;
        cout << "     |     |     " << endl;
        cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;

        cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;

        cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

        cout << "     |     |     " << endl << endl;

    }
};
int main() {
    TicTacToe game;
    game.display_menu();
    int decision;
    cout << "\n\n\tYour decision is : ";
    cin >> decision;
    while (decision == true) {
        game.main_menu();
        cout << "\nYour decision is : ";
        cin >> decision;
        continue;
    }
    return 0;
}



