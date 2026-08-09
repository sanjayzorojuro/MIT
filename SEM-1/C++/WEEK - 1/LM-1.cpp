/* exhange of two variable whithout using temporary variable*/
#include <iostream>
using namespace std;

int main(){

	int a,b;
	
	cout << "Enter two numbers:"<<endl;
	cin >> a >> b;
	
	a = a + b;
	b = a - b;
	a = a - b;
	
	cout << "after swapping :"<<endl;
	cout << "value of a is:"<<a<<" ...value of b is:"<<b<<endl;
	
	return 0;
		 
}
