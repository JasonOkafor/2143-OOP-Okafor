/**
* Course: CMPS 2143 - OOP
* Assignmet: PO1
* Purpose: The program makes a class to implement a vector
*
* @author Jason Okafor
* @version 1.1 9/14/18
*/
#include <iostream>
#include "myVector.h"

using namespace std;

/**
* The function is a parameter constructor that gives the fullsize of the vector
*
* @param{int}
* @return{nothing}
*/
myVector::myVector(int size) {
	vSize = 0;
	FullSize = size;
	theVector = new int[FullSize];
	//just so we have stuff to print!!!!!
	for (int i = 0; i<FullSize; i++) {
		theVector[i] = i * 2;
	}
}

/**
* This function implementing to print
*
* @param{nothing}
* @return{nothing}
*/
void myVector::print() {
	for (int i = 0; i<vSize; i++) {
		cout << theVector[i] << " ";
	}
	cout << endl;
}

/**
* This function is a constructor and theVector is the array
*
* @param{nothing}
* @return{nothing}
*/
//constructor 
myVector::myVector()
{
	theVector = nullptr;
	vSize = 0;
	FullSize = vSize;
}

/**
* This function is a destructor that deletes the pointer 
*
* @param{nothing}
* @return{nothing}
*/
//destructor 
myVector::~myVector()
{
	delete[] theVector;
	theVector = nullptr;
}

/**
* The function adds a new element to the end of the list
*
* @param{int}
* @return{nothing}
*/
void myVector::push_back(int item)
{
	if (vSize == FullSize)
	{
		resize(FullSize * 1.5);
	}

	theVector[vSize] = item;
	vSize++;

}

/**
* This function removes the last element and given it back of were it came from 
*
* @param{nothing}
* @return{theVector[i]}
*/
int myVector::pop_back()
{
	int i = vSize - 1;
	if (vSize == 0)
	{
		cout << "FALSE: ARRAY IS EMPTY" << endl;
		return 0;
	}
	else
	{
		if (vSize <= FullSize * .40) {
			resize(FullSize * .5);
		}

		vSize--;
		return theVector[i];
	}
}

/**
* The function deletes theVector and makes a newVector 
*
* @param{int}
* @return{nothing}
*/
void myVector::resize(int newSize)
{
	int* newVector = new int[newSize];

	for (int i = 0; i < FullSize; i++)
	{
		newVector[i] = theVector[i];

	}
	FullSize = newSize;

	int* temp = theVector;
	theVector = newVector;
	delete temp;

}

/**
* The function tells want the size is 
*
* @param{nothing}
* @return{vSize}
*/
int myVector::size()
{
	return vSize;
}