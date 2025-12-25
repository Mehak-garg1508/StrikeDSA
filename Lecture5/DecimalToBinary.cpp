#include<iostream>
using namespace std;

int main(){
  int num;
  cout << "Enter the number: "; 
  cin >> num;
  // int ans = 0;
  // while(num){
  // int rem = num % 2;
  // num /= 2;
  // ans = ans*10+rem;
  // }
  // // reverse the answer
  // int final = 0;
  // while(ans){
  //   int rem = ans%10;
  //   ans/=10;
  //   final=final*10+rem;
  // }
  // cout << final;

  // Agar hame ek hi bar ma answer dena ho toh
  int ans = 0, mul = 1;
  while(num){
    int rem = num%2;
    num/=2;
    ans = ans + rem*mul;
    mul = mul * 10;
  }
  cout << ans;
}