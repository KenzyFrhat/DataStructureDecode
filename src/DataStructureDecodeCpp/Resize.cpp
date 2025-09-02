# include <iostream>
# include <string>
# include "ArrayHeader.h"
using namespace std;

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
