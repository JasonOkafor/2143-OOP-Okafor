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

int main() {

	cout << "Course: CMPS 2143 - OOP" << endl;
	cout << "Assignmet : PO1" << endl;
	cout << "Purpose : The program makes a class to implement a vector" << endl;
	cout << "@author Jason Okafor" << endl;
	cout << "@version 1.1 9 / 14 / 18" << endl << endl;

	//the size is 10
	myVector V(10);
	
	//removing from the empty vector will return false
	V.pop_back();

	cout << "there are " << V.size() << " items in this vector." << endl;

	//insert the values
	V.push_back(13);
	V.push_back(31);
	V.push_back(73);

	V.print();

	//insert 10000 items
	int i;
	for (i = 0; i < 10000; i++)
	{
		V.push_back(0);
	}
	cout << "there are " << V.size() << " items in this vector." << endl;

	//remove 998 items
	for (i = 0; i < 998; i++)
	{
		V.pop_back();
	}
	cout << "there are " << V.size() << " items in this vector." << endl;



	system("pause");
	return 0;

}
