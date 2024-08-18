#include <iostream>

using namespace std;

const int N = 9;
bool is_valid(int grid[N][N], int row, int col, int num);
bool solve_sudoku(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (is_valid(grid, row, col, num))
                    {
                        grid[row][col] = num;
                        if (solve_sudoku(grid))
                        {
                            return true;
                        }
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool is_valid(int grid[N][N], int row, int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
    int start_row = row / 3 * 3;
    int start_col = col / 3 * 3;
    for (int i = start_row; i < start_row + 3; i++)
    {
        for (int j = start_col; j < start_col + 3; j++)
        {
            if (grid[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int grid[N][N] = {
        {0, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 8, 1},
        {0, 0, 0, 0, 7, 0, 0, 0, 6},
        {0, 0, 0, 2, 0, 0, 0, 0, 9},
        {0, 0, 0, 0, 4, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 7, 0}};
    if (solve_sudoku(grid))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution found" << endl;
    }
    return 0;
}