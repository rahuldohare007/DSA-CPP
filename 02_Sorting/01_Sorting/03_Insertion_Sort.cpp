#include <bits/stdc++.h>
using namespace std;

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
 
    return 0;
}

// Time Complexity:
// Best: O(n) when the array is already sorted
// Average: O(n^2) in all cases (average, worst)
// Worst: O(n^2) in all cases (average, worst)

// Space Complexity: O(1)