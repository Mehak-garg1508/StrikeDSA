#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class MyQueue {
public:
stack<int>st1;
stack<int>st2;
    void push(int x) {
      cout << x << " is pushed into queue" << endl;
        st1.push(x);
    }
    
    int pop() {
        if(st1.empty()&&st2.empty())
        return -1;
        else if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            int ele = st2.top();
            st2.pop();
            return ele;
        }
        else{
            int ele = st2.top();
            st2.pop();
            return ele;
        }
    }
    
    int peek() {
        if(st1.empty()&&st2.empty())
        return -1;
        else if(!st2.empty())
        return st2.top();
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        return st1.empty()&&st2.empty();
    }
};

int main(){
MyQueue q;
q.push(4);
q.push(5);
q.push(10);
q.push(2);
cout << q.pop() << " is removed from queue" << endl;
cout << q.peek() << " is top of queue" << endl;
cout << q.pop() << " is removed from queue" << endl;
cout << q.pop() << " is removed from queue" << endl;
cout << q.pop() << " is removed from queue" << endl;
if(q.empty()){
    cout << "Queue is empty." << endl;
}
else{
    cout << "Queue is not empty." << endl;
}
}