#include <iostream>
using namespace std;

class Date{

	int date,month,year;
	
public:
	Date(int d,int m,int y){
		date=d;
		month=m;
		year=y;
	}
	void display(){
		cout<<"\nThe year is:"<<year;
		cout<<"\nThe month is:"<<month;
		cout<<"\nThe date is:"<<date;
	}
	void operator ++();
};
void Date::operator ++(){
	date++;
	
	if((month == 2 && date >28) || ((month == 4 || month == 6 || month == 9 || month == 11) && date >30) || date > 31){
		date = 1;
		month++;
		
	}
	if(month > 12){
		month = 1;
		year++;
	}
}

int main(){

	int day,month,year;
	cout<<"Enter the current year:";
	cin>>year;
	cout<<"Enter the current month:";
	cin>>month;
	cout<<"Enter the current day:";
	cin>>day;
	
	Date d1(day,month,year);
	++d1;
	cout<<"\nThe Date after incrementing the date object  is:";
	d1.display();	
	return 0;
}

