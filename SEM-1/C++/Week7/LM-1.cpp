#include <iostream>
using namespace std;

class person{
	protected: 
		int id;
		string name;
		
	public:
		getname(){
			cout<<"Enter id:";
			cin>>id;
			
			cout<<"\nEnter name:";
			cin>>name;
		}
		
		void display(){
			cout<<"\nId is :"<<id<<" And name is :"<<name;
		}
};

class teaching : public person{
	private:
		string subject;
	public:
		void getteach(){
			cout<<"\n\nEnter subject:";
			cin>>subject;
		}
		void display(){
			person::display();
			cout<<"\nSubject:"<<subject;
			
		}
	};
	
class nonteaching : public person{
	private:
		string dept;
	public:
		void getdata(){
			cout<<"\n\nEnter dept name:";
			cin>>dept;
		}
		void display(){
			person::display();
			cout<<"\nDepartmanet is:"<<dept;
		}
	};
		
class instuctor: public person{
	public:
		void display(){
			person::display();
		}
	};
	
		
	int main(){
		
		person p1;
		p1.getname();
		p1.display();
		teaching t1;
		t1.getteach();
		t1.display();
		nonteaching n1;
		n1.getdata();
		n1.display();
		instuctor i1;
		i1.display();
		
		return 0;
	}
		
		
			
	
		
