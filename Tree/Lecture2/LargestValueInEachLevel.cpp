#include<iostream>
#include<queue>
#include<math.h>
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

void LargestValue(Node *root, vector<int>&ans){
queue<Node*>q;
q.push(root);
while(!q.empty()){
  int length = q.size();
  int result = INT8_MIN;
  while(length--){
  Node *temp = q.front();
  q.pop();
  result = max(result,temp->data);
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
  vector<int>ans;
  cout << "Largest value in each level is: " <<endl;
  LargestValue(root,ans);
  for(int i = 0 ; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
  return 0;
}