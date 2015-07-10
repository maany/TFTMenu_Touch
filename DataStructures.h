/*
DataStructures.h 

Author : Mayank Sharma (imptodefeat@gmail.com)

This header file defines some common data structures which are used 
by the TFTMenu library to track menu and user actions.
This library is compatible with the Aurdino environment as it uses
basic C++ concepts to implement the data structures.
The header includes both API documentation and Implementation documentation

*/
#ifndef DATA_STRUCTURES_h
#define DATA_STRUCTURES_h
#define DEFAULT_STACK_CAPACITY 10
//-------------
// Generic Stack
//--------------
template<class T>
class Stack{
	int capacity;
	int TOP;
	T** data;
public:
	Stack(int);
	Stack();
	bool push(T* element);
	T* pop();
	int size();
	T* peek();
	T* operator[](int i);
};
// -----------------------------------------------
//Template functions must be defined in header file
// ------------------------------------------------

//-----------------------------------------------------------
// Constructor which initializes a new Stack of given capacity
//------------------------------------------------------------
template<class T>
Stack<T>::Stack(int capacity){
	this->capacity = capacity;
	data = new T*[capacity];
	TOP = -1;
}

//--------------------------------------------------------------------------------------
// Default Contructor will initialize a Stack with DEFAULT_STACK_CAPACITY , currently 10
//--------------------------------------------------------------------------------------
template<class T>
Stack<T>::Stack(){
	this->capacity = DEFAULT_STACK_CAPACITY;
	data = new T*[capacity];
	TOP = -1;
}

//-------------------------------------------
// push element on top of Stack. 
// Return false if overflow condition is met
//-------------------------------------------
template<class T>
bool Stack<T>::push(T* element){
	if (TOP>=capacity)
		return false;
	TOP++;
	data[TOP] = element;
	return true;
}

//-------------------------------
// Pop element from top of stack. 
// Return null if stack is empty
//--------------------------------
template<class T>
T* Stack<T>::pop(){
	if(TOP<0){
		return '\0';
	}
	T* returnValue = data[TOP];
	TOP--;
	return returnValue;
}

//---------------------------------------------------
// Returns pointer to the top most element of stack. 
// Returns null if stack is empty.
//---------------------------------------------------
template<class T>
T* Stack<T>::peek(){
	if(TOP>=0 && TOP<=capacity)
		return this->operator[](TOP);
	return '\0';
}
template<class T>
T* Stack<T>::operator[](int i){
	if(i>TOP || TOP<0)
		return '\0';
	return data[i];
}
//-----------------------------------------------------------
// returns 0 if stack is empty
// returns -1 if overflow, should never return this value 
//------------------------------------------------------------
template<class T>
int Stack<T>::size(){
	if(TOP<0)
		return 0;
	else if(TOP>capacity)
		return -1;
	else
		return TOP;
}
#endif