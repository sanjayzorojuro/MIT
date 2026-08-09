/* convert time in seconds to hours,min,sec */
#include <iostream>
using namespace std;

int main(){

	int s,hour,min,sec;
	
	cout <<"Enter the seconds you want to convert:"<<endl;
	cin >> s;
	
	hour= s / 3600;
	min = (s % 3600) / 60;
	sec = s % 60;
	
	cout <<"Total hour:"<<hour<<"....Total minutes:"<<min<<"....Total seconds:"<<sec;
	
	return 0;
	
}
