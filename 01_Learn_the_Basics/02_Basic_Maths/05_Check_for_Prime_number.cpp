#include <bits/stdc++.h>
using namespace std;

isPrime(int num)
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

int main()
{

    int num;
    cin >> num;
    if (isPrime(num))
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;

    return 0;
}

// Example Input/Output:
// Input: 17
// Output: Prime

// Example Input/Output:
// Input: 10
// Output: Not Prime

// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)