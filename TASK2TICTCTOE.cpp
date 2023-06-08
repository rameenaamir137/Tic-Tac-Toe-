#include <iostream>
using namespace std;
// Making a class named TICTACTOE
class TicTacToe
{                    // DECLARING PRIVATE DATA MEMBERS OF CLASS
    int array[3][3]; // CREATING A 2-D ARRAY
    string player_1;
    string player_2;
    // CHANGING THE ACCESSER TO PUBLIC
public:
    // DECLARING PUBLIC MEMBER FUNCTIONS OF CLASS
    TicTacToe(); // CONSTRUCTOR
    void Move(void);
    // void results(void);
    void printboard(void);
    void initialboard(void);
    void Draw(void);
};
// DEFINING MEMBER FUNCTIONS

TicTacToe::TicTacToe()
{ // DISPLAYING INTRO MESSAGE
    cout << "\n WELCOME TO TIC-TAC-TOE GAME:"
         << "\n"
         << "****************************************** \n"
         << endl;
    // INITILZING THE ARRAY WITH VALUES AT 0
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            array[i][j] = 0;
    }
    // TAKING INPUTS FOR THE NAMES OF USERS
    cout << "\nENTER THE NAME OF PLAYER 1=" << endl;
    getline(cin, player_1);
    cout << "\nENTER THE NAME OF PLAYER 2=" << endl;
    getline(cin, player_2);
    // DISPLYING USERS NAME ON SCREEN
    cout << "\t \t \t \t \t \t \t \t -------->PLAYER 1= " << player_1 << "[1]" << endl;
    cout << "\t \t \t \t \t \t \t \t -------->PLAYER 2= " << player_2 << "[2]" << endl;
    // DISPLAYING THE TIC TAC BOARD
    initialboard();
}
void TicTacToe::Move(void)
{ // DECLARING VARIABLES
    int a1;
    int b1;
    int a2;
    int b2;
    bool player1;
    player1 = false;
    bool player2;
    player2 = false;
    bool check;

    check = false;
    //APPLYIMG WHILE LOOP TO EXECUTE THE LOOP AND CONTINUE THE GAME UNTIL THERE IS A WINNER
    while (check == false)
    {
        player1 = false;
        //APPLYIMG WHILE LOOP TO EXECUTE THE LOOP AND ASK THE USER FOR INPUT UNTIL THERE IS A VALID INPUT
        while (player1 == false)
        {
            cout << "\n"
                 << player_1 << "'s TURN:" << endl;
            cout << "****************************" << endl;
            // TAKING INPUT FROM USER TO MARK PLACE
            cout << "\nWHERE DOES " << player_1 << " WANT TO MOVE=" << endl;
            cin >> a1 >> b1;
            a1 = a1 - 1;
            b1 = b1 - 1;
            // DISPLAYING MESSAGE IF A SPACE IS REPEATED AGAIN
            if (array[a1][b1] == 1 || array[a1][b1] == 2 || a1 > 2 || b1 > 2)
            {

                cout << "YOU CANNOT MOVE HERE SINCE IT IS NOT AN EMPTY SPACE" << endl;
              
            }
                else if (array[a1][b1] == 0)
                {
                    array[a1][b1] = 1;
                    printboard();
                    player1 = true;
                }
            
            // MARKING THE SELECTED SPACE WITH 1 FOR PLAYER 1
            else if (array[a1][b1] == 0)
            {
                array[a1][b1] = 1;
                // DISPLAYING THE MARKED TIC TAC TOE BOARD
                printboard();
                player1 = true;
            }
        }

        // APPLYING LOOP TO CHECK IF WINNER IS PLAYER 1

        for (int m = 0; m < 3; m++)
        {
            for (int n = 0; n < 1; n++)
            {
                if (array[m][n] == 1 && array[m][n + 1] == 1 && array[m][n + 2] == 1)
                {
                    check = true;
                    cout << "winner is " << player_1 << endl;
                }

                if (array[n][m] == 1 && array[n + 1][m] == 1 && array[n + 2][m] == 1)
                {
                    check = true;
                    cout << "winner is " << player_1 << endl;
                }
            }
        }

        if (array[0][0] == 1 && array[1][1] == 1 && array[2][2] == 1)
        {
            check = true;
            cout << "winner is " << player_1 << endl;
        }

        if (array[2][0] == 1 && array[1][1] == 1 && array[0][2] == 1)
        {
            check = true;
            cout << "winner is " << player_1 << endl;
        }
        // APPLYING LOOP TO CHECK IF IT IS A DRAW
        for (int j = 0; j < 1; j++)
        {
            for (int k = 0; k < 1; k++)
            {
                if (array[j][k] != 0 && array[j][k + 1] != 0 && array[j][k + 2] != 0 && array[j + 1][k] != 0 && array[j + 1][k + 1] != 0 && array[j + 1][k + 2] != 0 && array[j + 2][k] != 0 && array[j + 2][k + 1] != 0 && array[j + 2][k + 2] != 0)
                {
                    check = true;
                    cout << "IT IS DRAW";
                }
            }
        }
        // APPLYING CHECK TO BREAK THE LOOP IF THERE IS A WINNER

        if (check == true)
        {
            break;
        }

        player2 = false;
             //APPLYIMG WHILE LOOP TO EXECUTE THE LOOP AND ASK THE USER FOR INPUT UNTIL THERE IS A VALID INPUT
        while (player2 == false)
        {
            cout << player_2 << "'s TURN:" << endl;
            cout << "****************************" << endl;
            // TAKING INPUT FROM USER TO MARK PLACE
            cout << "\nWHERE DOES " << player_2 << " WANT TO MOVE=" << endl;
            cin >> a2 >> b2;
            a2 = a2 - 1;
            b2 = b2 - 1;

            if (array[a2][b2] == 1 || array[a2][b2] == 2 || a2 > 2 || b2 > 2)
            {
                // DISPLAYING MESSAGE IF A SPACE IS REPEATED AGAIN
                cout << "YOU CANNOT MOVE HERE SINCE IT IS NOT AN EMPTY SPACE" << endl;
              
                if (array[a2][b2] == 0)
                {
                    array[a2][b2] = 2;
                    printboard();
                    player2 = true;
                }
            }

            else if (array[a2][b2] == 0)
            { // MARKING THE SELECTED SPACE WITH 2 FOR PLAYER 2
                array[a2][b2] = 2;
                // DISPLAYING THE MARKED TIC TAC TOE BOARD
                printboard();
                player2 = true;
            }
        }

        // APPLYING LOOP TO CHECK IF WINNER IS PLAYER 2
        for (int m = 0; m < 3; m++)
        {
            for (int n = 0; n < 1; n++)
            {
                if (array[m][n] == 2 && array[m][n + 1] == 2 && array[m][n + 2] == 2)
                {
                    check = true;
                    cout << "winner is " << player_2 << endl;
                }

                if (array[n][m] == 2 && array[n + 1][m] == 2 && array[n + 2][m] == 2)
                {
                    check = true;
                    cout << "winner is " << player_2 << endl;
                }
            }
        }
        if (array[0][0] == 2 && array[1][1] == 2 && array[2][2] == 2)
        {
            check = true;
            cout << "winner is " << player_2 << endl;
        }

        if (array[2][0] == 2 && array[1][1] == 2 && array[0][2] == 2)
        {
            check = true;
            cout << "winner is " << player_2 << endl;
        }

        // APPLYING LOOP TO CHECK IF IT IS A DRAW
        for (int j = 0; j < 1; j++)
        {
            for (int k = 0; k < 1; k++)
            {
                if (array[j][k] != 0 && array[j][k + 1] != 0 && array[j][k + 2] != 0 && array[j + 1][k] != 0 && array[j + 1][k + 1] != 0 && array[j + 1][k + 2] != 0 && array[j + 2][k] != 0 && array[j + 2][k + 1] != 0 && array[j + 2][k + 2] != 0)
                {
                    check = true;
                    cout << "IT IS DRAW";
                }
            }
        }
        // APPLYING CHECK TO BREAK THE LOOP IF THERE IS A WINNER
        if (check == true)
        {
            break;
        }
    }
}

