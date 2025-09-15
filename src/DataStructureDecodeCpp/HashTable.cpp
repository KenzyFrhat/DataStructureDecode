# include "FNV-1aHash.h" // header file name
using namespace FNV_1aHash; // namesapce name
//TODO: Include the namespace from into the cpp file to access data and members


int main() {
	Hash* MyHash = new Hash();
	unsigned int hash = MyHash->Hash32("Kannoza");
	unsigned int idx = hash % 10;
	cout << "\nThe returned index is " << idx;
}