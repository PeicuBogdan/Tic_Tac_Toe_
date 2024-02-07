#include <iostream>
#include <cstdlib>
#include <ctime>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void printBoard();
void resetBoard();
int checkSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
    char winner = ' ';
   
    resetBoard();
    do {
        printBoard();

        playerMove();

        winner = checkWinner();

        if (checkSpaces() == 0 || winner != ' ') {
            break;
        }
                
        computerMove();

        winner = checkWinner();

        if (checkSpaces() == 0 || checkWinner() != ' ') {
            break;
        }

    } while (winner == ' ' && checkSpaces() != 0);

    printBoard();

    printWinner(winner);

    return 0;
}

void printBoard()
{
    std::cout << "\n " << board[0][0] << " | " << board[0][1] << " | " << board[0][2];
    std::cout << "\n---|---|---";
    std::cout << "\n " << board[1][0] << " | " << board[1][1] << " | " << board[1][2];
    std::cout << "\n---|---|---";
    std::cout << "\n " << board[2][0] << " | " << board[2][1] << " | " << board[2][2];
}

void resetBoard()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

int checkSpaces()
{
    int spaces = 9;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                spaces--;
            }
        }
    }

    return spaces;
}

void playerMove()
{
    int x, y;
    do {
        std::cout << "\nChoose where you want to place 'row' (0-2)";
        std::cin >> x;
        std::cout << "\nChoose where you want to place 'column' (0-2)";
        std::cin >> y;
        if (board[x][y] != ' ') {
            std::cout << "\nSpace already occupied";
        } else {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}

void computerMove()
{
    int x, y;
    if (checkSpaces() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;

            if (board[x][y] == ' ') {
                board[x][y] = COMPUTER;
                break;
            }
        } while (board[x][y] != ' ');
    }
}

char checkWinner()
{
    for (int i = 0; i <= 2; i++) {
        // Rows
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        // Columns
        } else if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        // Diagonals
        } else if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0];
        } else {
            return ' ';
        }
    }
}

void printWinner(char winner)
{
    if (winner != ' ' && winner == 'O') {
        std::cout << "\nThe winner is O. You lose :(((";
        std::cout << "\nThank you for playing!";
    } else if (winner != ' ' && winner == 'X') {
        std::cout << "\nThe winner is X. You win :))))";
        std::cout << "\nThank you for playing!";
    } else {
        std::cout << "\nDRAW!"; 
    }
}
