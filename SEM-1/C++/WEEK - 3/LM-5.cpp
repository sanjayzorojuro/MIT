#include<iostream>
using namespace std;

struct emp{
	int empno;
	string empname;
	float basic,da,net,it;
};

void read(emp &e){
	cout<<"Enter the emp no,name,and basic:";
	cin>>e.empno>>e.empname>>e.basic;
}
void cal(emp &e){
	float gross;
	e.da = e.basic * 0.12f;
	gross = e.da+e.basic;
	e.it = gross *0.18f;
	e.net = gross - e.it;
}
void display(emp &e){
	cout<<"Employee number is:"<<e.empno<<endl;
	cout<<"Employee name is:"<<e.empname<<endl<<"Salary:"<<e.basic<<endl<<"DA:"<<e.da<<endl<<"IT:"<<e.it<<endl<<"Employee net salary is:"<<e.net;
}
int main(){
	emp e;
	read(e);
	cal(e);
	display(e);
	return 0;
}

