//  student makes calculation 

#include <iostream>
using namespace std;

int main(){

	string name,grade;
	int regno,year,semno,m1,m2,m3,m4,m5;
	float avg,total;
	 
	cout<< "Enter student name:"<<endl;
	cin>> name;
	
	cout<< "Enter student joining year:"<<endl;
	cin >> year;
	
	cout<< "Enter student sem number:"<<endl;
	cin >> semno;
	
	cout<< "Enter student marks in five subjects:"<<endl;
	cin>>m1>>m2>>m3>>m4>>m5;
	
	total = m1+m2+m3+m4+m5;
	avg = total / 5.0;
	
	if(avg>=90){
		grade = "A";
	}else if(avg >80){
		grade = "B";
	}else if(avg >61){
		grade = "C";
	}else if(avg >51){
		grade = "D";
	}else if(avg >41){
		grade = "E";
	}else{
		grade = "F";
	}
	
	cout << "Name of the student is:"<<name<<endl;cout<<endl;
	cout << "Student joining year is:"<<year<<endl;cout<<endl;
	cout << "Sem of the student is:"<<semno<<endl;cout<<endl;
	cout << "Total marks of the student  is:"<<total<<endl;cout<<endl;
	cout << "Average of the student is:"<<avg<<endl;cout<<endl;
	cout << "Final grade of the student is:"<<grade<<endl;cout<<endl;
	
	return 0;
	
	
}

