#include <bits/stdc++.h>
using namespace std;

// You are given the head of a singly linked list. Your task is to return the number of nodes in the linked list.

int getLength(ListNode *head)
{
    int length = 0;
    ListNode *current = head;
    while (current != nullptr)
    {
        length++;
        current = current->next;
    }
    return length;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << getLength(head) << endl;

    return 0;
}

// Example 1:
// Input: head = [1, 2, 3, 4, 5]
// Output: 5

// Example 2:
// Input: head = [8, 6]
// Output: 2

// Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse the entire list once to count the nodes.
// Space Complexity: O(1)