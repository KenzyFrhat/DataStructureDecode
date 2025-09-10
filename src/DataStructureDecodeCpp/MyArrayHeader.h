#pragma once
#include <iostream>
#include <string>
using namespace std;


namespace Array
{
template <typename T>
void Resize(T*& Source, int newSize);


template <typename T>
T GetAt1(T*& Array, int idx, int arrSize) {

	if (idx < 0 || idx >= arrSize)
		return -1;

	char* zeroAddr = reinterpret_cast<char*>(Array);
	cout << "Look at this address! " << zeroAddr << endl;

	char* itemAddr = (zeroAddr)+(sizeof(T) * idx);

	return *reinterpret_cast<T*>(itemAddr);

}



template <typename T>
T GetAt2(T* Array, int idx, int arrSize) {
	if (idx >= arrSize || idx < 0)
		return T();

	char* zeroAddr = reinterpret_cast<char*>(Array);
	char* itemAddr = zeroAddr + (idx * sizeof(T));

	return *reinterpret_cast<T*>(itemAddr);

}


template <typename T>
void Resize(T*& Source, int newSize) {
	//validation

	cout << "The old array length : " << static_cast<int>(sizeof(Source)) << "\n";

	if (newSize < 0)
		return;
	if (newSize == static_cast<int>(sizeof(Source)))// to get the array size by the pointer 
		return;
	if (newSize < static_cast <int>(sizeof(Source))) // output sizeof(source) ? 
		return;
	if (Source == nullptr)
		return;


	//progress 
	T* newArray = new T[newSize];
	for (int i = 0; i < newSize; i++) {
		newArray[i] = Source[i];
	}

	//cout << "New Array after filling it with old one's elements \n";
	for (int i = 0; i < newSize; i++) {
		cout << newArray[i] << ", ";
	}

	Source = newArray;

}

}




