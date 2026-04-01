#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
public:
int index; 
Node *next;
Node(int value){
index = value;
next = NULL;
}
};

class NStack
{
public:

   int *arr;
   Node **top;
   stack<int>st;

    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        arr = new int[S];
        top = new Node*[N];
        for(int i = 0; i < N; i++)
        top[i] = NULL;
        for(int i = 0; i < S; i++){
            st.push(i);
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(st.empty())
        return 0;

        arr[st.top()] = x;
        Node *temp = new Node(st.top());
        temp->next = top[m-1];
        top[m-1] = temp;
        st.pop();
        return 1;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1]==NULL)
        return -1;

        st.push(top[m-1]->index);
        int element = arr[top[m-1]->index];
        top[m-1] = top[m-1]->next;
        return element;
    }
};