#include<iostream>
using namespace std;

int main(){
  int num;
  cout << "Enter the number" << endl;
  cin >> num;

  int sum = 0;
  while(num != 0){
    int rem = num%10;
    num/=10;
    sum+=rem;
  }
  
  cout << "Sum of digits of number is: " << sum << endl;
}