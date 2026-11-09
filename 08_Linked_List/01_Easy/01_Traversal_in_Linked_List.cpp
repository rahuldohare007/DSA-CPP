#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly Linked List. Traverse the entire Linked List and return its elements in an array in the order of their appearance.

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

vector<int> LLTraversal(ListNode *head)
{
    vector<int> result;

    while (head != NULL)
    {
        result.push_back(head->val);
        head = head->next;
    }

    return result;
}

int main()
{
    // Create linked list: 5 -> 4 -> 3 -> 1 -> 0
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(0);

    vector<int> result = LLTraversal(head);

    for (int item : result)
    {
        cout << item << " ";
    }

    return 0;
}

// Example 1:
// Input: linkedList = [5, 4, 3, 1, 0]
// Output: [5, 4, 3, 1, 0]
// Explanation: The nodes in the Linked List are 5 -> 4 -> 3 -> 1 -> 0, with the head pointing to node with value 5.

// Example 2:
// Input: linkedList = [1]
// Output: [1]
// Explanation: Only one node (head) present in the list.

// Time Complexity: O(n)
// Space Complexity: O(n)