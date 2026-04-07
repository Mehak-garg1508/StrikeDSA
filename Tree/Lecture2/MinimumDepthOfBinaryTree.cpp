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

int minDepth(Node *root){
  if(!root)
  return 0;
  
  if(!root->left && root->right)
  return 1 + minDepth(root->right);

  if(root->left && !root->right)
  return 1 + minDepth(root->left);

  return 1 + min(minDepth(root->left),minDepth(root->right));
}

int main(){
  int x;
  cout << "Enter the root node: ";
  cin >> x;
  Node *root = new Node(x);
  queue<Node*>q;
  q.push(root);
  while(!q.empty()){
  Node *temp = q.front();
  q.pop();
  int leftval, rightval;
  cout << "Enter left child of " << temp->data << ": ";
  cin >> leftval;
  if(leftval!=-1){
   temp->left = new Node(leftval);
   q.push(temp->left);
  }
   cout << "Enter right child of " << temp->data << ": ";
  cin >> rightval;
  if(rightval!=-1){
   temp->right = new Node(rightval);
   q.push(temp->right);
  }
  }
  cout << "Minimum Depth of binary tree: " << minDepth(root);
  return 0;
}