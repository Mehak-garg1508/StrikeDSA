#include<iostream>
using namespace std;

int main(){
  int num;
  cout << "Enter the number" << endl;
  cin >> num;

  if(num<2){
    cout << "Not a prime number" << endl;
    return 0;
  }

  for(int i = 2; i <= num-1; i++){
    if(num%i == 0){
      cout << "Not a prime Number" << endl;
      return 0;
    }
  }

  cout << "Prime Number" << endl;
}