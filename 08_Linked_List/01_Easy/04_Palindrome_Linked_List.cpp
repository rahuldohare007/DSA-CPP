#include <bits/stdc++.h>
using namespace std;

// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head){
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = nullptr;
    ListNode *curr = slow;

    while (curr != nullptr)
    {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    ListNode *firstHalf = head;
    ListNode *secondHalf = prev;

    while (secondHalf != nullptr)
    {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
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
    // Creating linked list: 1 -> 2 -> 2 -> 1
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << "Original List: ";
    printList(head);

    bool result = isPalindrome(head);

    if (result)
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    return 0;
}

// Example 1:
// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// Input: head = [1,2]
// Output: false

// Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse the list twice: once to find the middle and once to compare the two halves.
// Space Complexity: O(1), as we are using a constant amount of extra space for pointers.