#pragma once
#include <iostream>
#include <string>
	using namespace std;

namespace MyNamespace
{
	template <typename T>
	class Array {
		int initialSize;
		int currentSize;
		int topIndex;
		T* dataList;

	public:
		Array(int size = 10) {
			this->initialSize = size;
			this->currentSize = size;
			this->topIndex = -1;
			this->dataList = new T[size];
		}


		void ResizeOrNot() {
			if (topIndex < currentSize - 1) return;

			T* newArray = new T[currentSize + initiaSize];
			copy(dataList, dataList + currentSize, newArray);
			currentSize += initialSize;
			delete[] this->dataList;
			this->dataList = newArray;


		}

		void
	};

	template <typename T>
	class Stack {

	};


}