#include <bits/stdc++.h>
using namespace std;

// Given the head of a doubly linked list and an integer X, insert a node with value X before the tail of the linked list and return the head of the modified list.

struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

ListNode *insertBeforeTail(ListNode *head, int X){
    ListNode *newNode = new ListNode(X);
    if (head == nullptr)
    {
        return newNode; 
    }

    ListNode *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next; 
    }

    newNode->prev = tail->prev; 
    newNode->next = tail;       

    if (tail->prev != nullptr)
    {
        tail->prev->next = newNode; 
    }
    else
    {
        head = newNode; 
    }

    tail->prev = newNode; 

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
    // Create doubly linked list: 1 <-> 2 <-> 4
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node2->prev = head;
    head->next = node2;

    ListNode *node3 = new ListNode(4);
    node3->prev = node2;
    node2->next = node3;

    cout << "Original List: ";
    printList(head);

    int X;
    cin >> X; // Value to be inserted before the tail
    head = insertBeforeTail(head, X);

    cout << "Modified List after inserting " << X << " before tail: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head = [1, 2, 4], X = 3
// Output: head = [1, 2, 3, 4]
// Explanation: 3 was added before the last node.

// Example 2:
// Input: head = [4], X = 6
// Output: head = [6, 4]
// Explanation: 6 was added before 4, note that the head was changed as a result.

// Time Complexity: O(n) - Inserting a node before the tail of a linked list takes linear time, as we need to traverse the list to find the tail node.
// Space Complexity: O(1) - We are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the linked list.