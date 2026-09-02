#include <bits/stdc++.h>
using namespace std;

void printNumbers(int count, int N)
{
    if (count > N)
        return;

    cout << count << endl;
    printNumbers(count + 1, N);
}
int main()
{
    int N;
    cout << "Enter a number: ";
    cin >> N;

    printNumbers(1, N);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n) (due to recursion stack)