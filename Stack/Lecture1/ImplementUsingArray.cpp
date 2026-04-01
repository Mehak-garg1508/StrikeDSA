// Implementing stack using array

#include<iostream>
using namespace std;

class Stack{
public:
int arr[100];
int index;

Stack(){
  index = -1;
}

void push(int value){
if(index==99){
  cout << "Stack Overflow" << endl;
  return;
}
else{
  index++;
  arr[index] = value;
  cout << value << " is pushed in stack" << endl;
}
}

void pop(){
  if(index==-1){
    cout << "Stack Underflow" << endl;
    return;
  }
  else{
    cout << arr[index] << " is removed from stack" << endl;
    index--;
  }
}

int top(){
  return arr[index];
}

bool isEmpty(){
  return index==-1;
}

int size(){
  return index+1;
}
};

int main(){
  Stack st;
  st.push(5);
  st.push(4);
  st.push(8);
  st.pop();
  cout << "Size of Stack is: " << st.size() << endl;
  cout << "Stack is empty or not" <<st.isEmpty()<<endl;
  st.pop();
  st.pop();
  cout << "Stack is empty or not" <<st.isEmpty()<<endl;
}