#include <bits/stdc++.h>
using namespace std;

// Iterative Approach
void printNumbers_iterative(int N)
{
    for (int i = N; i >= 1; i--)
    {
        cout << i << endl;
    }
}

// Recursive Approach
void printNumbers_recursive(int count, int N)
{
    if (count > N)
        return;

    printNumbers_recursive(count + 1, N);
    cout << count << endl;
}
int main()
{
    int N;
    cout << "Enter a number: ";
    cin >> N;

    printNumbers_iterative(N);
    printNumbers_recursive(1, N);

    return 0;
}

// Iterative
// Time Complexity: O(n)
// Space Complexity: O(1)

// Recursive
// Time Complexity: O(n)
// Space Complexity: O(n) (due to recursion stack)