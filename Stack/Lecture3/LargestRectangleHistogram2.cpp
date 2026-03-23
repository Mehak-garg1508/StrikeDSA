#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int>st;
    int ans = 0;
    int n = heights.size();
    for(int i = 0; i < n; i++){
        while(!st.empty() && heights[st.top()] > heights[i]){
            int index = st.top();
            st.pop();
            if(!st.empty())
            ans = max(ans, heights[index]*(i-st.top()-1));
            else
            ans = max(ans, heights[index]*i);
        }
        st.push(i);
    }
    while(!st.empty()){
        int index = st.top();
        st.pop();
        if(!st.empty())
        ans = max(ans, heights[index]*(n-st.top()-1));
        else
        ans = max(ans, heights[index]*n);
    }
    return ans;
}

int main(){
  vector<int>heights = {2,1,5,6,2,3};
  cout << "Answer is: " << largestRectangleArea(heights) << endl;
}