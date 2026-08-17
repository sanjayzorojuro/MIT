//program to check if the number is cube or not.

#include <iostream>
using namespace std;

int main(){
	
	int num;
	cout<< "Enter number to check if its cube or not:";
	cin >> num;
	
	int val = num;
	int count=0;
	
	for (int i=1; i<=num;i++){
		if (i*i*i == val){
			count += 1;
			cout << num<<" is a perfect cube, cube root is "<<i;
			break;
		}	
	}
	
	if(count < 1)
		cout<< "Not a perfect cube.";
	return 0;
	
}
