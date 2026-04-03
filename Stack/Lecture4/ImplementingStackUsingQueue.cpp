#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class MyStack {
public:
   queue<int>q1;
   queue<int>q2;

    MyStack() {
        
    }
    
    void push(int x) {
        if(!q1.empty()){
            cout << x << " is pushed into stack" << endl;
            q1.push(x);
        }
        else if(!q2.empty()){
            cout << x << " is pushed into stack" << endl;
            q2.push(x);
        }
        else{
            cout << x << " is pushed into stack" << endl;
            q1.push(x);
        }
    }
    
    int pop() {
        if(!q2.empty()){
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            int ele = q2.front();
            q2.pop();
            return ele;
        }
        else{
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            int ele = q1.front();
            q1.pop();
            return ele;
        }
    }
    
    int top() {
        if(!q1.empty()){
            return q1.back();
        }
        else{
            return q2.back();
        }
    }
    
    bool empty() {
        return q1.empty()&&q2.empty();
    }
};

int main(){
MyStack s;
s.push(4);
s.push(5);
s.push(10);
s.push(2);
cout << s.pop() << " is removed from stack" << endl;
cout << s.top() << " is top of stack" << endl;
cout << s.pop() << " is removed from stack" << endl;
cout << s.pop() << " is removed from stack" << endl;
cout << s.pop() << " is removed from stack" << endl;
if(s.empty()){
    cout << "Stack is empty." << endl;
}
else{
    cout << "Stack is not empty." << endl;
}
}