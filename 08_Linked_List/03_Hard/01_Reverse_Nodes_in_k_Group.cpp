#include <bits/stdc++.h>
using namespace std;

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr || k <= 1)
        return head;

    ListNode dummy(0, head);
    ListNode *groupPrev = &dummy;

    while (true)
    {
        ListNode *kth = groupPrev;

        for (int i = 0; i < k; i++)
        {
            kth = kth->next;

            if (kth == nullptr)
                return dummy.next;
        }

        ListNode *groupNext = kth->next;

        ListNode *prev = groupNext;
        ListNode *curr = groupPrev->next;

        while (curr != groupNext)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode *temp = groupPrev->next;
        groupPrev->next = kth;

        groupPrev = temp;
    }
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
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "After reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

// Time Complexity: O(n), Each node is visited and reversed a constant number of times.
// Space Complexity: O(1), Reversal is performed in-place using pointers.