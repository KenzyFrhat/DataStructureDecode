#pragma once
#ifndef ArrayHeader
#define ArrayHeader
#include <iostream>
#include <string>
using namespace std;
template <typename T>
void Resize(T*& Source, int newSize);

template <typename T>
T GetAt1(T*& Array, int idx, int arrSize);

template <typename T>
T GetAt2(T* Array, int idx, int arrSize);


#endif
