//  Stephen McCormick
//  Travel Agency  Assignment 6
//  Take data and sort it befor output
//  Variable dictionary
//  string  	airline_name[6]		array to hold airline's names
//  string		destination[6]		array to hold airline's destination
//  string		swapping			y on n if swapping happened
//  int			airline_number[6]	array to hold airline's flight number
//  int			passenger[6]		array to hold airline's passenger number
//  int			i					incrimenter when filling array
//  int			pass_min			holds the minimum number of passengers to fly
//  int			pass_max			holds the maximum number of passengers to fly
//	int			total_pass			accumulator for total number of passengers flying

#include<iostream>
#include<string>
using namespace std;

string airline_name[6], destination[6], swapping;
int airline_number[6], passenger[6], i, pass_min, pass_max, total_pass;

void setup();
void input();

int main(){

	setup();
	input();
	
system("pause");
return 0;
}  //  end main

void setup(){
	pass_min=50;
	pass_max=275;
	total_pass=0;
}  //  end setup

void input(){
	for(i=0;i<=5;i++){
		cout<<"Charter Number -->"<<i+1<<endl;
		cout<<"Enter airline name: ";
		cin>>airline_name[i];
		cout<<"Enter airline flight number: ";
		cin>>airline_number[i];
		cout<<"Enter destination: ";
		cin>>destination[i];
		cout<<"Enter number of passengers: ";
		cin>>passenger[i];

		while(passenger[i]<pass_min || passenger[i]>pass_max){
			cout<<"The number of passengers is "<<passenger[i]<<". This must be between "<<pass_min<<" and "<<pass_max<<" to fly."<<endl;
			cout<<"Re-enter number of passengers: ";
			cin>>passenger[i];
		}  //  end while

	}  //  end for
}  //  end input
