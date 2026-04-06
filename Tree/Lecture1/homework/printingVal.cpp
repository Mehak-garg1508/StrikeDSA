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

// Level Traversal
void LevelTraversal(Node *root){
  queue<Node *>q;
  q.push(root);
  while(!q.empty()){
    Node *temp = q.front();
    q.pop();
    cout << temp->data << " ";
    if(temp->left){
    q.push(temp->left);
    }
    if(temp->right){
    q.push(temp->right);
    }
  }
}

// Node Right Left
void method1(Node *root){
if(root == NULL)
return;

cout << root->data<< " ";
method1(root->right);
method1(root->left);
}

// Right Node Left
void method2(Node *root){
if(root == NULL)
return;

method2(root->right);
cout << root->data<< " ";
method2(root->left);
}

// Right Left Node
void method3(Node *root){
if(root == NULL)
return;

method3(root->right);
method3(root->left);
cout << root->data<< " ";
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
  cout << "Level traversal is: ";
  LevelTraversal(root);
  cout << endl;
  cout << "Method1 ie Node Right Left traversal is: ";
  method1(root);
  cout << endl;
  cout << "Method2 ie Right Node Left traversal is: ";
  method2(root);
  cout << endl;
  cout << "Method3 ie Right Left Node traversal is: ";
  method3(root);
  return 0;
}

//            1
//       2          3
//   4      5    6      7
// LevelTraversal: 1 2 3 4 5 6 7
// Method1: 1 3 7 6 2 5 4
// Method2: 7 3 6 1 5 2 4
// Method3: 7 6 3 5 4 2 1