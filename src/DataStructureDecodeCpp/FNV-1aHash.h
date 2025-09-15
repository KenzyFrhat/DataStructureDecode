#pragma once

# include <iostream>
# include <string>
# include <vector>
using namespace std;

namespace FNV_1aHash{

	// offsetbasis =  ( 2166136261 ) to get hash with length -> 32
	// FNVPrime = 161777619

	class Hash {
	public:
		unsigned int Hash32(string str) {
			unsigned int OffsetBasis = 2166136261;
			unsigned int FNVPrime = 161777619;
			// incode the string into bytes
			vector<char> byteArray(str.size());
			for (size_t i = 0; i < str.size(); ++i) {
				byteArray[i] = char(str[i]);
			}
			// end
			unsigned int hash = OffsetBasis;
			for (int i = 0; i < byteArray.size(); i++) {
				hash = hash ^ byteArray[i];
				hash = hash * FNVPrime;
			}
			cout << str << ", " << hash << ",  " << hex << hash << endl;
			return hash;
		}//hash32
	};//class


}