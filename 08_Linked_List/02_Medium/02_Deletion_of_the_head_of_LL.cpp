#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list, delete the head of the linked list and return the head of the modified list. The head is the first node of the linked list.
// Note : Please note that this section might seem a bit difficult without prior knowledge on what linkedList is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!

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

ListNode *deleteHead(ListNode *&head){
    ListNode *temp = head;
    head = head->next;
    delete temp;

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
    deleteHead(head);
    printList(head);

    return 0;
}

// Example 1:
// Input: linkedList = [1, 2, 3]
// Output: [2, 3]
// Explanation: The first node was removed.

// Example 2:
// Input: linkedList = [1]
// Output: []
// Explanation: Note that the head of the linked list gets changed.

// Time Complexity: O(1)
// Space Complexity: O(1)