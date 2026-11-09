#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list and an integer k, delete the kth node of the linked list and return the head of the modified list.

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

ListNode *deleteKthNode(ListNode *&head, int k)
{
    if (head == NULL || k <= 0)
        return head;

    if (k == 1)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *temp = head;
    int count = 1;

    while (temp->next != NULL && count < k - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
        return head;

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
    int k = 2;
    deleteKthNode(head, k);
    printList(head);

    return 0;
}

// Example 1:
// Input: linkedList = [3, 4, 5], k = 2
// Output: linkedList = [3, 5]
// Explanation: The 2nd node with value 4 was removed.

// Example 2:
// Input: linkedList = [1, 2, 3], k = 1
// Output: [2, 3]
// Explanation: The 1st Node was removed, note that the value of the head has changed.

// Time Complexity: O(n)
// Space Complexity: O(1)