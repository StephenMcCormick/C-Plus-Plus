//  Stephen McCormick
//  Travel Agency  Assignment 6
//  Take data and sort it for output
//  Variable dictionary
//  string		airline_name[6]		array to hold airline's names
//  string		destination[6]		array to hold airline's destination
//  string		swapping			y on n if swapping happened
//  string		duplicate[6]		array used in sorting so data is not ruined
//  int			airline_number[6]	array to hold airline's flight number
//  int			passenger[6]		array to hold airline's passenger number
//  int			i					incrimenter for filling array
//  int			pass_min			holds the minimum number of passengers to fly
//  int			pass_max			holds the maximum number of passengers to fly
//	int			total_pass			accumulator for total number of passengers flying
//  int			index[6]			array used in sorting

#include<iostream>
#include<string>
using namespace std;

string airline_name[6], destination[6], swapping, duplicate[6], hold;
int airline_number[6], passenger[6], i, pass_min, pass_max, total_pass, index[6], hold_num;

void setup();
void input();
void display_airline();
void display_destination();
void sort_data();

int main(){

	setup();
	input();
	display_airline();
	display_destination();
	
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
		cout<<"Charter Number --> "<<i+1<<endl;
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

		total_pass=total_pass+passenger[i];

	}  //  end for
}  //  end input

void display_airline(){
	cout<<"\n\t\t ABC TRAVEL AGENCY \n";
	cout<<"\t CHARTER PASSENGER LOAD REPORT \n";
	cout<<"Airline Name \t Flight Number \t Destination \t Passenger Load \n";

	for(i=0;i<=5;i++){
		duplicate[i]=airline_name[i];
	}  //  end for

	sort_data();

	for(i=0;i<=5;i++){
		cout<<airline_name[index[i]]<<"\t\t"<<airline_number[index[i]]<<"\t\t"<<destination[index[i]]<<"\t\t"<<passenger[index[i]]<<endl;
	}  //  end for
	cout<<"End of Passenger Report"<<endl;
}  //  end display_airline

void display_destination(){
	cout<<"\n\t\t ABC TRAVEL AGENCY \n";
	cout<<"\t CHARTER PASSENGER LOAD REPORT \n";
	cout<<"Airline Name \t Flight Number \t Destination \t Passenger Load \n";

	for(i=0;i<=5;i++){
		duplicate[i]=destination[i];
	}  //  end for

	sort_data();

	for(i=0;i<=5;i++){
		cout<<airline_name[index[i]]<<"\t\t"<<airline_number[index[i]]<<"\t\t"<<destination[index[i]]<<"\t\t"<<passenger[index[i]]<<endl;
	}  //  end for
	cout<<"Total Passengers: "<<total_pass<<endl;
	cout<<"End of Passenger Report"<<endl<<endl;
}  //  end display_destination

void sort_data(){
	for(i=0;i<=5;i++){
		index[i]=i;
	}  //  end for

	swapping="y";
	while(swapping=="y"){
		swapping="n";
		for(i=0;i<=4;i++){
			if(duplicate[i]>duplicate[i+1]){
				swap(duplicate[i], duplicate[i+1]);
				swap(index[i], index[i+1]);

				/*hold=duplicate[i];   --this code will work for swapping data--
				duplicate[i]=duplicate[i+1];
				duplicate[i+1]=hold;
				hold_num=index[i];
				index[i]=index[i+1];
				index[i+1]=hold_num;*/

				swapping="y";

					/*for(i=0;i<=4;i++){
						cout<<index[i]<<"  "<<duplicate[i]<<"  "<<index[i+1]<<"  "<<duplicate[i+1]<<endl;
					}  //  end for
					system("pause");  --this is the code i used to find that it was duplicating a number to compensate for "i + 1" when i = 5--*/

			}  // end if
		}  //  end for
	}  //  end while
}  //  end sort_data
