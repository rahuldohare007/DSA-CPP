#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n){
    if(n == 0 || n == 1){
        return n;
    }

    int i = 1;
    for(int j = 1; j < n; j++){
        if(arr[j] != arr[j-1]){
            arr[i] = arr[j];
            i++;
        }
    }
    return i;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    n = removeDuplicates(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

// Example: For an array arr = [1, 1, 2, 2, 3, 4, 4, 5]
// The function will modify the array to [1, 2, 3, 4, 5] and return the new length n = 5.
// Output: 1 2 3 4 5

// Time Complexity: O(n)
// Space Complexity: O(1)