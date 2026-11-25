#include <bits/stdc++.h>
using namespace std;

// Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.
// Return the head of the modified linked list.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

ListNode *removeDuplicates(ListNode *head)
{
    ListNode *temp = head;

    while (temp != nullptr && temp->next != nullptr)
    {

        if (temp->val == temp->next->val)
        {
            ListNode *duplicate = temp->next;

            temp->next = duplicate->next;

            if (duplicate->next != nullptr)
                duplicate->next->prev = temp;

            delete duplicate;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
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
    // Create: 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
    vector<int> arr = {1, 1, 3, 3, 4, 5};

    ListNode *head = new ListNode(arr[0]);
    ListNode *tail = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *newNode = new ListNode(arr[i]);

        tail->next = newNode;
        newNode->prev = tail;

        tail = newNode;
    }

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
// Output: head -> 1 <-> 3 <-> 4 <-> 5
// Explanation: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
// The underlined nodes were deleted to get the desired result.

// Example 2:
// Input: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2
// Output: head -> 1 <-> 2
// Explanation: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2
// The underlined nodes were deleted to get the desired result.

// Time Complexity: O(n)
// Space Complexity: O(1)