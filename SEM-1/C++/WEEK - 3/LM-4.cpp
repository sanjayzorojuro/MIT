//program to reverse a integer and double that number.
#include<algorithm>
#include <iostream>
using namespace std;

int inverse(int &n){
	int rev = 0;
	int temp = n;
	
	while(temp > 0){
		rev = (rev*10)+(temp%10);
		temp = temp/10;
		
	}
	return rev *2;
}
int main(){
	
	int a ;
	cout<<"Enter a number to inverse and double the value:";
	cin>>a;
	
	cout<<inverse(a);


	return 0;
}

