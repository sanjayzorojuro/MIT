#include <iostream>
using namespace std;

int prime(int a[],int n){
	bool isprime = false;
	int range = n;
	int itsprime = 0;

	for(int i=1 ; i<=range ;i++){
		int count = 0;
		for(int j=1;j<=i;j++){
			if(i%j == 0){
				count++;
			}
		}
		if(count == 2){
			itsprime++;	
		}
	}
	return itsprime;
}
		

int main(){
	int a[] = {};
	int n;
	
	cout<<"Enter the n elements:";
	cin>>n;
	
//	for(int i=0;i<n;i++){
//		cout<<"enter array elements:"<<endl;
//		cin>>a[i];
//	}
	
	
	cout<<"The total prime numbers in the array is:"<<prime(a,n);
	
}

