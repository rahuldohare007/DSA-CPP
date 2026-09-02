#include <bits/stdc++.h>
using namespace std;

// Iterative Approach
void reverseNumbers_iterative(vector<int> &N) {
    int start = 0;
    int end = N.size() - 1;

    while (start < end) {
        swap(N[start], N[end]);
        start++;
        end--;
    }
}

// Recursive Approach
void reverseNumbers_recursive(vector<int> &N, int start, int end) {
    if (start < end) {
        swap(N[start], N[end]);
        reverseNumbers_recursive(N, start + 1, end - 1);
    }
}

// Built-in reverse function
void reverseNumbers_builtin(vector<int> &N) {
    reverse(N.begin(), N.end());
}


int main() {
    vector<int> N = { 1, 2, 3, 4, 5 };

    // Iterative Approach
    reverseNumbers_iterative(N);

    // Recursive Approach
    reverseNumbers_recursive(N, 0, N.size() - 1);

    // Built-in reverse function
    reverseNumbers_builtin(N);

    // Print the reversed vector
    for (int i = 0; i < N.size(); i++) {
        cout << N[i] << " ";
    }
    cout << endl;

    return 0;
}

// Iterative Approach
// Time Complexity: O(n)
// Space Complexity: O(1)

// Recursive Approach
// Time Complexity: O(n)
// Space Complexity: O(n) due to recursive call stack

// Built-in reverse function
// Time Complexity: O(n)
// Space Complexity: O(1)