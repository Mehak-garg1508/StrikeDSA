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

// Node Left Right
void preOrder(Node *root){
if(root == NULL)
return;

cout << root->data<< " ";
preOrder(root->left);
preOrder(root->right);
}

// Left Node Right
void inOrder(Node *root){
  if(root==NULL)
  return;

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

// Left Right Node
void postOrder(Node *root){
  if(root==NULL)
  return;

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
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
  cout << endl;
  cout << "Preorder traversal is: ";
  preOrder(root);
  cout << endl;
  cout << "Inorder traversal is: ";
  inOrder(root);
  cout << endl;
  cout << "Postorder traversal is: ";
  postOrder(root);
  return 0;
}

//          1
//      2         3
//  4     5     6     7
// Preorder: 1 2 4 5 3 6 7
// InOrder: 4 2 5 1 6 3 7
// PostOrder: 4 5 2 6 7 3 1