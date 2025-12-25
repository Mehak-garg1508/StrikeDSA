#include<iostream>
using namespace std;

int main(){
  int num;
  cout << "Enter the binary number: ";
  cin >> num;

  int ans = 0, mul = 1;
  while(num){
  int rem = num % 2;
  num /= 10;
  ans = ans + rem*mul;
  mul = mul * 2;
  }
  cout << ans;
}