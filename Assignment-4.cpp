//  Stephen McCormick
//  GPA Assignment 4
//  learn to use array and seach array data for information
//  Variable Dictionary
//  run  			string		if the program needs to run or not
//  first_name[8]	string		array that is filled with students first names
//  last_name[8]	string		array that is filled with students last names
//  search_again	string		used for if the user wants to enter a new target and search again
//  never_found		string		used as a switch for if the target was found or not
//  gpa[8]			double		array filled with students gpa score
//  student_id[8]	int			array that is filled with students ids
//  search_id		int			user input for the student id that is being search for
//  i				int			used as an incrimenter in the array search that trigers the stop of the search

#include<iostream>
#include<string>
using namespace std;

int student_id[8],search_id, i;
double gpa[8];
string run, first_name[8], last_name[8], search_again="y", never_found;

void load();
void search();
void found();
void not_found();

int main(){
	cout<<"Is this the program you want to run, y or n ";
	cin>>run;
	while(run!="y"&&run!="n"){
		cout<<"Input Error\nIs this the program you want to run, y or n ";
		cin>>run;
	}  //  end while
	while(run=="y"){
		load();
		search();

		cout<<"Do you want to run the program again? ";
		cin>>run;
		while(run!="y"&&run!="n"){
			cout<<"Input Error\nDo you want to run the program again? ";
			cin>>run;
		}  //  end while
	}  //  end while

system("pause");
return 0;
}  //  end main

void load(){
	for(i=0;i<=7;i=i+1){
		cout<<"Enter student ID: ";
		cin>>student_id[i];
		cout<<"Enter student First name: ";
		cin>>first_name[i];
		cout<<"Enter student Last name: ";
		cin>>last_name[i];
		cout<<"Enter student GPA: ";
		cin>>gpa[i];
		while(gpa[i]<0.00||gpa[i]>4.00){
			cout<<"the GPA for "<<first_name[i]<<" "<<last_name[i]<<" was not correct \n Enter Student GPA: ";
			cin>>gpa[i];
		}  //  end while
	}  //  end for
}  //  end load

void search(){
	while(search_again=="y"){
		cout<<"\n\nEnter the student id that you want to seach: ";
		cin>>search_id;
		for(i=0;i<=7;i=i+1){
			if(student_id[i]==search_id)
				found();
		}  //  end for
		
		if(never_found=="y")
			never_found="n";
		else
			not_found();

		cout<<"Do you want to seach again, y or n: ";
		cin>>search_again;
		while(search_again!="y"&&search_again!="n"){
			cout<<"Input Error\nDo you want to seach again, y or n: ";
			cin>>search_again;
		}  //  end while
	}  //  end while
}  //  end search

void found(){
	if(gpa[i]>3.65)
		cout<<first_name[i]<<" "<<last_name[i]<<" is on the Dean's list \n";
	if(gpa[i]<=3.65 && gpa[i]>=2.0)
		cout<<first_name[i]<<" "<<last_name[i]<<" is an average student \n";
	if(gpa[i]<2.0)
		cout<<first_name[i]<<" "<<last_name[i]<<" is on academic probation \n";
	
	never_found="y";
}  //  end found

void not_found(){
	cout<<"The student ID was not located \n";
}  //  end not found
