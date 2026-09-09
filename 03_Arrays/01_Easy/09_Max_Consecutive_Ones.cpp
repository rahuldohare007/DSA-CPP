#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> arr)
{
    int maxCount = 0;
    int currentCount = 0;

    for (int num : arr)
    {
        if (num == 1)
        {
            currentCount++;
            maxCount = max(maxCount, currentCount);
        }
        else
        {
            currentCount = 0;
        }
    }

    return maxCount;
}

int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1};

    int result = findMaxConsecutiveOnes(arr);

    cout << "The maximum number of consecutive ones is: " << result << endl;

    return 0;
}

// Example:
// Input: arr = [1, 1, 0, 1, 1, 1]
// Output: 3

// Time Complexity: O(n)
// Space Complexity: O(1)