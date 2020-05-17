# CollegeManagementApp
This C++ application manages the infomation of the students, faculties, administrators with more than five different C++ classes which publicly inherites the person class.

The administrator class has following members:
- a constructor administrator()
- a user defined constructor function, which can be overloaded 
- a print() public member function, which prints full name, M Number, Email, title of an administrator
- a getTitle() public member function, which return a title of an administrator (getter)
-	a setTitle(string myTitle), a public member function, returns nothing (setter)
- a private data member:
        title  // A TITLE OF A administrator



The faculty class has following members:
- a constructor function faculty()
- a user defined faculty constructor function, which can be overloaded 
- a print() public member function, which prints full mame, M number, Email, tenure status of a faculty
- a getter for a faculty's status, getTenured();
- a getter for a Faculty's departmnet, getDepart();
- a setter for a faculty's status, getTenured();
- a setter for a Faculty's departmnet, getDepart();
- two private data members:
        string depart; //Faculty's department
	int tenured; //Faculty's tenure status
        
        
The Student class has following members:
- a constructor function Student()
- a user defined Student constructor function, which can be overloaded 
- a print() public member function, which prints the full Name, M Number, department, major of a student
- a getter for a student's grade, getGrade(), returns an integer
- a getter for a student's major, getMajor(), returns a string
- a setter for a student's grade, setGrade(), takes an integer
- a setter for a student's major, setMajor(), takes a string
- two private data member:
        string grade; //student's department
	      int major; //student's major
        
       
The RecordsOffice class has following members:
- a constructor function RecordsOffice()
- a public member function:  importRecords(string filenName), which process (add,print,delete,or dumping personal records) the input file with a filenName as the parameter. This function uses an instance (an object) of a HashTable class from HashTable.h
- a private data member:
      a STL vector of person pointer : vector <Person *> PersonPtr;
                
        
The HashTable class has following members:
- a constructor function HashTable()
- a void function, insert( T PersonPointer ), takes a templated Person pointer of type T
- a void function, remove(string name), takes a person's name and delete it
- a boolean funtion, find(string name), take a person's name and retrieve the person's record (Yes or No) 
- a void function, printOne(string name), take a person's name and print only ONE person's info
- a void funtion, dump(),prints every person's info
- a void setter funtion, setTableSize(int size), set the size of a HashTable 	


- 3 private data members:

		int TableSize;				//hash table size
		vector < list < T > > PersonPtr;	//hash table, a STL vector of a STL lists
		int hash( const string & key ) const ;	//hash function, takes a key and return an integer value
    


