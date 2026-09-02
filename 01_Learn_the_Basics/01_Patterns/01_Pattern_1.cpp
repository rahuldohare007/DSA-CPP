#include <bits/stdc++.h>
using namespace std;

// * * * * *
// * * * * *
// * * * * *
// * * * * *
// * * * * *

int main()
{
    int N;
    cout << "Enter the number of rows: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(N^2)
// Space Complexity: O(1)

// Note: The code above prints a square pattern of asterisks (*) with N rows and N columns.
//  The outer loop iterates over the rows, while the inner loop iterates over the columns, printing an asterisk followed by a space for each column.
//  After completing each row, it moves to the next line.