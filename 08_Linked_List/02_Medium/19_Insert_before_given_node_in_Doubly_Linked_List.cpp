#include <bits/stdc++.h>
using namespace std;

// Given a node's reference within a doubly linked list and an integer X, insert a node with value X before the given node in the linked list while preserving the list's integrity.
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

void insertBeforeGivenNode(ListNode *node, int X){
    ListNode *newNode = new ListNode(X);
    newNode->next = node;
    newNode->prev = node->prev;

    if (node->prev != nullptr)
        node->prev->next = newNode;

    node->prev = newNode;

    return;
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
    // Create doubly linked list: 1 <-> 2 <-> 6
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node2->prev = head;
    head->next = node2;

    ListNode *node3 = new ListNode(6);
    node3->prev = node2;
    node2->next = node3;

    cout << "Original List: ";
    printList(head);

    int X, K;
    cin >> X >> K; // Value to be inserted and position
    head = insertBeforeGivenNode(head, X, K);

    cout << "Modified List after inserting " << X << " before " << K << "th node: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head = [1, 2, 6], node = 6, X = 7
// Output: head = [1, 2, 7, 6]
// Explanation: Note that the head was not given to the function.

// Example 2:
// Input: head = [7, 5, 15], node = 5, X = 10
// Output: head = [7, 10, 5, 15]
// Explanation: The node with value 5 was referenced, thus the new node was added before the given node.

// Time Complexity: O(1) - Inserting a node before a given node in a doubly linked list takes constant time, as we have direct access to the node's reference and can update the pointers accordingly.
// Space Complexity: O(1) - We are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the linked list.