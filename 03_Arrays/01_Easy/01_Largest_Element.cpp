#include <bits/stdc++.h>
using namespace std;

int largestElement(int arr[], int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int largest = largestElement(arr, n);

    cout << "The largest element in the array is: " << largest << endl;
     
    return 0;
}

// Time Complexity: O(n), where n is the number of elements in the array. We traverse the array once to find the largest element.
// Space Complexity: O(1), as we are using a constant amount of space regardless of the input size.