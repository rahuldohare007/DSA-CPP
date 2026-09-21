#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return sum == number;
}
int main()
{
    int number;
    cin >> number;

    if (isPerfect(number))
    {
        cout << "The number is perfect." << endl;
    }
    else
    {
        cout << "The number is not perfect." << endl;
    }

    return 0;
}

// Example:
// Input: Num: 28
// Output: The number is perfect.
// Explanation: 28 = 1 + 2 + 4 + 7 + 14

// Time Complexity: O(n)
// Space Complexity: O(1)
