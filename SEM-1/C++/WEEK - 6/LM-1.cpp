#include <iostream>
using namespace std;

class mystring{
	private:
		char str[100];
	public:
		void getstring(){
			cout<<" Enter string:";
			cin>>str;
		}
		
		bool operator <= (mystring s){
			int i=0;
			while( str[i] != '\0' && s.str[i] != '\0'){
				if(str[i] < s.str[i])
					return true;
				if(str[i] < s.str[i])
					return false;
				i++;
			}
			//both strings are equal
			if(str[i] == '\0' && s.str[i] == '\0')
				return true;
					
			//first string ended first
			if(str[i] == '\0')
				return true;
			return false;
		}
		
		void display(){
			cout<<str;
		}
	};

int main(){
	mystring s1,s2;
	
	cout<<"\n Enter first string:"<<endl;
	s1.getstring();
	cout<<"\nEnter second string:"<<endl;
	s2.getstring();
	
	if(s1 <= s2){
		cout<<"\n First string is less than or equal to second string."<<endl;
	}
	else{
		cout<<" First string is greater than second string.";
	}
	return 0;
}

