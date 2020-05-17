//filename: administrator.cpp
// Author: David Chen
// This program intialize all the member functions and data members for administrator Class 

#include <iostream>
#include <string>
#include "administrator.h"


using namespace std;

Administrator::Administrator() : Person() 
{
//default constructor to initiate class member data
	name="";  	//Administrator's name
	mNumber=0;   //Administrator's M number
	email="";   //Administrator's email address
	title="";	//Administrator's title
}

Administrator::Administrator(string n,int id,string e, string t): Person(n,id,e)
 //user defined constructor 
{
	this->setName(n);		//set Administrator's name
	this->setId(id);	//set Administrator's M number
	this->setEmail(e);	//set Administrator's email address
	this->setTitle(t);	//set Administrator's title
}

string Administrator::print()
{
//Print out Administrator's name,M number,Email,tile information
	string s;
	
	string str = to_string((*this).mNumber);
	
	s="Administrator: \n \t Full Name: \t "+(*this).name+"\n\t M Number: \t "+str+"\n\t Email Addr: \t "+(*this).email+"\n\t title: \t "+(*this).title+"\n";
	return s;
}


void Administrator::setTitle(string myTitle) // setter method,set Administrator's title
{
	title=myTitle;
}




