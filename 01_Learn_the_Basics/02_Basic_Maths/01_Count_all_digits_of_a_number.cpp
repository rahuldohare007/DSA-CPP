#include <bits/stdc++.h>
using namespace std;

int countDigits(int N)
{
    // string S = to_string(N);
    // return S.length();

    int cnt = (int)log10(N) + 1;
    return cnt;
}

int main()
{
    int N;
    cout << "Enter a number: ";
    cin >> N;

    cout << "Number of digits: " << countDigits(N) << endl;

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)