#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class SpecialStack {
  public:
  stack<int>st1;  //original stack
  stack<int>st2;  //minimum stack
    void push(int x) {
    // code here
    if(st1.empty())
    {
        st1.push(x);
        st2.push(x);
    }
    else{
    st1.push(x);
    st2.push(min(st2.top(),x));  
    }
    }
    void pop() {
    // code here
    if(!st1.empty()){
       st1.pop();
       st2.pop();
    }
    }
    int peek() {
        // code here
        if(st1.empty())
        return -1;
        else
        return st1.top();
    }
    int getMin() {
        // code here
        if(st2.empty())
        return -1;
        else
        return st2.top();
    }
    bool isEmpty() {
        // code here
        if(st1.empty())
        return 1;
        else
        return 0;
    }
};

// Method 2 more optimized then above and valid for range 1-10^9
class SpecialStack1 {
  public:
  stack<long long>st;
  long long n = 1e9 + 1;
    void push(int x) {
        // code here
        if(st.empty()){
            st.push(x*n+x);
        }
        else{
            st.push(x*n+ min(st.top()%n , (long long)x));
        }
    }

    void pop() {
        // code here
        if(!st.empty()){
            st.pop();
        }
    }
    int peek() {
        // code here
        if(st.empty())
        return -1;
        else
        return st.top()/n;
    }
    int getMin() {
        // code here
        if(st.empty())
        return -1;
        else
        return st.top()%n;
    }
    bool isEmpty() {
        // code here
        if(st.empty())
        return 1;
        else
        return 0;
    }
};

int main(){
  SpecialStack1 S;
  S.push(9);
  S.push(1);
  S.push(2);
  S.push(19);
  cout << "Minimum till now is: " << S.getMin() << endl;
}