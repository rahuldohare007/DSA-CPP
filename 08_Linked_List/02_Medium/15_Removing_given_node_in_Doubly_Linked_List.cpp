#include <bits/stdc++.h>
using namespace std;

// Given a node's reference within a doubly linked list, remove that node from the linked list while preserving the list's integrity.
// You will only be given the node's reference, not the head of the list. It is guaranteed that the given node will not be the head of the list.

struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

void deleteGivenNode(ListNode *node)
{
    if (node == nullptr)
        return;

    if (node->prev != nullptr)
    {
        node->prev->next = node->next;
    }

    if (node->next != nullptr)
    {
        node->next->prev = node->prev;
    }

    delete node;
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
    // Create doubly linked list: 1 <-> 3 <-> 5
    ListNode *head = new ListNode(1);

    ListNode *node2 = new ListNode(3);
    node2->prev = head;
    head->next = node2;

    ListNode *node3 = new ListNode(5);
    node3->prev = node2;
    node2->next = node3;

    cout << "Original List: ";
    printList(head);

    // Delete node with value 3
    deleteGivenNode(node2);

    cout << "After deletion: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head = [1, 3, 5], node = 3
// Output: [1, 5]
// Explanation: The referenced node with value 3 was removed.

// Example 2:
// Input: head = [1, 3, 7], node = 7
// Output: head = [1, 3]
// Explanation: The referenced node with value 7 was removed.

// Time Complexity: O(1) - The deletion operation is performed in constant time since we have direct access to the node to be deleted and its neighbors.
// Space Complexity: O(1) - No additional space is used for data structures; only a few pointers are used for manipulation.