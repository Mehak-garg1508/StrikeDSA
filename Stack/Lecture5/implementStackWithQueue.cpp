#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

class MyStack {
queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        cout << x << " is pushed into stack" << endl;
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        const int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }  
};

int main(){
MyStack st;
st.push(3);
st.push(4);
st.push(5);
cout << st.pop() << " element is removed from stack" << endl;
cout << st.pop() << " element is removed from stack" << endl;
cout << st.pop() << " element is removed from stack" << endl;
cout << st.empty() << endl;
}