#include<iostream>
using namespace std;

int main(){
  int num;
  cout << "Enter the number: " << endl;
  cin >> num;

  int ans = 0;
  while(num){
    int rem = num % 10;
    num/=10;
    ans = ans*10 + rem;
  }
  cout << ans;
}