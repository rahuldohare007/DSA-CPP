#include <bits/stdc++.h>
using namespace std;

// Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.
// Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. If there are no such pairs, return an empty list.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode()
    {
        delete next;
    }
};

vector<vector<int>> findPairsWithGivenSum(ListNode *head, int target)
{
    vector<vector<int>> ans;

    if (head == nullptr)
        return ans;

    ListNode *left = head;
    ListNode *right = head;

    while (right->next != nullptr)
    {
        right = right->next;
    }

    while (left != right && left->prev != right)
    {

        long long sum = (long long)left->val + right->val;

        if (sum == target)
        {
            ans.push_back({left->val, right->val});

            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }

    return ans;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;

        if (head->next != nullptr)
            cout << " <-> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{

    // Create doubly linked list
    vector<int> arr = {1, 2, 4, 5, 6, 8, 9};

    ListNode *head = new ListNode(arr[0]);
    ListNode *tail = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *newNode = new ListNode(arr[i]);

        tail->next = newNode;
        newNode->prev = tail;

        tail = newNode;
    }

    int target = 7;

    cout << "Original List: ";
    printList(head);

    vector<vector<int>> ans = findPairsWithGivenSum(head, target);

    cout << "Pairs: ";

    for (auto &pair : ans)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }

    cout << endl;

    delete head;

    return 0;
}

// Example 1:
// Input: head = [1, 2, 4, 5, 6, 8, 9], target = 7
// Output: [[1, 6], [2, 5]]
// Explanation: 1 + 6 = 7 and 2 + 5 = 7 are the valid pairs.

// Example 2:
// Input: head = [1, 5, 6], target = 6
// Output: [[1, 5]]
// Explanation: 1 + 5 = 6 is the only valid pair.

// Time Complexity: O(n)
// Space Complexity: O(1) — excluding the result array.