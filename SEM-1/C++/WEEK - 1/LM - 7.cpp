// programe to calculate compound intrest

#include <iostream>
#include <cmath>
using namespace std;

int main(){

	float a,p,r,n,t,ci;
	
	cout << "Enter principle amount , rate of intrest, time period ,number of time to be compounded :"<<endl;
	cin >> p>>r>>t>>n;	
	
	a = p *pow((1+ (r / (100*n))),n*t);
	
	ci = a-p;
	
	cout << "The compound intrest is:"<<ci<<endl;
	
	return 0;
}

