#include <iostream>
#include <windows.h>
using namespace std;

bool play(int[][7], int);

int main()
{
       int board[6][7];
       int coloum;
       bool player1 = false, player2 = false;
       bool game = true;
       bool draw = true;
       HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
       for (int i = 0; i < 6; i++)
       {
              for (int j = 0; j < 7; j++)
                     board[i][j] = 0;
       }
    cout << "hello and welcome to Connect four" << endl;
       //the actual game
       do
       {
              cout << "player 1 ";
              player1 = play(board, 1);
              if (!player1)
              {
                     cout << "player 2 ";
                     player2 = play(board, 2);
              }
              for (int i = 0; i < 6; i++)
              {
                     for (int j = 0; j < 7; j++)
                           if (board[i][j] == 0)
                                  draw = false;
              }
       } while (!(player1 || player2) || draw);
       if (player1)
       {
              SetConsoleTextAttribute(h, 12);
              cout << "player 1 wins";
       }
       else
       {
              SetConsoleTextAttribute(h, 11);
              cout << "playse 2 wins";
       }
       return 0;
}

bool play(int board[][7], int player)
{
       int x;
       bool game = false;
       int i = 5;
       bool done = false;
       HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
       do 
       {
              done = true;
              cout << "please enter a column" << endl;
              cin >> x;
              x = x - 1;

              while (board[i][x] != 0 && done)
              {
                     if (i != 0 && x < 7 && x > - 1)
                           i--;
                     else
                     {
                           cout << "that column is invalid" << endl;
                           done = false;
                           i = 5;
                     }
              }
       } while (!done);
       board[i][x] = player;
       //printing the game board
       for (int i = 0; i < 6; i++)
       {
              for (int j = 0; j < 7; j++)
              {
                     if(board[i][j] == 1)
                           SetConsoleTextAttribute(h, 12);
                     else if(board[i][j] == 2)
                           SetConsoleTextAttribute(h, 11);
                     else
                           SetConsoleTextAttribute(h, 15);
                     cout << board[i][j] << ' ';
              }
              cout << endl;
       }
       SetConsoleTextAttribute(h, 15);
       //test if game is won
       //vertical
       if (board[i][x] == board[i + 1][x] && board[i][x] == board[i + 2][x] && board[i][x] == board[i + 3][x] && i < 3)
              game = true;
       //horezontal
       if (board[i][x] == board[i][x - 1] && board[i][x] == board[i][x - 2] && board[i][x] == board[i][x - 3] && x > 2)
              game = true;
       if (board[i][x] == board[i][x + 1] && board[i][x] == board[i][x - 1] && board[i][x] == board[i][x - 2] && x > 1 && x < 6)
              game = true;
       if (board[i][x] == board[i][x + 2] && board[i][x] == board[i][x + 1] && board[i][x] == board[i][x - 1] && x > 0 && x < 5)
              game = true;
       if (board[i][x] == board[i][x + 3] && board[i][x] == board[i][x + 2] && board[i][x] == board[i][x + 1] && x < 4)
              game = true;
       // diagenal
       //top right
       if (board[i][x] == board[i + 1][x + 1] && board[i][x] == board[i + 2][x + 2] && board[i][x] == board[i + 3][x + 3] && x < 4 && i < 3)
              game = true;
       if (board[i][x] == board[i - 1][x - 1] && board[i][x] == board[i + 1][x + 1] && board[i][x] == board[i + 2][x + 2] && x > 0 && x < 5 
              && i > 0 && i < 4)
              game = true;
       if (board[i][x] == board[i - 2][x - 2] && board[i][x] == board[i - 1][x - 1] && board[i][x] == board[i + 1][x + 1] && x > 1 && x < 6
              && i > 1 && i < 5)
              game = true;
       if (board[i][x] == board[i - 3][x - 3] && board[i][x] == board[i - 2][x - 2] && board[i][x] == board[i - 1][x - 1] && x > 2
              && i > 2)
              game = true;
       if (board[i][x] == board[i - 1][x + 1] && board[i][x] == board[i - 2][x + 2] && board[i][x] == board[i - 3][x + 3] && x < 4
              && i > 2)
              game = true;
       if (board[i][x] == board[i + 1][x - 1] && board[i][x] == board[i - 1][x + 1] && board[i][x] == board[i -2][x + 2] && x > 0 && x < 5
              && i > 1 && i < 5)
              game = true;
       if (board[i][x] == board[i + 2][x - 2] && board[i][x] == board[i + 1][x -1] && board[i][x] == board[i - 1][x + 1] && x > 1 && x < 6
              && i > 0 && i < 4)
              game = true;
       if (board[i][x] == board[i + 3][x - 3] && board[i][x] == board[i + 2][x - 2] && board[i][x] == board[i + 1][x - 1] && x > 2 && i < 3)
              game = true;
       return game;
}
