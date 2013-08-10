//  Stephen McCormick
//  Grades Assignment 3
//  sequential dick fileing of grades then calculate what students received what grade
//  Variable Dictionary
//  run  			string		if the program needs to run or not
//  first_name		string		holds students first name
//  last_name		string		holds students last name
//  grade			string		will be filled with a letter grade based on score
//  create_file		string		if the user needs to create a file or not
//  score			int			holds the students score
//  total_students	int			accumulator for total students
//  total_a			int			accumulator for total A grades
//  total_b			int			accumulator for total B grades
//  total_c			int			accumulator for total C grades
//  total_d			int			accumulator for total D grades
//  total_f			int			accumulator for total F grades
//  average			double		the average score for the class
//

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

ofstream fout;
ifstream fin;

string run, first_name, last_name, grade, create_file;
int score, total_students, total_a, total_b, total_c, total_d, total_f; 
double average;

void setup();
void build();
void extract();
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
		setup();
		cout<<"Will you need to build the file, y or n: ";
		cin>>create_file;
		while(create_file!="y"&&create_file!="n"){
			cout<<"Input Error\nWill you need to build the file, y or n: ";
			cin>>create_file;
		}  //  end while
		if(create_file=="y"){
			build();
		}//  end if
		extract();
		totals();

		cout<<"Do you want to run the program again? ";
		cin>>run;
		while(run!="y"&&run!="n"){
			cout<<"Input Error\nDo you want to run the program again? ";
			cin>>run;
		}  //  end while
	}  //  end while

system("pause");
return 0;
}

void setup(){
	total_students=0;
	total_a=0;
	total_b=0;
	total_c=0;
	total_d=0;
	total_f=0;
	average=0;
	score=0;
}

void build(){
	fout.open("Z:\\class_grades_data.txt");

	while(run=="y"){
		cout<<"Enter student's first name: ";
		cin>>first_name;
		cout<<"Enter student's last name: ";
		cin>>last_name;
		cout<<"Enter student's test score: ";
		cin>>score;
		while(score<0||score>100){
			cout<<"test score is not correct, re-enter test score";
			cin>>score;
		}  //  end while

		fout<<first_name<<" "<<last_name<<" "<<score<<" ";

		cout<<"Is there another record, y or n ";
		cin>>run;
		while(run!="y"&&run!="n"){
			cout<<"Input Error\nIs there another record, y or n ";
			cin>>run;
		}  //  end while
	}  //  end while

	fout.close();
}

void extract(){
	fin.open("Z:\\class_grades_data.txt");

	fin>>first_name>>last_name>>score;

	while(!fin.eof()){
		average+=score;
		total_students++;
		process();
		cout<<first_name<<"\t"<<last_name<<"\t\t"<<grade<<endl;
		fin>>first_name>>last_name>>score;
	}  //  end while

	fin.close();
}

void process(){
	if(score<=100&&score>=90){
		grade="A";
		total_a++;
	}  //  end if
	if(score<=89&&score>=80){
		grade="B";
		total_b++;
	}  //  end if
	if(score<=79&&score>=70){
		grade="C";
		total_c++;
	}  //  end if
	if(score<=69&&score>=60){
		grade="D";
		total_d++;
	}  //  end if
	if(score<60){
		grade="F";
		total_f++;
	}  //  end if
}

void totals(){
	average=(average/total_students);
	cout<<"Total students processed: "<<total_students<<endl;
	cout<<"Total students receiving an A: "<<total_a<<endl;
	cout<<"Total students receiving an B: "<<total_b<<endl;
	cout<<"Total students receiving an C: "<<total_c<<endl;
	cout<<"Total students receiving an D: "<<total_d<<endl;
	cout<<"Total students receiving an f: "<<total_f<<endl;
	cout<<"Average score for class: "<<average<<endl;
}
