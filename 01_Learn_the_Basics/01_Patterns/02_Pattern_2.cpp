#include <bits/stdc++.h>
using namespace std;

// *
// * *
// * * *
// * * * *
// * * * * *

int main()
{
    int N;
    cout << "Enter the number of rows: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(N^2)
// Space Complexity: O(1)
