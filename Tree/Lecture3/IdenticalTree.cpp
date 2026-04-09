#include<iostream>
#include<queue>
using namespace std;

class Node{
  public:
  int data;
  Node *left, *right;
  Node(int val){
    data = val;
    left = right = NULL;
  }
};

bool identical(Node *r1, Node *r2){
  if(!r1 && !r2)
  return 1;

  if((!r1&&r2) || (r1&&!r2))
  return 0;

  if(r1->data!=r2->data)
  return 0;

  return identical(r1->left,r2->left) || identical(r1->right,r2->right);que
}