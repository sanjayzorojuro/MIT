//check for cube of a number using inline function.
#include <iostream>
using namespace std;

inline int cube(int n){
	return n*n*n;
}

int main(){
	
	int n;
	cout<<"Enter a number to chcek for cube:";	
	cin>>n;
	
	cout<<"cube of the number is:"<<cube(n);
	
	
	return 0;
	
}

