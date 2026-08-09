/* convert distance from mm to cm,feet,inches */

#include <iostream>
using namespace std;

int main(){

	int mm,cm,feet,inches;
	
	cout<<"Enter the millimeter you want to convert:"<<endl;
	cin >> mm;
	
	cm = mm / 10;
	feet = cm / 2.5;
	inches =  feet / 12;
	
	cout << "Total centimeter is:"<<cm<<"....Total feet is:"<<feet<<"....Total inches is:"<<inches;
	return 0;
	
	
	
}
