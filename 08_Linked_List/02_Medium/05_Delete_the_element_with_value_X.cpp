#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list and an integer X, delete the node with value X and return the head of the modified list.

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

ListNode *deleteNodeWithValueX(ListNode *&head, int X){
    if(head == NULL) return NULL;

    if(head->val == X){
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *temp = head;
    while(temp->next != NULL && temp->next->val != X){
        temp = temp->next;
    }

    if(temp->next == NULL) return head;

    ListNode *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    delete nodeToDelete;
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
    ListNode *head = new ListNode(3);
    head->next = new ListNode(4);
    head->next->next = new ListNode(5);

    printList(head);
    int X = 5;
    deleteNodeWithValueX(head, X);
    printList(head);

    return 0;
}

// Example 1:
// Input: linkedList = [3, 4, 5], X = 5
// Output: [3, 4]
// Explanation: The node with value 5 was removed.

// Example 2:
// Input: linkedList = [3, 4, 5], X = 7
// Output: [3, 4, 5]
// Explanation: No nodes were removed.

// Time Complexity: O(n)
// Space Complexity: O(1)