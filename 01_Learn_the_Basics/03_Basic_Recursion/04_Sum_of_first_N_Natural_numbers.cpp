#include <bits/stdc++.h>
using namespace std;

// Iterative Approach
void sumOfNaturalNumbers(int N)
{
    return (N * (N + 1)) / 2;
}

// Recursive Approach
int sumOfNaturalNumbersRecursive(int N)
{
    if (N == 1)
        return 1;
    return N + sumOfNaturalNumbersRecursive(N - 1);
}

int main()
{
    int N;
    cout << "Enter a number: ";
    cin >> N;

    cout << "Sum of first " << N << " natural numbers (Iterative): " << sumOfNaturalNumbers(N) << endl;
    cout << "Sum of first " << N << " natural numbers (Recursive): " << sumOfNaturalNumbersRecursive(N) << endl;

    return 0;
}

// Iterative Approach
// Time Complexity: O(1)
// Space Complexity: O(1)

// Recursive Approach
// Time Complexity: O(n)
// Space Complexity: O(n)(due to recursion stack)