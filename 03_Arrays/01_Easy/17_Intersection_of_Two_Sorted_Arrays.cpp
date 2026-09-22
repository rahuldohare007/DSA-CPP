#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;

    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ans = intersectionArray(nums1, nums2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// Example:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

// Example:
// Input: nums1 = [-49, -49, 0, 0, 1], nums2 = [-50, -49, 0, 0, 1]
// Output: [-49, 0, 0, 1]

// Time Complexity: O(m + n)
// Space Complexity: O(m + n)