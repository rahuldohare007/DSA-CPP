#include <bits/stdc++.h>
using namespace std;

// Sum of n natural numbers = n(n+1)/2
int missingNumber(vector<int> arr)
{
    int n = arr.size() + 1; // Since one number is missing, the size of the array is n-1
    long long sum = 0;

    for (int num : arr)
    {
        sum += num;
    }

    long long totalSum = (n * 1LL * (n + 1)) / 2;

    return totalSum - sum;
}

// Using XOR Operation
int missingNumberXOR(vector<int> arr)
{
    int n = arr.size() + 1; // Since one number is missing, the size of the array is n-1
    int xorSum = 0;

    // XOR array elements
    for (int num : arr)
    {
        xorSum = xorSum ^ num;
    }

    // XOR numbers from 0 to n
    for (int i = 1; i <= n; i++)
    {
        xorSum = xorSum ^ i;
    }

    return xorSum;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6};

    int result = missingNumber(arr);
    int resultXOR = missingNumberXOR(arr);

    cout << "The missing number is: " << result << endl;
    cout << "The missing number (XOR method) is: " << resultXOR << endl;

    return 0;
}

// Example:
// Input: arr = [1, 2, 3, 4, 6]
// Output: 5

// Time Complexity: O(n)
// Space Complexity: O(1)

// Time Complexity (XOR method): O(n)
// Space Complexity (XOR method): O(1)