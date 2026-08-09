/* area of circle and trinagle*/
#include <iostream>
using namespace std;

int main(){

	int areacircle,areatriangle,r,b,h;
	
	cout << "Enter the radius of the circle:"<<endl;
	cin >>r;
	
	cout<<endl;
	
	cout << "Enter breadth and height of the triangle:"<<endl;
	cin >>b>>h;
	
	cout<<endl;
	
	areacircle = 3.14*r*r;
	areatriangle = 0.5*b*h;
	
	cout<<endl;
	cout << "The area of the circle is:"<<areacircle<<endl;
	cout<< " the area of the triangle is :"<<areatriangle;
	
	return 0;
	
		

	
}
