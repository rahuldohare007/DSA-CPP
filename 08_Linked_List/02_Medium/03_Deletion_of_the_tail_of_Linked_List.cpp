#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list, delete the tail of the linked list and return the head of the modified list.
// The tail is the last node of the linked list.

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

ListNode *deleteTail(ListNode *&head){
    if(head == NULL) return NULL;

    if(head->next == NULL){
        delete head;
        return NULL;
    }

    ListNode *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

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
    deleteTail(head);
    printList(head);

    return 0;
}

// Example 1:
// Input: linkedList = [1, 2, 3]
// Output: [1, 2]
// Explanation: The last node was removed.

// Example 2:
// Input: linkedList = [1]
// Output: []
// Explanation: Note that the value of head is null here.

// Time Complexity: O(n)
// Space Complexity: O(1)