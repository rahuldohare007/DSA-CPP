#include <bits/stdc++.h>
using namespace std;

// Given the head of a doubly linked list and two integers X and K, insert a new node with value X, before the Kth node of the linked list and return the head of the modified linked list.

struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

ListNode *insertBeforeKthPosition(ListNode *head, int X, int K){
    ListNode *newNode = new ListNode(X);
    if (head == nullptr || K <= 1)
    {
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        return newNode; 
    }

    ListNode *current = head;
    int count = 1;

    while (current != nullptr && count < K)
    {
        current = current->next;
        count++;
    }

    if (current == nullptr)
    {
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
    }
    else
    {
        newNode->prev = current->prev;
        newNode->next = current;

        if (current->prev != nullptr)
            current->prev->next = newNode;

        current->prev = newNode;

        if (current == head) 
            head = newNode;
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
    // Create doubly linked list: 1 <-> 3 <-> 5
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    node2->prev = head;
    head->next = node2;

    ListNode *node3 = new ListNode(5);
    node3->prev = node2;
    node2->next = node3;

    cout << "Original List: ";
    printList(head);

    int X, K;
    cin >> X >> K; // Value to be inserted and position
    head = insertBeforeKthPosition(head, X, K);

    cout << "Modified List after inserting " << X << " before " << K << "th node: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head = [1, 3, 5], X = 7, K = 2
// Output: head = [1, 7, 3, 5]
// Explanation: A node with value 7 was added before the 2nd node.

// Example 2:
// Input: head = [5], X = 7, K = 1
// Output: head = [7, 5]
// Explanation: A node with value 7 was added, note that the head was changed.

// Time Complexity: O(n) - Inserting a node before the Kth node of a linked list takes linear time, as we may need to traverse the list to find the Kth node.
// Space Complexity: O(1) - We are not using any additional data structures that grow with the input size. The space used is constant, regardless of the size of the linked list.