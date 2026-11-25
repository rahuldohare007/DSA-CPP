#include <bits/stdc++.h>
using namespace std;

// Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list.

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

ListNode *deleteAllOccurrences(ListNode *head, int target)
{
    ListNode *temp = head;

    while (temp != nullptr)
    {
        ListNode *nextNode = temp->next;

        if (temp->val == target)
        {
            if (temp == head)
                head = temp->next;

            if (temp->prev != nullptr)
                temp->prev->next = temp->next;

            if (temp->next != nullptr)
                temp->next->prev = temp->prev;

            delete temp;
        }
        temp = nextNode;
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
    // Create: 1 <-> 2 <-> 3 <-> 1 <-> 4
    ListNode *head = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(1);
    ListNode *n5 = new ListNode(4);

    head->next = n2;
    n2->prev = head;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    int target = 1;

    cout << "Original List: ";
    printList(head);

    head = deleteAllOccurrences(head, target);

    cout << "Modified List: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1
// Output: head -> 2 <-> 3 <-> 4
// Explanation: All nodes with the value 1 were removed.

// Example 2:
// Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2
// Output: head -> 3 <-> -1 <-> 4
// Explanation: All nodes with the value 2 were removed.
// Note that the value of head is changed.

// Time Complexity: O(n)
// Space Complexity: O(1)