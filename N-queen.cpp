#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& chessboard, int row, int col, int n)
{
    for (int i = 0; i < col; i++)
    {
        if (chessboard[row][i] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (chessboard[i][j] == 1)
            return false;
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (chessboard[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& chessboard, int col, int n)
{
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (isSafe(chessboard, i, col, n))
        {
            chessboard[i][col] = 1;
            if (solveNQueensUtil(chessboard, col + 1, n))
                return true;
            chessboard[i][col] = 0; // The backtrackign part
        }
    }

    return false;
}

void printSolution(vector<vector<int>>& chessboard, int n)
{
    cout << "Solution for N Queens Problem:\n";
    cout << "Chessboard Configuration:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chessboard[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Queen Positions:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (chessboard[i][j] == 1)
            {
                cout << "(" << i << "," << j << ") ";
            }
        }
    }
    cout << endl;
}

void solveNQueens(int n)
{
    vector<vector<int>> chessboard(n, vector<int>(n, 0));

    if (!solveNQueensUtil(chessboard, 0, n))
    {
        cout << "No solution exists for N Queens Problem";
        return;
    }

    printSolution(chessboard, n);
}

int main()
{
    int n;
    cout << "Enter the value of N for N Queens Problem: ";
    cin >> n;
    solveNQueens(n);
    return 0;
}
