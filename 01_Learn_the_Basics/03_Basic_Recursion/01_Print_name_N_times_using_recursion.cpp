#include <bits/stdc++.h>
using namespace std;

void printNameNTimes(string name, int n) {
    if (n <= 0) {
        return;
    }
    cout << name << endl;
    printNameNTimes(name, n - 1);
}

int main() {
    string name;
    int n;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the number of times to print your name: ";
    cin >> n;
    printNameNTimes(name, n);
 
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n) (due to recursion stack)