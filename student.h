//filename: student.h
// Author: David Chen
// This program sets up all the member functions and data member for Student Class 
#include <string>
#include "person.h"

#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student : public Person
{
	public:
	    Student();											//constructor
		Student(string n,int id,string e,int g,string m);  //user defined constructor 
	    string print();										//Add ,Delete,Print *** polymorphic method ***
	
		int getGrade(); 						// get Student's grade// *** polymorphic method ***
		string getMajor(); 						// get Student's major// *** polymorphic method ***

		void setGrade(int myGrade); 			// set Student's grdae *** polymorphic method ***
		void setMajor(string myMajor); 			// set Student's major// *** polymorphic method ***

	private:
		int grade;								// year in school
		string major;							// Student's major
};


#endif