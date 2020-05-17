//filename: recordsOffice.cpp
// Author: David Chen
// This program is to read a tab file and process the info based on the A F S P D L

#include <iostream>
#include <string>
#include <fstream>

#include "recordsOffice.h"

#include "faculty.h"
#include "student.h"
#include "administrator.h"
#include "HashTable.h"


using namespace std;

RecordsOffice::RecordsOffice()	//constructor
{

}

void RecordsOffice::importRecords(string filenName)
{
//public member function performs Add ,Delete,Print
	string AFSPDL;
	
	int TableSize; // size of Hash Table
	
	string AdminName;
	string AdminEmail;
	string AdminTitle;
		
	string FacultyName;
	string StudentName;
	
	string Name;  // new variable
	int AdminID;
	int FacultyID;
	int StudentID;
		
	string FacultyEmail;
	string FacultyDepart;
	int FacultyTenured;
	
	string StudentEmail;
	int StudentGrade;
	string StudentMajor;
	
	ifstream infile;
	
	infile.open( filenName.c_str() );
	
	HashTable < Person* > myHashTable; //create an instance of HashTable Class, called myHashTable
	
	infile>>TableSize;	// read in size
	
	
	myHashTable.setTableSize(TableSize); //set table size
	
	infile>>AFSPDL; // read in flag

	//loop
	while(!infile.eof())
	{
		if (AFSPDL=="A")  // adding a student
		{
			infile>>AdminName;			
			infile>>AdminID;
			infile>>AdminEmail;
			infile>>AdminTitle;
			
			cout<<"Adding "<<AdminName<<" ..."<<endl<<endl;
			Administrator *administratorPtr=new Administrator(AdminName,AdminID,AdminEmail,AdminTitle);
			myHashTable.insert(administratorPtr);
		}
		
		
		else if (AFSPDL=="F")  // adding a faculty
		{
			infile>>FacultyName;			
			infile>>FacultyID;
			infile>>FacultyEmail;
			infile>>FacultyDepart;
			infile>>FacultyTenured;
			
			cout<<"Adding  "<<FacultyName<<" ..."<<endl<<endl;
			
			Faculty *facultyPtr=new Faculty(FacultyName,FacultyID,FacultyEmail,FacultyDepart,FacultyTenured);
			
			myHashTable.insert(facultyPtr);
		}
		
		else if (AFSPDL=="S")  // adding a student
		{
			infile>>StudentName;			
			infile>>StudentID;
			infile>>StudentEmail;
			infile>>StudentGrade;
			infile>>StudentMajor;
			
			cout<<"Adding "<<StudentName<<" ..."<<endl;
		
			Student *studentPtr=new Student(StudentName,StudentID,StudentEmail,StudentGrade,StudentMajor);
			
			myHashTable.insert(studentPtr);
		}
		
		else if(AFSPDL=="P")  // print a person and number of visiting steps
		{			
			infile>>Name;	// change 
			
			cout<<"Finding "<<Name<<" . . . "<<endl;
			if ( myHashTable.find(Name) )
				myHashTable.printOne(Name);
			else
				cout<<Name<<" does not exist in the Hash Table "<<endl;	
		}  //end of else if for P
	
		else if (AFSPDL=="D")	// deleting a student
		{
			infile>>Name;			
			myHashTable.remove(Name);
		}  //end of else if
	
	
		else if (AFSPDL=="L")	// dumpping ENTIRE LIST OF PPL
		{
			cout<<"Dumping ..."<<endl;
			myHashTable.dump();	// calling the dump() method in the HashTable class
		}
	
		infile>>AFSPDL;
	
	} // END OF WHILE

	infile.close();
    
    return ;
}
