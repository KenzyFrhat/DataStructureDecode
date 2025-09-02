# include "ArrayHeader.h"

template <typename T>
T GetAt1(T*& Array, int idx, int arrSize) {

	if (idx < 0 || idx >= arrSize)
		return -1;

	char* zeroAddr = reinterpret_cast<char*>(Array);
	cout << "Look at this address! " <<  zeroAddr << endl;

	char* itemAddr = (zeroAddr) + (sizeof(T) * idx);

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
