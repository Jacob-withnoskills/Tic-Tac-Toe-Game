#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<Windows.h>
#include<stdbool.h>
#include <time.h>
#define n 3
#pragma warning(disable : 4996)

//int checkwin();
//char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char board[n][n] ={{'1','2','3'},{'4','5','6'},{'7','8','9'}}; 
//int moves[n * n];
bool rowCrossed(char board[n][n]);
bool columnCrossed(char board[n][n]);
bool diagonalCrossed(char board[n][n]);

struct coordinate
{
    int x;
    int y;
}head;


void gotoxy(int x, int y)
{
    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void load()
{
    int r, q;
    gotoxy(36, 14);
    printf("loading...");
    gotoxy(30, 15);
    for (r = 1; r <= 20; r++)
    {
        for (q = 0; q <= 100000000; q++);
        printf("%c", 177);
    }
    getch();
}
/*void initialise(char board[][n])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            board[i][j] = ' ';
    }

    for (int i = 0; i < n * n; i++)
        moves[i] = i;

    return;
}*/
void displayboard()

{
    system("cls");
    gotoxy(36,14);
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);

    printf("     |     |     \n\n");
}

void showinstructions()
{
    printf("\t\t\t  Tic-Tac-Toe\n\n");
    printf("Choose a cell numbered from 1 to 9 as below"
        " to play\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("\t\t\t  1 | 2  | 3  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  4 | 5  | 6  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  7 | 8  | 9  \n\n");

    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");

    return;
}
bool gameOver(char board[][n])
{
    return(rowCrossed(board) || columnCrossed(board)
        || diagonalCrossed(board));
}

bool rowCrossed(char board[][n])
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return (true);
    }
    return(false);
}
bool columnCrossed(char board[][n])
{
    for (int i = 0; i < n; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return (true);
    }
    return(false);
}
bool diagonalCrossed(char board[][n])
{
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return (true);
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
        return (true);

    return(false);
}
int playgame(char board[][n])
{
    int player = 1, i, choice;

    char mark;
    do
    {
        displayboard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf_s("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && board[0][0] == '0')
            board[0][0] = mark;

        else if (choice == 2 && board[0][1] == '1')
            board[0][1] = mark;

        else if (choice == 3 && board[0][2] == '2')
            board[0][2] = mark;

        else if (choice == 4 && board[1][0] == '3')
            board[1][0] = mark;

        else if (choice == 5 && board[1][1] == '4')
            board[1][1] = mark;

        else if (choice == 6 && board[1][2] == '5')
            board[1][2]  = mark;

        else if (choice == 7 && board[2][0] == '6')
            board[2][0] = mark;

        else if (choice == 8 && board[2][1] == '7')
            board[2][1] = mark;

        else if (choice == 9 && board[2][2] == '8')
            board[2][2] = mark;

        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = gameOver(board);

        player++;
    } while (i == false);

    displayboard();

    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    getch();

    return 0;
}

/*int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  -1;
}*/
int main()
{
    load();
    showinstructions();
    delay(2);
    getch();
    playgame(board);
    return 0;

}
