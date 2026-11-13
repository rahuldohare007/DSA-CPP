#include <bits/stdc++.h>
using namespace std;

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n){
    
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *first = dummy;
    ListNode *second = dummy;

    for (int i = 0; i <= n; i++)
    {
        first = first->next;
    }

    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    ListNode *nodeToDelete = second->next;
    second->next = second->next->next;
    delete nodeToDelete;

    return dummy->next;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->data;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list with values 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original linked list: ";
    printList(head);

    head = removeNthFromEnd(head, 2);

    cout << "Linked list after removing 2nd node from the end: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

// Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse the linked list twice, once to find the nth node from the end and once to remove it.
// Space Complexity: O(1), as we are using a constant amount of extra space for pointers.
