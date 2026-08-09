/* smallest of three number*/
#include <iostream>
using namespace std;

int main(){

	int a,b,c;
	cout <<"Enter three values for a,b,c:"<<endl;
	cin >>a>>b>>c;
	
	if(a<= b and a<=c){
		cout << "A is the smallest number.."<<endl;
	}else if( b<=a and b<=c){
		cout << "B is the smallest number."<<endl;
	}else{
		cout << "C is the smallest number."<<endl;
	}
	
	return 0;
}
