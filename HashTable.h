//filename: HashTable.h
// Author: David Chen

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

using namespace std;


int i=0;						// how many time item has been visited 
int actualNum=0;				// set actual total number element in the hash table to 0
int *RecordArray;				// Dynamic array used in insert ( )
int actualTableElements=0;		// number of used slot in the vector
int counter=0;					// use in insert ( )

template <typename T>
class HashTable
{  
	public:   
		HashTable();						//constructor
		void insert( T PersonPointer );		//add
		void remove(string name);			//delete
		bool find(string name);				//retrieve
		void printOne(string name);  		//print only ONE person's info
		void dump();						//print every person's info, overload << operator
		void setTableSize(int size);		//setter function to set the size of hash table
		
	private:
		int TableSize;							//hash table size
		vector < list < T > > PersonPtr;		//hash table
		int hash( const string & key ) const ;	//hash function 
};


//constructor
template < typename T >
HashTable < T >::HashTable()
{
		TableSize=-1;
}

// Hash function, can only handle strings.
template <typename T>
int HashTable<T>::hash( const string & key ) const
{
    int hashVal = 0;
	int sum=0;
    for( int i = 0; i < key.size(); i++ )
	{
		sum=sum+key[i];
        //hashVal =  ( hashVal << 5 ) ^ key[ i ] ^ hashVal;
	}
	
	if (TableSize % 2==0) //if TableSize is even
		hashVal=sum % (TableSize-1);	//devide by an odd number
	else  //else if TableSize is odd
		hashVal=sum % (TableSize);	//devide by an odd number
		
    return hashVal;
}

template <typename T>
void HashTable<T>::insert( T PersonPointer ) 
{	

	double Alpha; // declare load factor alpha
	
	string myName=PersonPointer->getName();
		
	int hashIndexNum=hash(myName);
		
	PersonPtr[hashIndexNum].push_back(PersonPointer);  	


	if (counter==0)
	{
		RecordArray=new int[PersonPtr.size()];   // book keeping 

		for (int i=0;i<PersonPtr.size();i++)
		{
			 RecordArray[i]=0;
		}
	}

	RecordArray[hashIndexNum]=RecordArray[hashIndexNum]+1; // insert one item


	actualTableElements=0;  //RESET BEFORE BOOK KEEPPING

	for (int i=0;i<PersonPtr.size();i++)
	{
		if( RecordArray[i] > 0 )
			actualTableElements++;  //  mark it 
	}
	
	actualNum++;  // increase actual element in the hash table
		
	Alpha = (double)actualNum / (double) actualTableElements;  // calculate load factor alpha

	cout<<"Alpha: "<< Alpha << endl<<endl;

	counter++;
}

// Remove item x from the hash table.
template <typename T>
void HashTable<T>::remove(string name)
{
	i=0; 			// how many item been visited 
	double Alpha; 	// declare load factor alpha
    typename	list<T> ::iterator iter; 	//iterator for list
   	
	cout<<"\nRemoving "<<name<<" ..."<<endl;
	
	if ( find(name) )  // found a match
	{
		int hashIndexNum=hash(name);
		
		for( iter = PersonPtr[hashIndexNum].begin(); iter != PersonPtr[hashIndexNum].end(); iter++)  // retrieve
		{
			i++; 	// bookkeeping
		
			if ( (*iter)->getName() == name ) //found a name match
			{
			
				PersonPtr[hashIndexNum].erase(iter);  // PersonPointer has to be STL interator
				actualNum--;  // decrease actual element in the hash table by 1
				//actualTableElements;
				RecordArray[hashIndexNum]=RecordArray[hashIndexNum]-1; // delete one item

				actualTableElements=0;  //RESET BEFORE BOOK KEEPPING
				for (int i=0;i<PersonPtr.size();i++)
				{
					if( RecordArray[i] > 0 )
						actualTableElements++;  //  mark it 
				}

				break;								//since found one ,stop iterating
			}		
		} //end of for 

		if (actualTableElements==0) //denominator is 0
			Alpha=0.0;
		else
			Alpha = (double)actualNum / (double)actualTableElements; // declare load factor alpha
		
		cout<< i <<" item visited for remove()"<<endl;

		cout<<"Alpha: "<< Alpha << endl<<endl;     // more work
	}
	
	else  // can not found a match
	{
		cout<<"ALERT: \""<<name<<"\" not found!"<<endl;
		cout<< i <<" items visited for remove()"<<endl;
		
		if(actualTableElements==0)   // demominator is 0
			Alpha=0.0;
		else
			Alpha = (double)actualNum / (double)actualTableElements; // declare load factor alpha

		cout<<"Alpha: "<< Alpha << endl<<endl;   //print out load factor n/m
		return;
	}
} // end of remove()


// Find item <T> in the hash table
template <typename T>
bool HashTable<T>::find(string name)
{
	i=0; // num of items visited
	
	bool found=0;	// set found to zero
	
	typename list < T > :: iterator iter;  		//Very important iterator
	
	int hashIndexNum=hash(name);

	if ( !PersonPtr.empty() )
	{
		
		for( iter = PersonPtr[hashIndexNum].begin(); iter != PersonPtr[hashIndexNum].end(); iter++)  // retrieve
		{
			
			if ((*iter) -> getName() == name ) //found a name match
			{
				found=1;			// set found to 1			
				break;				//since found one ,stop iterating
			}
		}	
	}
	
	return found;
}

template <typename T>
void HashTable<T>::dump()  // Print every person's info
{	
	typename list< T >::iterator Liter;  	//Viterator for list in vector  //syntax correct?

			if (PersonPtr.size()!=0)
			{
				for( int i =0; i<PersonPtr.size(); i++)
				{
					for( Liter = PersonPtr[i].begin(); Liter!=PersonPtr[i].end(); Liter++)
					{
						cout<<"Bucket index "<<i<<":"<<endl;
						cout << *Liter << endl;     //
					}
				}
			}
			else //(PersonPtr.size==0)
			{
				; //do nothing
			}
}



template <typename T>
void HashTable<T>::printOne(string name)  	// Print only ONE person's info and number of visiting operation
{
	i=0; 			// how many item been visited 
	typename list<T>::iterator iter;  	//Viterator for list in vector

	if ( find(name) )  // found a match
	{
			int hashIndexNum=hash(name);

			for( iter = PersonPtr[hashIndexNum].begin(); iter != PersonPtr[hashIndexNum].end(); iter++)  // retrieve
			{
				i++;  // Dr.Carroll 

				if (	(*iter)->getName() == name	) //found a name match
				{
					cout<< i <<" item visited for find()"<<endl;
					
					cout<<(*iter)<<endl;

					break;	//since found one ,stop iterating
				} // end of if 	
			} //end of for 		
		
		
	} // end of if
} // end of print ()


template <typename T>
void HashTable<T>::setTableSize(int size) // setter function 
{
	
	TableSize=size;
	
	PersonPtr.resize(TableSize);
	
}

#endif