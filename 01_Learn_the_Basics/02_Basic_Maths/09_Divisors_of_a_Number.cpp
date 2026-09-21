#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int n)
{
    vector<int> divisors;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
        }
    }
    return divisors;
}
int main()
{

    int n;
    cin >> n;
    vector<int> divisors = divisors(n);
    for (int i = 0; i < divisors.size(); i++)
    {
        cout << divisors[i] << " ";
    }

    return 0;
}

// Example Input: n = 12
// Expected Output: 1 2 3 4 6 12

// Time Complexity: O(n)
// Space Complexity: O(n)