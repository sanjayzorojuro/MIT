#include <iostream>
using namespace std;
#include<algorithm>


string pali(string s){
	string var = s;
	reverse(var.begin(),var.end());
	if(s == var)
		return "Palindrome";
	else
		return "not a palindrome";
	
}

int main(){
	
	string var;
	cout<<"Enter a string to check for palindrome:";
	cin>>var;
	
	cout<<"The string is "<<pali(var);
	
	return 0;
	
}
	
