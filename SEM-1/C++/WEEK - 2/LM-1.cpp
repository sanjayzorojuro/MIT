#include <iostream>
using namespace std;

int main(){
	
	int n=0;
	for(int i=4;i>n;i--){
		for(int j = 0 ; j< i;j++){
			cout << "*";
		}cout <<endl;
			
	}
	cout <<endl;
	for(int a=69;a>65;a--){
		for (int b= 65;b< a ;b++){
			cout << char(b);
		}cout << endl;
 	}
	
	cout <<endl;
	
	int m=3,val=1;
	for(int c=1;c<=m;c++){
		for (int d=1;d<=c;d++){
			cout<<val++;
		}cout << endl;
	}
	
	
	return 0;
	
}
