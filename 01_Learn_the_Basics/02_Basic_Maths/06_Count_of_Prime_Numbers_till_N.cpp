#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int primeCount(int num)
{
    int count = 0;
    for (int i = 2; i <= num; i++)
    {
        if (isPrime(i))
            count++;
    }
    return count;
}
int main()
{

    int num;
    cin >> num;
    cout << primeCount(num) << endl;

    return 0;
}

// Example Input/Output:
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than or equal to 10, which are 2, 3, 5, and 7.

// Time Complexity: O(n)
// Space Complexity: O(1)