//  Stephen McCormick
//  Club 2  Assinment 1
//  Determin dues for members and total dues for all members
//  Variable Dictionary
//  years  			  int		input for years of membership
//  dues				  int		filled with dues for member
//  total_family_dues	  int		accumulates all dues for all family members
//  total_individual_dues int		accumulates all dues for all individual members
//  family_more			  int		holds dues for family member with more than 6 years
//  family_less			  int		holds dues for family member with 6 or less years
//  individual_more		  int		holds dues for individual member with more than 6 years
//  individual_less		  int		holds dues for individual member with 6 or less years
//  total_members		  int		counts number of members being processed
//  first_name			  string	input for member first name
//  last_name			  string	input for member last name
//  type				  string	input for member type
//  run					  string	input for if program should run and if program sould run again

#include <iostream>
#include <string>
using namespace std;

int years=0, dues=0, total_family_dues=0, total_individual_dues=0, family_more, family_less, individual_more, individual_less, total_members=0;
string first_name, last_name, type, run;

void setup();
void input();
void process();
void totals();

int main(){
	cout<<"Is this the program you want to run, y or n ";
	cin>>run;
	while(run!="y"&&run!="n"){
		cout<<"Input Error\nIs this the program you want to run, y or n ";
		cin>>run;
	}  //  end while
	while(run=="y"){
		if(total_members==0)
			setup();
		input();
		process();
		cout<<"Do you want to enter another member , y or n ";
		cin>>run;
		while(run!="y"&&run!="n"){
			cout<<"Input Error\nDo you want to enter another member , y or n ";
			cin>>run;
		}  //  end while
	}  //  end while

	if(total_members!=0)
		totals();

system("pause");
return 0;
}  //end of main

void setup(){
	family_more=1200;
	family_less=1600;
	individual_more=800;
	individual_less=1100;
}

void input(){
	cout<<"Enter member's first name: ";
	cin>>first_name;
	cout<<"Enter member's last name: ";
	cin>>last_name;
	cout<<"Enter member's type, f for family i for individual: ";
	cin>>type;
	while(type!="f"&&type!="i"){
		cout<<"Input Error\nEnter member's type, f for family i for individual: ";
		cin>>type;
	}  //  end while
	cout<<"Enter number of years: ";
	cin>>years;
}

void process(){
	total_members++;
	if(type=="f"){
		type="Family";
		if(years>6)
			dues=family_more;
		else
			dues=family_less;
		total_family_dues+=dues;
	}  //  end if
	else{
		type="Individual";
		if(years>6)
			dues=individual_more;
		else
			dues=individual_less;
		total_individual_dues+=dues;
	}  //  end else
	cout<<first_name<<" "<<last_name<<" is a "<<type<<" and annual dues are "<<dues<<endl;
}

void totals(){
	cout<<"Total members processed: \t"<<total_members<<endl;
	cout<<"Total family membership dues: \t"<<total_family_dues<<endl;
	cout<<"Total individual membership dues: \t"<<total_individual_dues<<endl;
}
