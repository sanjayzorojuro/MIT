#include <iostream>
using namespace std;

int main(){

	int num;
	cout << "Enter a number to convert to binary:";
	cin >> num;
	
	int rem,val,place=1;
	
	while(num>0){
		rem = num%2;
		val = val+rem*place;
		place = place *10;
		num = num/2;
	}
	cout <<val;
	
	cout<<endl;
	int num2;
	cout << "Enter a binary number to convert to decimal:";
	cin >> num2;
	cout<<endl;
	
	int rem2,val2,place2=1;
	while(num2>0){
		rem2 = num2%10;
		val2 = val2+rem2*place2;
		place2 = place2*2;
		num2 = num2 /10; 
	}	
	cout<<val2;
	return 0;

}
