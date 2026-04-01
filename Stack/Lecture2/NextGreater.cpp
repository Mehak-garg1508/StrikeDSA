#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextLargerElement(vector<int>& arr) {
int n = arr.size();
stack<int>st;
vector<int>ans(n,-1);
for(int i = n - 1; i >= 0; i--){
    while(!st.empty() && arr[st.top()] <= arr[i])
    st.pop();

    if(!st.empty()){
        ans[i] = arr[st.top()];
    }

    st.push(i);
}   
return ans; 
}

int main(){
  vector<int>arr;
  arr = {8,6,4,7,4,9,10,8,12};
  vector<int>ans;
  ans = nextLargerElement(arr);
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
}