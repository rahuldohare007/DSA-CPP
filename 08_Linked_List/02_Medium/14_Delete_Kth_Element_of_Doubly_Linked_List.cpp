#include <bits/stdc++.h>
using namespace std;

// Given the head of a doubly linked list and an integer k, remove the node at the kth position of the linked list and return the head of the modified list.

struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

ListNode *deleteKthElement(ListNode *&head, int k)
{
    if (head == nullptr || k <= 0)
        return head;

    ListNode *curr = head;
    int count = 1;

    while (curr != nullptr && count < k)
    {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr)
        return head;

    if (curr->prev != nullptr)
    {
        curr->prev->next = curr->next;
    }
    else
    {
        head = curr->next;
    }

    if (curr->next != nullptr)
    {
        curr->next->prev = curr->prev;
    }

    delete curr;

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
    // Create doubly linked list: 2 <-> 5 <-> 7 <-> 9
    ListNode *head = new ListNode(2);
    head->next = new ListNode(5);
    head->next->prev = head;

    head->next->next = new ListNode(7);
    head->next->next->prev = head->next;

    head->next->next->next = new ListNode(9);
    head->next->next->next->prev = head->next->next;

    cout << "Original List: ";
    printList(head);

    int k = 2;

    head = deleteKthElement(head, k);

    cout << "After deletion: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head = [2, 5, 7, 9], k = 2
// Output: head = [2, 7, 9]
// Explanation: The node with value 5 was removed.

// Example 2:
// Input: head = [2, 5, 7], k = 1
// Output: head = [5, 7]
// Explanation: The node with value 2 was removed, note that the head was modified.

// Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse the list to find the kth node.
// Space Complexity: O(1), as we are using a constant amount of extra space for pointers.