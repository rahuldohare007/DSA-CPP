#include <bits/stdc++.h>
using namespace std;

// Given an array arr, convert it into a doubly linked list and return the head of the list.

struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

ListNode *arrayToDoublyLinkedList(vector<int> &arr){
    if (arr.empty())
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;

    for (size_t i = 1; i < arr.size(); ++i)
    {
        ListNode *newNode = new ListNode(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
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
    vector<int> arr = {1, 2, 3, 4};

    ListNode *head = arrayToDoublyLinkedList(arr);

    printList(head);
    return 0;
}

// Example 1:
// Input: arr = [1, 2, 3, 4]
// Output: [1, 2, 3, 4]

// Example 2:
// Input: arr = [7, 7]
// Output: [7, 7]

// Time Complexity: O(n), where n is the number of elements in the array. We traverse the array once to create the doubly linked list.
// Space Complexity: O(n), for the new doubly linked list that we create to store the result.