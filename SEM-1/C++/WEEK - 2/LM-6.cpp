#include <iostream>
using namespace std;

int main(){

	float bill,paid,bal;
	cout<<"Enter the total bill cash paid:";
	cin>>bill>>paid;

	bal=paid-bill;
	
	int note500=0,note200=0,note100=0,note50=0,note20=0,note10=0,coins=0;
	if(bal > 500){
		for (int i=1;i<bal;i+=500){
			note500 +=1;
			bal-=500;
		}
	}if(bal > 200){
		for (int i=1;i<bal;i+=200){
			note200 +=1;
			bal -= 200;
		}	
	}if(bal >100){
		for (int i=1;i<bal;i+=100){
			note100 +=1;
			bal -= 100;
		}
	}if(bal >50){
		for(int i=1;i<bal;i+=50){
			note50 +=1;
			bal -=50;
		}
	}if(bal >20){
		for(int i=1;i<bal;i+=20){
			note20+=1;
			bal-=20;
		}
	}if(bal >10){
		for (int i=1;i<bal;i+=10){
			note10+=1;
			bal-=10;
		}
	}else{
		coins += bal;
	}
	
	if(note500||note200||note100||note50||note20||note10||coins >=1){
		cout <<"Total payable:"<<"\n500:"<<note500<<"\n200:"<<note200<<"\n100:"<<note100<<"\n50:"<<note50<<"\n20:"<<note20<<"\n10:"<<note10<<"\ncoins:"<<coins;
	}else{
		cout<<"No amount to be paid.";
	}
	return 0;
}
