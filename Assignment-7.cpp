//  Stephen McCormick
//  Registrar Assignment 7
//  interactive menu to alpha the data and use menu to display data
//  Variable dictionary
//  int			index[6]		holds the index for arrays in the sorting
//  int			students[6]		holds the number of students in a class
//  int			max_students	holds the max number of students aloud in a class
//  int			i				index
//  int			select			used to select the menu item
//  int			total_students	accumulate the total number of students
//  string		duplicate[6]	holds array data so it can be sorted
//  string		class_name[6]	array for class names
//  string		instructor_name[6]  array for instructors names
//  string		create			hold answer for creating a file or not
//  string		swapping		used in the sorting function
//  string		search_item		user input to search
//  string		match			if user input if found or not

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

ofstream fout;
ifstream fin;

int index[6], students[6], max_students, i, select, total_students;
string duplicate[6], class_name[6], instructor_name[6], create, swapping, search_item, match;

void setup();
void build_file();
void menu();
void load_file();
void by_name();
void by_instructor();
void search();
void sort();
void found();
void not_found();

int main(){
	setup();

	cout<<"Is the data avalible in a file already, y or n? ";
	cin>>create;
	while(create!="y" && create!="n"){
		cout<<"Error"<<endl<<"Re-enter, y or n: ";
		cin>>create;
	}  //  end while

	if(create=="n")
		build_file();

	menu();

	while(select!=5){
		switch (select){
			case 1:
				load_file();
				break;
			case 2:
				by_name();
				break;
			case 3:
				by_instructor();
				break;
			case 4:
				search();
				break;
		}  //  end switch

		menu();

	}  //  end while

system("pause");
return 0;
}  //  end main

void setup(){
	max_students=25;
	select=0;
	total_students=0;
	swapping="y";
}  //  end setup

void build_file(){
	fout.open("Z:\\C++\\Registrar\\school.dat");
	
	for(i=0;i<6;i++){
		cout<<"Enter the class name: ";
		cin>>class_name[i];
		cout<<"Enter the instructor's name: ";
		cin>>instructor_name[i];
		cout<<"Enter the number of students in the class: ";
		cin>>students[i];

		while(students[i]>max_students){
			cout<<"There are too many students in that class"<<endl;
			cout<<"Enter the number of students in the class: ";
			cin>>students[i];
		}  //  end while

		fout<<class_name[i]<<" "<<instructor_name[i]<<" "<<students[i]<<" ";
	}  //  end for

	fout.close();
}  //  end build_file

void menu(){
	system("cls");

	cout<<"\t\t CLASS MENU \n\n";
	cout<<"Code \t Function \n";
	cout<<"1 \t Load data to process \n";
	cout<<"2 \t List classes by name \n";
	cout<<"3 \t List classes by Instructor \n";
	cout<<"4 \t obtain instructor name and enrollment \n";
	cout<<"5 \t Exit \n";
	cin>>select;

	while(select<1 || select>5){
		cout<<"Not a valid selection \n";
		cout<<"Re enter: ";
		cin>>select;
	}  //  end while

}  //  end menu

void load_file(){
	fin.open("Z:\\C++\\Registrar\\school.dat");

	for(i=0;i<6;i++){
		fin>>class_name[i]>>instructor_name[i]>>students[i];
	}  //  end for

	cout<<"\n\n\n Load Complete \n\n";

system("pause");
}  //  end load_file

void by_name(){
	cout<<"\t ALPHABETICAL CLASS LISTING BY CLASS NAME \n";
	cout<<"class name \t instructor \t enrollment \n";

	for(i=0;i<6;i++){
		duplicate[i]=class_name[i];
	}  //  end for

	sort();

	for(i=0;i<6;i++){
		cout<<class_name[index[i]]<<"\t\t"<<instructor_name[index[i]]<<"\t\t"<<students[index[i]]<<endl;
		total_students=total_students+students[i];
	}  //  end for

	cout<<endl<<"Total enrollment: "<<total_students<<endl;

	system("pause");
}  //  end by_name

void by_instructor(){
	cout<<"\t ALPHABETICAL CLASS LISTING BY INSTRUCTOR NAME \n";
	cout<<"instructor \t class name \t enrollment \n";

	for(i=0;i<6;i++){
		duplicate[i]=instructor_name[i];
	}  //  end for

	sort();

	for(i=0;i<6;i++){
		cout<<instructor_name[index[i]]<<"\t\t"<<class_name[index[i]]<<"\t\t"<<students[index[i]]<<endl;
	}  //  end for

	system("pause");
}  //  end by_instructor

void sort(){
	for(i=0;i<6;i++){
		index[i]=i;
	}  //  end for

	swapping="y";
	while(swapping=="y"){
		swapping="n";
		for(i=0;i<5;i++){
			if(duplicate[i]>duplicate[i+1]){
				swap(duplicate[i], duplicate[i+1]);
				swap(index[i], index[i+1]);
				swapping="y";
			}  //  end if
		}  //  end for
	}  //  end while
}  //  end sort

void search(){
	cout<<"\nSearch for instructor and enrollment by class name";
	cout<<"\nPlease enter class name: ";
	cin>>search_item;

	match="n";
	i=0;
	while(match=="n" && i<6){
		if(search_item==class_name[i])
			match="y";
		else
			i++;
	}  //  end while

	if(match=="y")
		found();
	else
		not_found();

}  //  end search

void found(){
	cout<<"The instructor for class "<<class_name[i]<<" is "<<instructor_name[i]<<" and there are "<<students[i]<<" students enrolled.\n\n";

	system("pause");
}  //  end found

void not_found(){
	cout<<"Class "<<search_item<<" was not found.\n\n";

	system("pause");
}  //  end not_found
