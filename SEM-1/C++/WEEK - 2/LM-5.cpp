#include <iostream>
using namespace std;

int main(){
	
	int start,end;
	cout<<"Enter first limit:";
	cin>>start;
	cout<<"Enter second limit:";
	cin>>end;
	
	bool isprime = false;
	
	for(int num=start; num<= end;num++){
		int count = 0;
		
		for (int i=1; i<=num;i++){
			if( num % i == 0){
				count++;
			}
		}
		if(count == 2)
			cout<<num<<'\t';
	}
	return 0;
}
