//filename: person.cpp
// Author: David Chen
// This program intialize all data members for Person Class and implement  member functions

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

Person::Person()
{
//default constructor to initiate class member data
	 name="";  //Person's name
	 mNumber=0;   //Person's M number
	 email="";   //Person's email address
}

Person::Person(string n,int id,string e)		
//constructor:setter method
{
	name=n;			//set Person's name
	mNumber=id;		//set Person's M number
	email=e;		//set Person's email address
}

string Person::getName() // getter method,get Person's M number
{
	return (*this).name;
}

int Person::getId() // getter method,get Person's M (id) number
{
	return (*this).mNumber;
}

int Person::getMnumber() // getter method,get Person's M number
{
	return (*this).mNumber;
}

string Person::getEmail() // getter method,get Person's email
{
	return (*this).email;
}

void Person::setName(string myName) // setter method,set Person's M number
{
	 name=myName;
}

void Person::setId(int myId) // setter method,set Person's M (id) number
{
	mNumber=myId;
}

void Person::setMnumber(int myId) // setter method,set Person's M number
{
	mNumber=myId;
}

void Person::setEmail(string myEmail) // setter method,set Person's email
{
	email=myEmail;
}

ostream& operator << ( ostream& ostr, Person* PersonPtr ) // only visible in administrator class
{
	ostr << PersonPtr-> print();
	return ostr;
}