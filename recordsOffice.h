//filename: recordsOffice.h
// Author: David Chen
// This program creates a studentList object
//This class contains:
// constructor(s)
//Data members:
//A STL container to store person pointers
//Method to parse commands from a specified file
//A	<name> <M number> <email> <department> Add the specified administrator member
//F <name> <M number> <email> <department> <tenured> Add the specified faculty member.
//S <name> <M number> <email> <year in school> <major> Add the specified student.
//D <M number> Delete the specified person.
//P <M number> Print the specified person.
//L :Process the L command by calling the dump() method in the HashTable class.Print the entire list of people

#include <string>
#include <vector>


#ifndef RECORDS_OFFICE_H
#define RECORDS_OFFICE_H
#include "person.h"


using namespace std;

class RecordsOffice
{  
	public:   
		RecordsOffice();							//constructor
		void importRecords(string filenName);		//Add ,Delete,Print

	private:
		vector <Person *> PersonPtr;
};

//#include "recordsOffice.cpp"

#endif