#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<Windows.h>
#include<stdbool.h>
#define n 3
#pragma warning(disable : 4996)

char board[][n];
int moves[n * n];

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
void initialise(char board[][n])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            board[i][j] = ' ';
    }

    for (int i = 0; i < n * n; i++)
        moves[i] = i;

    return;
}
void displayboard()

{
    system("cls");
    printf("\n\n");

    printf("\t\t\t  %c | %c  | %c  \n", board[0][0],
        board[0][1], board[0][2]);
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0],
        board[1][1], board[1][2]);
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0],
        board[2][1], board[2][2]);
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

int playgame(char board[n][n])
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

        if (choice == 1 && !gameOver(board))
            board[0][0] = mark;

        else if (choice == 2 && !gameOver(board))
            board[0][1] = mark;

        else if (choice == 3 && !gameOver(board))
            board[0][2] = mark;


        else if (choice == 4 && !gameOver(board))
            board[1][0] = mark;

        else if (choice == 5 && !gameOver(board))
            board[1][1] = mark;

        else if (choice == 6 && !gameOver(board))
            board[1][2] = mark;

        else if (choice == 7 && !gameOver(board))
            board[2][0] = mark;

        else if (choice == 8 && !gameOver(board))
            board[2][1] = mark;

        else if (choice == 9 && !gameOver(board))
            board[2][2] = mark;


        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = gameOver(board);

        player++;
    } while (i == -1);

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

}*/

int main()
{
    load();
    showinstructions();
    return 0;

}