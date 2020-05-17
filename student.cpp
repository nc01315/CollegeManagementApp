//filename: student.cpp
// Author: David Chen
// This program intialize all the member functions and data members for Student Class 

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student()
{
//default constructor to initiate class member data
	name="";  //Student's name
	mNumber=0;   //Student's M number
	email="";   //Student's email address
	grade=0;	// year in school
	major="";	//Student's major
}

Student::Student(string n,int id,string e,int g,string m)		
//constructor:setter method
{
	name=n;			//set Student's name
	mNumber=id;		//set Student's M number
	email=e;		//set Student's email address
	grade=g;		//set year in school
	major=m;		//set Student's major
}

string Student::print()// *** polymorphic method ***
{
//Print out Student's name,M number,Email,Year(0-3),Major  information
	string s2;
	
	string sGrade;
	

	if((*this).grade==0)
		sGrade="Freshmen";
	else if ((*this).grade==1)
		sGrade="Sophomore";
	else if ((*this).grade==2)
		sGrade="Junior";
	else if ((*this).grade==3)
		sGrade="Senior";
	
	string str = to_string((*this).mNumber);
	
	s2="Student: \n\t Full Name: \t " + (*this).name + "\n\t M Number: \t " + str + "\n\t Email Addr: \t " + (*this).email+ "\n\t Grade: \t " + sGrade + "\n\t Major: \t " + (*this).major + "\n";
	return s2;
}



int Student::getGrade() // getter method,get Student's grade
{
	return (*this).grade;
}


string Student::getMajor() // getter method,get Student's major
{
	return (*this).major;
}

//setter

void Student::setGrade(int myGrade) // getter method,get Student's grdae
{
	grade=myGrade;
}

void Student::setMajor(string myMajor) // setter method,set Student's major
{
	major=myMajor;
}


