/* convert the temperature into clecius to fahranehit and viceversa */
#include <iostream>
using namespace std;

int main(){
	
	float c,f,temp1,temp2;
	
	cout << "Enter temperature in fahranehit to convert into celcius:"<<endl;
	cin >> temp1;
	
	c = (5.0/9.0)*(temp1 - 32);    /* note that while dividing 5/9 since c++ does integer division it will be zero so mek it 5.0/9.0 which will be converted into float*/
	
	cout << "The temperature in celcius is:"<<c<<endl;
	
	cout<<"Enter temperature in celcius to convert to fahranehit:"<<endl;
	cin >> temp2;
	
	f = (9.0/5.0)* temp2 +32;
	
	cout << "The temperture in fahranehit is:"<<f<<endl;
	
	
	return 0;
	
}
