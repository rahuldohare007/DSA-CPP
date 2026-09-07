#include <bits/stdc++.h>
using namespace std;

// Quick Sort
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
 
    return 0;
}

// Time Complexity:
// Best: O(n log n) when the pivot divides the array into two equal halves
// Average: O(n log n) in all cases (average, worst)
// Worst: O(n^2) when the pivot is always the smallest or largest element

// Space Complexity: O(log n) for recursive stack space