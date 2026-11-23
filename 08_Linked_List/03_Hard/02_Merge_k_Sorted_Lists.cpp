#include <bits/stdc++.h>
using namespace std;

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    auto cmp = [](ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    };

    priority_queue<
        ListNode *,
        vector<ListNode *>,
        decltype(cmp)>
        minHeap(cmp);

    for (ListNode *head : lists)
    {
        if (head != nullptr)
        {
            minHeap.push(head);
        }
    }

    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (!minHeap.empty())
    {
        ListNode *node = minHeap.top();
        minHeap.pop();

        tail->next = node;
        tail = tail->next;

        if (node->next != nullptr)
        {
            minHeap.push(node->next);
        }
    }

    return dummy.next;
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
    // List 1: 1 -> 4 -> 5
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    // List 2: 1 -> 3 -> 4
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // List 3: 2 -> 6
    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode *> lists = {list1, list2, list3};

    ListNode *merged = mergeKLists(lists);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []
// Example 3:
// Input: lists = [[]]
// Output: []

// Let N = total number of nodes across all linked lists and k = number of linked lists.
// Time Complexity: O(N log k)
// Space Complexity: O(k)