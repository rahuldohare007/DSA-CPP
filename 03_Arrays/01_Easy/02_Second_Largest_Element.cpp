#include <bits/stdc++.h>
using namespace std;

void printSecondLargest(int arr[], int n) {
    if (n < 2) {
        cout << "Invalid Input" << endl;
        return;
    }

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        cout << "There is no second largest element" << endl;
    } else {
        cout << "The second largest element is: " << second << endl;
    }
}

void printSecondSmallest(int arr[], int n) {
    if (n < 2) {
        cout << "Invalid Input" << endl;
        return;
    }

    int first = INT_MAX, second = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MAX) {
        cout << "There is no second smallest element" << endl;
    } else {
        cout << "The second smallest element is: " << second << endl;
    }
}

int main() {
    int arr[] = {10, 20, 4, 45, 99};
    int n = sizeof(arr) / sizeof(arr[0]);


    printSecondLargest(arr, n);
    printSecondSmallest(arr, n);

    return 0;
}

// Time Complexity: O(n)
// - We traverse the array once to find the second largest and second smallest elements.

// Space Complexity: O(1) 
// - We use a constant amount of space regardless of the input size.
