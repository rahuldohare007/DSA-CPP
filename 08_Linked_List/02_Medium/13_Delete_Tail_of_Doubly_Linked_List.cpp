#include <bits/stdc++.h>
using namespace std;

// Given the head of a doubly linked list, remove the node at the tail of the linked list and return the head of the modified list.
// The tail is the last node of the linked list.

struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

ListNode *deleteTail(ListNode *&head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    ListNode *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->prev->next = nullptr;
    delete current;

    return head;
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
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->prev = head;
    head->next->next = new ListNode(3);
    head->next->next->prev = head->next;

    printList(head);
    head = deleteTail(head);
    printList(head);

    return 0;
}

// Example 1:
// Input: head = [1, 2, 3]
// Output: head = [1, 2]
// Explanation: The node with value 3 was removed.

// Example 2:
// Input: head = [7]
// Output: head = [ ]
// Explanation: Note that the head has null value after the removal.

// Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse the entire list to find the tail node.
// Space Complexity: O(1), as we are using a constant amount of extra space for pointers.