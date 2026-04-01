#include<iostream>
#include<stack>
using namespace std;

int main(){
  stack<int>st;
  st.push(5);
  st.push(6);
  st.push(7);
  cout << st.top() << endl;
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  cout << st.empty();
}