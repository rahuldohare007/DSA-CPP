#include <bits/stdc++.h>
using namespace std;

// Given the head of a doubly linked list and an integer X, insert a node with value X before the head of the linked list and return the head of the modified list.

struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

ListNode *insertBeforeHead(ListNode *head, int X)
{
    ListNode *newNode = new ListNode(X);
    newNode->next = head;
    if (head != nullptr)
    {
        head->prev = newNode;
    }
    return newNode;
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

    int X;
    cin >> X; // Value to be inserted before the head

    head = insertBeforeHead(head, X);

    cout << "Modified List after inserting " << X << " before head: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head = [1, 2, 3], X = 3
// Output: head = [3, 1, 2, 3]
// Explanation: 3 was added before the 1st node. Note that the head's value is changed.

// Example 2:
// Input: head = [5], X = 7
// Output: head = [7, 5]

// Example 3:
// Input: head = [2, 3], X = 10
// Output: head -> 10 <-> 2 <-> 3

// Time Complexity: O(1) - Inserting a node before the head of a linked list takes constant time, as we only need to update the head pointer and the next pointer of the new node.
// Space Complexity: O(1) - We are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the linked list.