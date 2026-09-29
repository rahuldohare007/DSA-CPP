#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int number)
{
    int sum = 1;
    if (number == 1)
        return fasle;
    for (int i = 2; i < number / i; i++)
    {
        if (number % i == 0 && i != number / i)
        {
            sum += i + (number / i);
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
