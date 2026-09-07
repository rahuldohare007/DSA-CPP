#include <bits/stdc++.h>
using namespace std;

void Frequency(int arr[], int n) {
    unordered_map<int, int> freqMap;

    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    int maxFreq = 0, minFreq = INT_MAX;
    int maxElem = -1, minElem = -1;

    for (const auto& pair : freqMap) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            maxElem = pair.first;
        }
        if (pair.second < minFreq) {
            minFreq = pair.second;
            minElem = pair.first;
        }
    }

    cout << "Element with highest frequency: " << maxElem << " (Frequency: " << maxFreq << ")" << endl;
    cout << "Element with lowest frequency: " << minElem << " (Frequency: " << minFreq << ")" << endl;
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    Frequency(arr, n);
 
    return 0;
}
// Example:
// Input: arr = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]
// Output:
// Element with highest frequency: 4 (Frequency: 5)
// Element with lowest frequency: 1 (Frequency: 1)


// Time Complexity: O(n), where n is the size of the input array. We traverse the array once to build the frequency map and then traverse the map to find the highest and lowest frequency elements.
// Space Complexity: O(n), as we use an unordered_map to store the frequency of each element, which can take up to O(n) space in the worst case.