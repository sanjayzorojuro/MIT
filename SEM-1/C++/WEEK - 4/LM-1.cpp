#include<iostream>
using namespace std;

class flight{
	private:
		int fno;
		string des;
		float dis,fuel;
		
		void cal_fuel(float dis){
			if (dis<= 1000){
				fuel = 500;
			}else if(dis>1000 and dis<=2000){
				fuel=1100;
			}else{
				fuel=2200;
			}
		}
		
		
	public:
		flight(){
			dis=500;
		}
		
		void info_entry(){
			cout<<"Enter the flight details accordingly flightno,destintion and distance:"<<endl;
			cin>>fno>>des>>dis;
			cal_fuel(dis);
			
		}
		void display(){
		
			cout<<"The flights details are:"<<endl<<"Flight no:"<<fno<<endl<<"Destination:"<<des<<endl<<"Distance:"<<dis<<"KM"<<endl<<"Total fuel required:"<<fuel<<"Ltr";
		}
		
};
int main(){
	flight f1;
	f1.info_entry();
	f1.display();
	return 0;
}
