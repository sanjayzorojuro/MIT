#include <iostream>
using namespace std;

int main(){

	int num;
	cout <<"Enter n fibonacci:";
	cin>>num;
	
	int count=0,f1=0,f2=1,f3;
	while(count < num){
		cout<<f1<<"\t";
		f3=f1+f2;
		f1=f2;
		f2=f3;
		count++;
	}
	return 0;

}
