#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        
        for(int i = 0; i < n; i++){
            // Value kab tak pop hogi
            // NSL NSR
            while(!st.empty() && arr[st.top()] > arr[i]){
                int index = st.top();
                st.pop();
                int range = 0;
                if(st.empty()){
                    // i = next smallest right element
                    // Stack ke andar jo index, NSL (-1)
                    // i - (-1) - 1 = i
                    range = i;
                   ans[range - 1] = max(ans[range - 1], arr[index]);
                }
                else{
                    // Maximum window size
                    range = i - st.top() - 1;
                    ans[range - 1] = max(ans[range - 1], arr[index]);
                }
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int index = st.top();
            st.pop();
            if(st.empty()){
                int range = n;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
            else{
                int range = n - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }
        // ans array ko update kar diya
        for(int i = n - 2; i >= 0; i--){
            ans[i] = max(ans[i],ans[i+1]);
        }
        
        return ans;
}

int main(){
  vector<int>arr = {10,20,30,50,10,70,30};
  vector<int>ans;
  ans = maxOfMins(arr);
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
}