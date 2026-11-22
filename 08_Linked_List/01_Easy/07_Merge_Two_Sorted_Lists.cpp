#include <bits/stdc++.h>
using namespace std;

// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1 != nullptr)
        tail->next = list1;
    else
        tail->next = list2;

    return dummy.next;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }
    cout << endl;
}

int main()
{
    // List 1: 1 -> 2 -> 4
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // List 2: 1 -> 3 -> 4
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    ListNode *merged = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

// Time Complexity: O(n + m)
// Space Complexity: O(1)