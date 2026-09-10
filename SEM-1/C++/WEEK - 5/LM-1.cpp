#include <iostream>
using namespace std;

class matrix{
	private:
		int a[10][10];
		int rows,col;
	public:
		void getmatrix(){
			cout<<"Enter no of rows:";
			cin>>rows;
			
			cout<<"\nEnter number of col:";
			cin>>col;
			
			cout<<"\nEnter matrix elements:";
			
			for(int i=0;i<rows;i++){
				for(int j=0;j<col;j++){
					cin>>a[i][j];
				}
			}
		}
		
		void display(){
			for(int i=0;i<rows;i++){
				for(int j=0;j<col;j++){
					cout<<a[i][j];
				}
				cout<<endl;
			}
		}
		
		int operator ==(matrix m){
			if(rows == m.rows && col == m.col)
				return 1;
			else
				return 0;
		}
		
		matrix operator +(matrix m){
			matrix temp;
			temp.rows = rows;
			temp.col = col;
			
			for(int i=0;i<rows;i++){
				for(int j=0;j<col;j++){
					temp.a[i][j] = a[i][j] + m.a[i][j];
				}
			}
			return temp;	
		}
		matrix operator -(matrix m){
			matrix temp;
			temp.rows = rows;
			temp.col = col;
			
			for(int i=0;i<rows;i++){
				for(int j=0;j<col;j++){
					temp.a[i][j] = a[i][j] - m.a[i][j];
				}
			}
			return temp;
		}
};

int main(){
	matrix m1,m2,m3,m4;
	
	cout<<"Enter details of matrix 1:"<<endl;
	m1.getmatrix();
	
	cout<<"\nEnter details of matrix 2:"<<endl;
	m2.getmatrix();
	
	if(m1 == m2){
		m3 = m1+m2;
		m4 = m1-m2;
		
		cout<<"\n Matrix 1:"<<endl;
		
		m1.display();
		
		cout<<"\n Matrix 2:"<<endl;
		m2.display();
		
		cout<<"\n Matrix Addition:"<<endl;
		m3.display();
		
		cout<<"\n Matrix Substraction:"<<endl;
		m4.display();
	}
	else{
		cout<<"Matrix are not compatible:";
	}
	return 0;
}
		
