//filename: faculty.h
// Author: David Chen
// This program sets up all the member functions and data member for Faculty Class 
//This class is a derived class of the Person class and  contains:
//Appropriate constructors
//Data members to store: Title."get" and "set" methods


#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include "person.h"


using namespace std;

//Faculty is a derived class of Person
class Faculty : public Person{
	
public:
    Faculty();		//constructor
	Faculty(string n,int id,string e,string d,int t);  //user defined constructor 
    virtual string print();	//Add,Delete,Print// *** polymorphic method ***

	int getTenured(); // get Faculty's Tenure status
	string getDepart(); // get Faculty's departmnet

	void setTenured(int myTenured); // set Faculty's Tenure status
	void setDepart(string myDepart); // set Faculty's departmnet
	
 	//friend ostream& operator<< ( ostream& ostr,  Person* PersonPtr );
	

private:	
	string depart; //Faculty's department
	int tenured; //Faculty's tenure status
};

//#include "HashTable.cpp"

#endif