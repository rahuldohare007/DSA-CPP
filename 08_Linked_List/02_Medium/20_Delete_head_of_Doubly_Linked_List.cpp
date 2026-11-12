#include <bits/stdc++.h>
using namespace std;

// Given the head of a doubly linked list, remove the node at the head of the linked list and return the head of the modified list.
// The head is the first node of the linked list.

{
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

ListNode *deleteHead(ListNode *&head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    ListNode *newHead = head->next;

    if (newHead != nullptr)
    {
        newHead->prev = nullptr;
    }
    delete head;
    return newHead;
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
    // Create doubly linked list: 1 <-> 2 <-> 3
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node2->prev = head;
    head->next = node2;

    ListNode *node3 = new ListNode(3);
    node3->prev = node2;
    node2->next = node3;

    cout << "Original List: ";
    printList(head);

    head = deleteHead(head);

    cout << "Modified List after deleting head: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: doublyLinkedList = [1, 2, 3]
// Output: [2, 3]
// Explanation: The node with value 1 was removed.

// Example 2:
// Input: doublyLinkedList = [7]
// Output: [ ]
// Explanation: Note that the head has null value after the removal.

// Time Complexity: O(1) - Deleting the head node of a doubly linked list takes constant time, as we have direct access to the head node and can update the pointers accordingly.
// Space Complexity: O(1) - We are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the linked list.