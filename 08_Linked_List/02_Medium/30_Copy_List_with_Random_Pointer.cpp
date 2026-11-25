#include <bits/stdc++.h>
using namespace std;

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

struct ListNode
{
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;

    while (temp != nullptr)
    {
        Node *copy = new Node(temp->val);

        copy->next = temp->next;
        temp->next = copy;

        temp = copy->next;
    }

    temp = head;

    while (temp != nullptr)
    {
        if (temp->random != nullptr)
            temp->next->random = temp->random->next;

        temp = temp->next->next;
    }

    temp = head;

    Node dummy(0);
    Node *tail = &dummy;

    while (temp != nullptr)
    {
        Node *copy = temp->next;

        temp->next = copy->next;

        tail->next = copy;
        tail = copy;

        temp = temp->next;
    }

    tail->next = nullptr;

    return dummy.next;
}

void printList(ListNode *head)
{
  while (head != nullptr) {
        cout << "[" << head->val << ", ";

        if (head->random != nullptr)
            cout << head->random->val;
        else
            cout << "null";

        cout << "]";

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}
int main()
{
     // Create original linked list
    Node* head = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    // Connect next pointers
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Connect random pointers
    head->random = nullptr;
    n2->random = head;
    n3->random = n5;
    n4->random = n3;
    n5->random = head;

    cout << "Original List: ";
    printList(head);

    Node* copied = copyRandomList(head);

    cout << "Copied List: ";
    printList(copied);

    return 0;
}

// Example 1:
// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

// Example 2:
// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]

// Example 3:
// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]

// Time Complexity: O(n)
// Space Complexity: O(1) — excluding the newly created output nodes.