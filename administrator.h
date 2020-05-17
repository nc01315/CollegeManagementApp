//filename: Administrator.h
// Author: David Chen
// This program sets up all the member functions and data member for Administrator Class 
//This class is a derived class of the Person class and contains:
// constructors
//Data members to store:Title
//inheritated "get" and "set" methods 

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "person.h"


using namespace std;

class Administrator : public Person
{
public:
     Administrator();									//constructor
	 Administrator(string n,int id,string e,string t);  //user defined constructor 

     string print();							//print *** polymorphic method ***
	 string getTitle(); 						//get Administrator's title
	 void setTitle(string myTitle); 			//set Administrator's title
	 //friend ostream& operator<< ( ostream& ostr,  Person* PersonPtr );

private:
	string title;								//Administrator's title

};

#endif