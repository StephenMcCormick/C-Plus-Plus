//  Stephen McCormick
//  Airline Assignment 2
//  Sequential disk file
//  Variable Dictionary
//  flight  	int		holds the flight number
//	passengers	int		holds the number of passengers on the flight
//  origin		string	location the flight took off from
//  destination	string	location the flight landed
//  code		string	holds the flight code
//  run			string	input for if program should run and if program sould run again

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

ofstream fout;
ifstream fin;

int flight, passengers;
string origin, destination, code, run;

void creat();
void extract();

int main(){
	cout<<"Is this the program you want to run, y or n ";
	cin>>run;
	while(run!="y"&&run!="n"){
		cout<<"Input Error\nIs this the program you want to run, y or n ";
		cin>>run;
	}  //  end while
	while(run=="y"){
		creat();
		extract();
	}  //  end while

system("pause");
return 0;
}

void creat(){
	fout.open("Z:\\airline_data.txt");

	while(run=="y"){
		cout<<"enter flight number: ";
		cin>>flight;
		cout<<"Enter flight origin: ";
		cin>>origin;
		cout<<"Enter flight destination: ";
		cin>>destination;
		cout<<"Enter number of passangers: ";
		cin>>passengers;
		cout<<"Enter flight code: ";
		cin>>code;

		fout<<flight<<" "<<origin<<" "<<destination<<" "<<passengers<<" "<<code<<" ";

		cout<<"Is there another record, y or n ";
		cin>>run;
		while(run!="y"&&run!="n"){
			cout<<"Input Error\nIs there another record, y or n ";
			cin>>run;
		}  //  end while
	}

	fout.close();
}

void extract(){
	fin.open("Z:\\airline_data.txt");

	fin>>flight>>origin>>destination>>passengers>>code;

	while(!fin.eof()){
		cout<<flight<<" "<<origin<<" "<<destination<<" "<<passengers<<" "<<code<<" "<<endl;
		fin>>flight>>origin>>destination>>passengers>>code;
	}

	fin.close();
}
