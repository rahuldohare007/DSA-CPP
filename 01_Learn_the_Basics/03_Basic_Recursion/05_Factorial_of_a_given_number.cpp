#include <bits/stdc++.h>
using namespace std;

// Iterative Approach
int factorial_iterative(int N)
{
    int result = 1;
    for (int i = 2; i <= N; ++i)
    {
        result *= i;
    }
    return result;
}

// Recursive Approach
int factorial_recursive(int N)
{
    if (N == 0)
    {
        return 1;
    }
    return N * factorial_recursive(N - 1);
}

int main()
{
    int N;
    cout << "Enter a number: ";
    cin >> N;

    cout << "Factorial of " << N << " (Iterative): " << factorial_iterative(N) << endl;
    cout << "Factorial of " << N << " (Recursive): " << factorial_recursive(N) << endl;

    return 0;
}

// Time Complexity Iterative: O(N)
// Space Complexity Iterative: O(1)

// Time Complexity Recursive: O(N)
// Space Complexity Recursive: O(N) (due to recursion stack)