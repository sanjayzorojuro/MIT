#include<iostream>
using namespace std;

int swap(int &a ,int &b){
	int temp = a;
	a = b;
	b = temp;
}
float swap(float &a, float &b){
	float temp = a;
	a = b;
	b = temp;
}
string swap(string &a,string &b){
	string temp = a;
	a = b;
	b = temp;
}


int main(){

	int a,b;
	float c,d;
	string e,f;
	
	cout<<"Enter two integers number to swap:";
	cin>>a>>b;
	swap(a,b);
	cout<<"Elements after swapping:"<<a<<" "<<b;
	cout<<endl;
	
	cout<<"Enter two floating numbers to swap:";
	cin>>c>>d;
	swap(c,d);
	cout<<"Elements after swapping:"<<c<<" "<<d;
	cout<<endl;
	
	cout<<"Enter two charachter to swap:";
	cin>>e>>f;
	swap(e,f);
	cout<<"Charachters after swapping:"<<e<<" "<<f;

	return 0;
	
}
