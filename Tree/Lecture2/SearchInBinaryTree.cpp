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

Node *Search(Node *root, int val){
if(!root)
return NULL;

if(root->data == val)
return root;

Node *leftSide = Search(root->left,val);
if(leftSide)
return leftSide;

return Search(root->right,val);
}

void preorderofFound(Node *found){
  if(!found)
  return;

  cout << found->data << " ";
  preorderofFound(found->left);
  preorderofFound(found->right);
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

  Node *found = Search(root,2);
  preorderofFound(found);
  return 0;
}