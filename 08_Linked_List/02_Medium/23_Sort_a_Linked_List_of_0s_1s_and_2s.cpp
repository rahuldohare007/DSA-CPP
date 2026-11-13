#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list consisting of only 0, 1 or 2.
// Sort the given linked list and return the head of the modified list.
// Do it in-place by changing the links between the nodes without creating new nodes.

struct ListNode
{
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

ListNode *sortList(ListNode *&head){

    int count[3] = {0, 0, 0};
    ListNode *temp = head;
    while (temp != NULL)
    {
        count[temp->data]++;
        temp = temp->next;
    }

    // Update the linked list with sorted values
    temp = head;
    for (int i = 0; i < 3; i++)
    {
        while (count[i] > 0)
        {
            temp->data = i;
            temp = temp->next;
            count[i]--;
        }
    }

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
    // Create a linked list with values 1 -> 0 -> 2 -> 0 -> 1
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(1);

    cout << "Original linked list: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted linked list: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: linkedList = [1, 0, 2, 0 , 1]
// Output: [0, 0, 1, 1, 2]
// Explanation: The values after sorting are [0, 0, 1, 1, 2].

// Example 2:
// Input: linkedList = [1, 1, 1, 0]
// Output: [0, 1, 1, 1]
// Explanation: The values after sorting are [0, 1, 1, 1].

// Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse the linked list twice, once to count the occurrences of 0s, 1s, and 2s, and once to update the linked list with sorted values.
// Space Complexity: O(1), as we are using a constant amount of extra space for pointers.