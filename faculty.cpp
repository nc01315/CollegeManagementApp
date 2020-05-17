//filename: faculty.cpp
// Author: David Chen
// This program intialize all the member functions and data members for Faculty Class 

#include <iostream>
#include <string>
#include "faculty.h"

using namespace std;

Faculty::Faculty()
{
//default constructor to initiate class member data
	name="";  //Faculty's name
	mNumber=0;   //Faculty's M number
	email ="";//Faculty's email address
	depart=""; //Faculty's department 
	tenured=0; //Faculty's tenure status
}

Faculty::Faculty(string n,int id,string e,string d,int t)
//constructor:setter method
{
	name=n;			//set Faculty's name
	mNumber=id;		//set Faculty's M number
	email=e;		//set Faculty's email address
	depart=d;		//set Faculty's depart
	tenured=t;		//set Faculty's tenure status
}

string Faculty::print()
{
//Print out Faculty's name,M number,Email,Department,Tenured status information
	string s1;
	string status;

	if ((*this).tenured==1)
		status="yes";
	else
		status="no";
	
	string str = to_string((*this).mNumber);
	
	s1="Faculty: \n\t Full Name: \t "+ (*this).name+"\n\t M Number: \t "+str+"\n\t Email Addr: \t "+(*this).email+"\n\t Department: \t "+(*this).depart+"\n\t Tenured: \t "+status+"\n";

	return s1;
}



int Faculty::getTenured() // getter method,get Faculty's tenure status
{
	return (*this).tenured;
}


string Faculty::getDepart() // getter method,get Faculty's department
{
	return (*this).depart;
}



void Faculty::setTenured(int myTenured)// set Faculty's Tenure status
{
	tenured=myTenured;
}

void Faculty::setDepart(string myDepart)  // set Faculty's departmnet
{
	depart=myDepart;
}