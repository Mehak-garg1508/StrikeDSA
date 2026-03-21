#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next;

Node(int value){
data = value;
next = NULL;
}
};

class Stack{
public:
Node *index;
int size;

Stack(){
  index = NULL;
  size = 0;
}

void push(int value){
  if(index==NULL && size!=0){
    cout << "Stack Overflow" << endl;
  }
  else{
    Node *temp = new Node(value);
    temp->next = index;
    index = temp;
    size++;
    cout << index->data << " pushed into stack." << endl;
  }
}

void pop(){
  if(index==NULL){
    cout << "Stack Underflow" << endl;
    return;
  }
  else{
    cout << index->data << " popped from stack." << endl;
    Node *temp = index;
    index = index->next;
    delete temp;
    size--;
  }
}

int top(){
  return index->data;
}

bool isEmpty(){
return index==NULL;
}

int sizes(){
  return size;
}
};

int main(){
  Stack st;
  st.push(5);
  st.push(8);
  st.push(10);

  cout << "Stack top is: " << st.top() << endl;
  cout << "Stack is empty or not: " << st.isEmpty() << endl;
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  cout << "Stack is empty or not: " << st.isEmpty() << endl;
}