#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list and an integer X, insert a node with value X at the tail of the linked list and return the head of the modified list.

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

ListNode *insertAtTail(ListNode *&head, int X)
{
    ListNode *newNode = new ListNode(X);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

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
    int X = 7;
    head = insertAtTail(head, X);
    printList(head);

    return 0;
}

// Example 1:
// Input: linkedList = [1, 2, 3], X = 7
// Output: [1, 2, 3, 7]
// Explanation: 7 was added as the last node.

// Example 2:
// Input: linkedList = [], X = 0
// Output: [0]
// Explanation: 0 was added as the last/only node.

// Time Complexity: O(n) - Inserting a node at the tail of a linked list requires traversing the entire list to find the last node, which takes linear time in the size of the list.
// Space Complexity: O(1) - We are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the linked list.