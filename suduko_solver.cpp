#include <iostream>
using namespace std;

#define N 9

// Function to print the Sudoku board
void printBoard(int board[N][N]) 
{
	    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout <<"\033[32m" << board[i][j] << " \033[0m";
        }
       cout <<endl;
    }
    
    cout<<"\nsuduko solved !\n\n";

}


bool isValid(int board[N][N], int row, int col, int num) 
{
    // Check the row
    for (int x = 0; x < N; x++) 
    {
        if (board[row][x] == num) 
        {
            return false;
        }
    }

    // Check the column
    for (int x = 0; x < N; x++) 
    {
        if (board[x][col] == num) 
        {
            return false;
        }
    }

    // Check the 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i + startRow][j + startCol] == num) 
            {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int board[N][N]) 
{
    int row, col;
    bool empty = false;

    // Find an empty cell
    for (row = 0; row < N; row++) 
    {
        for (col = 0; col < N; col++) 
        {
            if (board[row][col] == 0) 
            {
                empty = true;
                break;
            }
        }
       
        if (empty) 
        {
            break;
        }
    }

    // If no empty cell is found, the puzzle is solved
    if (!empty) 
    {
        return true;
    }

    // Try numbers 1-9 in the empty cell
    for (int num = 1; num <= N; num++) 
    {
        if (isValid(board, row, col, num)) 
        {
            board[row][col] = num;

            // Recur to solve the rest of the board
            if (solveSudoku(board)) 
            {
                return true;
            }

            // If not solvable, reset and try the next number
            board[row][col] = 0;
        }
    }

    return false;
}

int main() 
{
  int board[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

    
    if (solveSudoku(board)) 
    {
        printBoard(board);
    } 
    
    else 
    {
       cout << "\nNo solution exists\n\n" ;
    }

    return 0;
}
 