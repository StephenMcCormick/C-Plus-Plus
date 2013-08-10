//  Stephen McCormick
//  Payroll Assignment 5
//  use binary search to find people that rate overtime pay
//  Variable Dictionary
//  run  			string		if the program needs to run or not
//  first_name[8]	string		hold the fist names in an array
//  last_name[8]	string		hold the last names in an array
//  match			string		used as a trigger in the seach
//  id[8]			int			hold the ids in an array
//  hours[8]		int			hold the hours worked in an array
//  search_id		int			input from user for id to search for
//  i				int			used as accumulator for changing array value
//  rowmin			int			used as search reference for low end
//  rowmax			int			used as search reference for high end
//  row				int			used as search reference for middle
//  overtime		int			holds hours worked in overtime status
//  pay_rate[8]		double		hold the rate of pay in an array
//  overtime_pay	double		holds any overtime pay that is calculated
//  half			double		holds half of pay for time over 40

#include<iostream>
#include<string>
using namespace std;

int id[8], hours[8], search_id, i, rowmin, rowmax, row, overtime;
string last_name[8], first_name[8], run, match;
double pay_rate[8], overtime_pay, half;

void input();
void search();
void process();

int main(){
	cout<<"Is this the program you want to run, y or n ";
	cin>>run;
	while(run!="y"&&run!="n"){
		cout<<"Input Error\nIs this the program you want to run, y or n ";
		cin>>run;
	}  //  end while
	while(run=="y"){
		input();
		search();
	}  //  end while

system("pause");
return 0;
}  //  end main

void input(){
	cout<<"Employees must be entered in numarical order based on ID"<<endl;
	for(i=0;i<=7;i++){
		cout<<endl<<"Enter employee ID: ";
		cin>>id[i];
		cout<<"Enter employee Last name: ";
		cin>>last_name[i];
		cout<<"Enter employee First name: ";
		cin>>first_name[i];
		cout<<"Enter employee rate of pay: ";
		cin>>pay_rate[i];
		cout<<"Enter employee hours worked: ";
		cin>>hours[i];
	}  //  end for
}  //  end input

void search(){
	while(run=="y"){
		cout<<endl<<"Enter the employee ID you want to search for: ";
		cin>>search_id;

		match="n";
		rowmin=0;
		rowmax=7;

		while(match=="n"&&rowmin<=rowmax){
			row=int((rowmin+rowmax)/2);
			if(search_id<id[row]){
				rowmax=row-1;
			}  //  end if
			else{
				if(search_id>id[row]){
					rowmin=row+1;
				}  //  end if
				else{
					match="y";
				}  //  end else
			}  //  end else
		}  //  end while

		if(match=="y"){
			process();
		}  //  end if
		else{
			cout<<"The employee ID was not located";
		}  //  end else
	
		cout<<endl<<endl<<"Would you like to search again, y or n: ";
		cin>>run;
		while(run!="y"&&run!="n"){
			cout<<"Input Error\nWould you like to search again, y or n ";
			cin>>run;
		}  //  end while
	}  //  end while
}  //  end search

void process(){
	if(hours[row]>40){
		half=(pay_rate[row]/2);  //  finds half of rate of pay
		overtime=(hours[row]-40); //  hours worked in overtime
		overtime_pay=((pay_rate[row]+half)*overtime);  //  $ made in overtime
		cout<<first_name[row]<<" "<<last_name[row]<<" has worked "<<overtime<<" hours of overtime and is eligible for $"<<overtime_pay<<" overtime pay."<<endl;
	}
	else
		cout<<first_name[row]<<" "<<last_name[row]<<" is not eligible for overtime pay."<<endl;
}  //  end process
