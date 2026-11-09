#include <bits/stdc++.h>
using namespace std;

// There is a singly-linked list head and we want to delete a node node in it.
// You are given the node to be deleted node. You will not be given access to the first node of head.
// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
// Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
// The value of the given node should not exist in the linked list.
// The number of nodes in the linked list should decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.
// Custom testing:
// For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
// We will build the linked list and pass the node to your function.
// The output will be the entire list after calling your function.

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

// Delete the given node
void deleteNode(ListNode *node)
{
    if (node == NULL || node->next == NULL)
        return;

    ListNode *nextNode = node->next;

    node->val = nextNode->val;
    node->next = nextNode->next;

    delete nextNode;
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
    // Create linked list: 4 -> 5 -> 1 -> 9
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List: ";
    printList(head);

    // Given node to delete (value 5)
    ListNode *nodeToDelete = head->next;

    deleteNode(nodeToDelete);

    cout << "After deletion: ";
    printList(head);

    return 0;
}

// Example 1:
// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

// Example 2:
// Input: head = [4,5,1,9], node = 1
// Output: [4,5,9]
// Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.

// Time Complexity: O(1) - The deletion operation is done in constant time since we are only modifying the values and pointers of the given node and its next node.
// Space Complexity: O(1) - No additional space is used for data structures; only a few pointers are used for manipulation.