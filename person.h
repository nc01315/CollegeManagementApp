//filename: person.h
// Author: David Chen
// This class provides an abstract base class for the Administrator, Faculty and the Student classes. This class contains:
// constructors
//Data members to store a person’s name, M Number, and email address.
//Appropriate "get" and "set" methods
//Pure virtual print() methods

#include <string>

#ifndef PERSON_H
#define PERSON_H

using namespace std;

//Abstract Base Classsss
class Person{

public:
    Person();		//constructor
	Person(string n,int id,string e);  //user defined constructor 

    virtual string print()=0;// *** pure virtual method *** it's up to sub-class to define print()
	virtual string getName(); // get person's name // *** polymorphic method ***
	virtual int getId();	//get person's M number // *** polymorphic method ***
	virtual int getMnumber(); // get person's M number // *** polymorphic method ***
	virtual string getEmail(); // get person's email // *** polymorphic method ***
	
	virtual void setName(string myName); // set person's M number // *** polymorphic method ***
	virtual void setId(int myId);// setter set person's M (id) number // *** polymorphic method ***
	virtual void setMnumber(int myId); // set person's M number // *** polymorphic method ***
	virtual void setEmail(string myEmail); // set person's email // *** polymorphic method ***

	friend ostream& operator<< ( ostream& ostr,  Person* PersonPtr );

protected:
	string name;  //persons's name
	int mNumber;   //persons's M number
	string email;   //persons's email address
};


#endif