#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list, find the length of the loop in the linked list if it exists. Return the length of the loop if it exists; otherwise, return 0.
// A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer. Internally, pos is used to denote the index (0-based) of the node from where the loop starts.
// Note that pos is not passed as a parameter.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

int findLengthOfLoop(ListNode *head){
    ListNode *slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(!fast || !fast->next) return 0;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    int count = 1;
    while(slow->next != fast){
        slow = slow->next;
        count++;
    }
    return count;
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

    // Create loop: 5 points back to 2
    head->next->next->next->next->next = head->next;

    // Print linked list
    cout << "Linked List: ";
    printList(head);

    cout << findLengthOfLoop(head) << endl;

    // Free allocated memory
    ListNode *temp = head;
    while (temp != NULL)
    {
        ListNode *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}

// Example 1:
// Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1
// Output: 4
// Explanation: 2 -> 3 -> 4 -> 5 - >2, length of loop = 4.

// Example 2:
// Input: head -> 1 -> 3 -> 7 -> 4, pos = -1
// Output: 0
// Explanation: No loop is present in the linked list.

// Time Complexity: O(n), where n is the number of nodes in the linked list.
// Space Complexity: O(1), since we are using only a constant amount of extra space.