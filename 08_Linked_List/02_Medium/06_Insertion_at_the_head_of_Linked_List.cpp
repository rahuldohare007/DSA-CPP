#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list and an integer X, insert a node with value X at the head of the linked list and return the head of the modified list.

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

ListNode *insertAtHead(ListNode *&head, int X)
{
    ListNode *newNode = new ListNode(X);
    newNode->next = head;
    head = newNode;
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
    head = insertAtHead(head, X);
    printList(head);

    return 0;
}

// Example 1:
// Input: linkedList = [1, 2, 3], X = 7
// Output: [7, 1, 2, 3]
// Explanation: 7 was added as the 1st node.

// Example 2:
// Input: linkedList = [], X = 7
// Output: [7]
// Explanation: 7 was added as the 1st node.

// Time Complexity: O(1) - Inserting a node at the head of a linked list takes constant time, as we only need to update the head pointer and the next pointer of the new node.
// Space Complexity: O(1) - We are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the linked list.