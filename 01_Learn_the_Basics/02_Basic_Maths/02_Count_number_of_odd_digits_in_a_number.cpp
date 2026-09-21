#include <bits/stdc++.h>
using namespace std;

int countOddDigits(int number)
{
    int count = 0;
    while (number > 0)
    {
        int rem = number % 10;
        if (rem % 2 == 1)
        {
            count++;
        }
        number /= 10;
    }
    return count;
}

int main()
{
    int number;
    cin >> number;
    cout << countOddDigits(number) << endl;

    return 0;
}

// Example:
// Input: Num: 5
// Output: 1
// Explanation: The number 5 has 1 odd digit.

// Example:
// Input: Num: 25
// Output: 1
// Explanation: The number 25 has 1 odd digit that is 5.

// Time Complexity: O(log(n))
// Space Complexity: O(1)