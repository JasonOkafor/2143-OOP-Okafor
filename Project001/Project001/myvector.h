/**
* Course: CMPS 2143 - OOP
* Assignmet: PO1
* Purpose: The program makes a class to implement a vector
*
* @author Jason Okafor
* @version 1.1 9/14/18
*/
#include <vector>
#include <iostream>

using namespace std;

class myvector {

private:
	//private attributes
	int *theVector;
	int vSize;
	int FullSize;

	//private methods
	void resize(int newSize);



public:
	//parameterized constructor 
	myVector(int size);
	void print();
	//default constructor 
	myVector();
	//destructor construtor 
	~myVector();
	//push method
	void push_back(int item);
	//pop method
	int pop_back();
	//size method
	int size();

};
