#include <iostream>
using namespace std;

class complex{
	private:
		int img,real;
	public:
		complex(){
			real = 0;
			img = 0;
		}
		complex(int r,int i){
			real = r;
			img = i;
		}
		complex operator + (complex c){
			complex temp;
			temp.real = real+c.real;
			temp.img = img + c.img;
			return temp;
		}
		complex operator - (complex c){
			complex temp;
			temp.real = real - c.real;
			temp.img = img - c.img;
			return temp;
		}
		void display(){
			
			cout<<real;
			if(img >0)
				cout<<" + " <<img<<"i";
			else
				cout<<" "<<img<<"i";
			cout<<endl;
		}
	};
int main(){
	
	complex c1(2,4);
	complex c2(3,5);
	complex c3,c4;
	
	c3 = c1+c2;
	c3.display();
	
	c4 = c1-c2;
	c4.display();	
	return 0;
}

