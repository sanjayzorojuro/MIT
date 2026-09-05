#include<iostream>
using namespace std;
#include<vector>
class player{
	private:
		int code, matchplayed, runs, notout;
    	string name;
    	float avgruns;
		
	public:
    	player() {
        	code = 0;
        	matchplayed = 0;
        	runs = 0;
        	notout = 0;
        	name = "";
        	avgruns = 0.0;
    	}
				
		void getinfo(){
			cout<<"Enter the cricketer details:"<<endl;
			cout<<"Enter the player code:";
			cin>>code;
			cout<<"Enter the name of the player:'";
			cin>>name;
			cout<<"Enter the total matches played by the player:";
			cin>>matchplayed;
			cout<<"Enter the total runs of the player:";
			cin>>runs;
			cout<<"Enter number of times the player was not out:";
			cin>>notout;
		}
		void avg_runs(int runs,int matchplayed){
			if(matchplayed ==0){
				cout<<"cannot be calculated";
				return;
			
			avgruns =(float) runs/matchplayed;
			cout << "Player: "<<name<<"Average Runs: "<<avgruns<<endl;
		}
		
		void avg_runs(int code,int runs,int matchplayed){
			if(matchplayed ==0){
				cout<<"cannot be calculated.";
				return;
			}
			avgruns = (float)runs/matchplayed;
			cout << "Player: "<<name<<"Average Runs: "<<avgruns<<endl;
		}
		void display(){
			cout<<"\nPlayer Code:"<<code<<endl;
        	cout<<"Name: "<<name<<endl;
        	cout<<"Matchesplayed: "<<matchplayed<<endl;
        	cout<<"Runs: "<<runs<<endl;
       	 	cout<<"Not Out: "<<notout<<endl;
    	}
    	int getcode(){
    		return code;
    	}
    	int getruns(){
    		return runs;
    	}
		void display_sorted(vector <player> &plist){	
			int n = plist.size();
			for(int i=0;i<n-1;i++){
				for(int j=0;j<n-i-1;j++){
					if(plist[j].getruns()> plist[j+1].getruns()){
						player temp = plist[j];
						plist[j] = plist[j+1];
						plist[j+1] = temp;
					}
				}
			}
			cout<<"Players sorted as per runs:"<<endl;
			for(int i=0;i<n;i++){
				cout<<plist[i].display();
			}		
		
		}
	}
	};
	
int main(){
	vector <player> people;
		 
	int ch,n=0;
	cout<<"Cricket Players:"<<endl;
	cout<<"Enter 1 to add a player."<<endl;
	cout<<"Enter 2 to display average runs of single player."<<endl;
	cout<<"Enter 3 to display average runs of all players."<<endl;
	cout<<"Enter 4 to display the list of players sorted s per total runs."<<endl;


	while(true){
			cout<<"Enter your choice:";
			cin>>ch;
	   		switch(ch){
				case 1:{
					int count;
					cout<<"how many players do you want to enter:(max-10):";
					cin>>count;
					
					if(count<= 0 || count >10){
						cout<<"please enter valid number.";
						break;
					}
					people.resize(count);
					for(int i=0;i<count;i++){
						people[i].getinfo();
					}
					n = count;
					break;}
				case 2:{
					if(n ==0 ){
						cout<<"please enter player first.";
						break;
					}
					int search;
					cout<<"Enter player code:";
					cin>>search;
					bool found= false;
					
					for(auto& p : people){
						if(p.getcode() == search){
							p.avg_runs(p.getruns(),1);
							found=true;
							break;
						}
					}
					if(!found){
						cout<<"Player not found.'";
					}
					break;}
				case 3:{
					if(n == 0){
						cout<<"please neter player first.";
						break;
					}else{	
						for(auto& p:people){
							p.avg_runs(p.getcode(),p.getruns(),1);
						}
					}
					break;}
				case 4:{
					if(!people.empty()){
						people[0].display_sorted(people);
					}
					else{
						cout<<"Enter the players detail.";
					}
					break;
				}
				case 5:{
					cout<<"Exiting program..";
					return 0;}
			}
		}
	return 0;
	}

					
					
					
					
						
	
