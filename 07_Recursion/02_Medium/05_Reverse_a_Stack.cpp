#include <bits/stdc++.h>
using namespace std;

// You are given a stack of integers. Your task is to reverse the stack using recursion. You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop constructs or additional data structures like arrays or queues.
// Your solution must modify the input stack in-place to reverse the order of its elements.

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int data = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(data);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;
    int x = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, x);
}

int main()
{
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}

// Example 1:
// Input: stack = [4, 1, 3, 2]
// Output: [2, 3, 1, 4]

// Example 2:
// Input: stack = [10, 20, -5, 7, 15]
// Output: [15, 7, -5, 20, 10]

// Time Complexity: O(n)
// Space Complexity: O(n)