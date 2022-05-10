
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

//Notes: In this class I overloaded the ostream operator and converted the Array class so instead of just ints you can use any type (templating). I also added a T& Array<T>::operator[] function.

template <class T>
class Array {

	template <class V>
	friend ostream& operator<<(ostream& out, const Array<V>&);

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		T& operator[](int) const;
		
		//other
		void add(T);
		int get(int index) const;
		int getSize() const;
		bool isFull() const;
	
	private:
		int size;
		T* elements;
		
	
};

//constructor

template <class T>

Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

//destructor

template <class T>

Array<T>::~Array(){
	delete [] elements;
}

//other

template <class T>

void Array<T>::add(T t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>

int Array<T>::getSize() const{
	return size;
}

template <class T>

bool Array<T>::isFull() const{
	return size >= MAX_ARR;
}

template <class T>

int Array<T>::get(int index) const {
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

//Note: I also added this function.
template <class T>
T& Array<T>::operator[](int index) const {

	if ((index < 0) || (index >= size)) {
		cout << "Error: Index is out of bounds." << endl;
		exit(1);
	}
	return elements[index];
}

template <class T>

ostream& operator<<(ostream& output,const Array<T>& arr){

	output << endl;

	for (int i = 0; i < arr.getSize(); i++) {
		output << arr.elements[i];
	}

	output << endl;
	return output;
}



#endif
