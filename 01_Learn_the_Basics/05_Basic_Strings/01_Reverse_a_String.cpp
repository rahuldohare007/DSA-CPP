#include <bits/stdc++.h>
using namespace std;

void reverseString(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - i - 1]);
    }
    cout << s << endl;
}

// STD library
void reverseString_std(string s)
{
    reverse(s.begin(), s.end());
}
int main()
{
    string s;
    cin >> s;

    reverseString(s);
    reverseString_std(s);

    cout << s << endl;

    return 0;
}
// Example Input: Hello
// Example Output: olleH

// Time Complexity: O(n)
// Space Complexity: O(1)