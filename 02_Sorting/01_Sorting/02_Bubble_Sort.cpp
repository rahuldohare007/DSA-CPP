#include <bits/stdc++.h>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: 
// Best: O(n) when the array is already sorted
// Average: O(n^2) in all cases (average, worst)
// Worst: O(n^2) in all cases (average, worst)

// Space Complexity: O(1)