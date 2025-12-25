#include<iostream>
using namespace std;

int main(){
  int n;
  cout << "Enter the number: ";
  cin >> n;
  
  // int ans = 1;
  // jise bade number per integer overflow na ho
  long long ans = 1;
  for(int i = 1; i <= n; i++){
  ans = ans * i;
  }
  cout << ans;
}