#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list and two integers X and K, insert a node with value X as the kth node of the linked list and return the head of the modified list.

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

ListNode *insertAtKthPosition(ListNode *&head, int X, int K)
{
    ListNode *newNode = new ListNode(X);

    if (K == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    ListNode *temp = head;
    for (int i = 1; i < K - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "The position K is greater than the length of the linked list." << endl;
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
    int X = 5;
    int K = 2;
    head = insertAtKthPosition(head, X, K);
    printList(head);

    return 0;
}

// Example 1:
// Input: linkedList = [1, 2, 3], X = 5, K = 2
// Output: [1, 5, 2, 3]

// Example 2:
// Input: linkedList = [], X = 7, K = 1
// Output: [7]
// Explanation: Note that the value of the head was changed.

// Time Complexity: O(K) - Inserting a node at the kth position requires traversing the linked list up to the (K-1)th node, which takes linear time in the worst case.
// Space Complexity: O(1) - We are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the linked list.