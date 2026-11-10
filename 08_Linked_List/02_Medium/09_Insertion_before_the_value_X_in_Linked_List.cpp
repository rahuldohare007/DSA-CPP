#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list and two integers X and val.
// Insert a node with value val before the node with value X in the linked list and return the head of the modified list.

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

ListNode *insertBeforeX(ListNode *&head, int X, int data)
{
    ListNode *newNode = new ListNode(val);

    if (head == nullptr)
    {
        delete newNode;
        return head;
    }

    if (head->data == X)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    ListNode *temp = head;

    while (temp->next != nullptr && temp->next->data != X)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        delete newNode;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
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
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    printList(head);
    int X = 2;
    int val = 5;
    head = insertBeforeX(head, X, val);
    printList(head);

    return 0;
}

// Example 1:
// Input: linkedList = [1, 2, 3], X = 2, val = 5
// Output: [1, 5, 2, 3]
// Explanation: The node with value 5 was added before the node with value 2

// Example 2:
// Input: linkedList = [1, 2, 3], X = 7, val = 5
// Output: [1, 2, 3]
// Explanation: No node was added as X was not found in the list.

// Time Complexity: O(n), where n is the number of nodes in the linked list. In the worst case, we may need to traverse the entire list to find the node with value X.
// Space Complexity: O(1)