// CREATING A FUNCTION TO DISPLAY THE BOARD WITH MARKED SPACES AFTER EACH PLAYERS TURN
void TicTacToe::printboard(void)
{

    cout << "           |          |\t" << endl;
    cout << " " << array[0][0] << "         | " << array[0][1] << "        | " << array[0][2] << endl;
    cout << "___________|__________|________" << endl;
    cout << "           |          |\t" << endl;
    cout << " " << array[1][0] << "         | " << array[1][1] << "        | " << array[1][2] << endl;
    cout << "___________|__________|________" << endl;
    cout << "           |          |\t" << endl;
    cout << " " << array[2][0] << "         | " << array[2][1] << "        | " << array[2][2] << endl;
}
// CREATING A FUNCTION TO DISPLAY THE BOARD WITH UNMARKED SPACES AT ZERO BEFORE THE GAME STARTS
void TicTacToe::initialboard()
{
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t"
         << "           |          |\t" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t"
         << " "
         << "  (1,1)  "
         << " | "
         << "  (1,2) "
         << " | "
         << "  (1,3)" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t"
         << "___________|__________|________" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t"
         << "           |          |\t" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t"
         << " "
         << "  (2,1) "
         << "  | "
         << "  (2,2) "
         << " | "
         << "  (2,3)" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t"
         << "___________|__________|________" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t"
         << "           |          |\t" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t"
         << " "
         << "  (3,1) "
         << "  | "
         << "  (3,2) "
         << " | "
         << "  (3,3)" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\tTHIS TABLE SHOWS LOCATION OF EMPTY SPACES" << endl;
}
int main()
{ // DECLARING OBJECT OF CLASS TICTACTOE
    TicTacToe game1;
    // CALLING MEMBER FUNCTIONS OF TICTACTOE
    game1.Move();
    return 0;
}