#include<iostream>
#include<queue>
#include<vector>
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

void levelOrderTraversal(Node *root, vector<vector<int>>&ans){
  queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    int length = q.size();
    vector<int>result;
    while(length--){
    Node *temp = q.front();
    q.pop();
    result.push_back(temp->data);
    if(temp->left)
    q.push(temp->left);
    if(temp->right)
    q.push(temp->right);
    }
    ans.push_back(result);
  }
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

  vector<vector<int>>ans;
  levelOrderTraversal(root,ans);
  for(int i = 0; i < ans.size(); i++){
    cout << "[";
    for(int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << "] ";
  }

  return 0;
}