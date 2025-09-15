#pragma once

# include <iostream>
# include <string>
# include <vector>
using namespace std;

template <typename TKey, typename TValue>
class HashTable {
public:
	class KeyValuePair {
		TKey _key;
		TValue _value;
	public:
		KeyValuePair() {
			_key = TKey{};
			_value = TValue{};
		}

		KeyValuePair(TKey key, TValue value) {
			_key = key;
			_value = value;
		}

		//TKey GetKey() { return _key; }
		//TValue GetValue() { return _value; }
		//TValue& GetValueRef() { return _value; } // return by reference to allow modification
		//void SetValue(TValue value) { _value = value; }
	}

private:
	KeyValuePair* dataEntries;
	int size;
	const int initailSize;
	int entriesCount;

public:
	dictionary(int initailSize = 4) {
		this->initailSize = initailSize;
		this->size = initailSize;
		int entriesCount = 0;
		this->dataEntries = new KeyValuePair[initailSize];
	}
	
	/*~dictionary() {
		delete[] pairs;
	}*/

	int Size() {
		return this->entriesCount;
	}

	// TODO: Convert any key data type to binary 
	
     int GetHash(TKey key) {

		unsigned int OffsetBasis = 2166136261;
		unsigned int FNVPrime = 161777619;
		// incode the string into bytes
		vector<char> byteArray(key.size());
		for (size_t i = 0; i < key.size(); ++i) {
			byteArray[i] = char(key[i]);
		}
		// end loop
		unsigned int hash = OffsetBasis;
		for (int i = 0; i < byteArray.size(); i++) {
			hash = hash ^ byteArray[i];
			hash = hash * FNVPrime;
		}
		
		return hash % this->size;
	}// Get Hash


	 int CollisionHandlingForGet( int hash, TKey key) {
		for (int i = 0; i < this->size; i++) {
			 int newHash = (hash + i * i) % this->size;
			// null -> no exist OR key == key (exist)
			if (this->dataEntries[newHash]._key == key) {
				return newHash;
			}
			
		}
		return -1; // not exist 
	} //CollisionHandlingForGet


	 int CollisionHandlingForSet( int hash, TKey key) {

		 for (int i = 0; i < this->size; i++) {
			  int newHash = (hash + i * i) % this->size;
			 // null (update) || key == key 
			  if (this->dataEntries[newHash] == NULL || this->dataEntries[hash]._key == key) {
				  return newHash;
			 }
		 }
		 return -1;
	 }// CollisionHandlingForSet()

	 void AddToEntries(TKey key, TValue value) {
		 // ResizeOrNot -> deleted and create new function ( Set ) to avoid Circural dependency resolution
		 int hash = GetHash(key);
		 // collision checking 
		 if (this->dataEntries[hash] != NULL && this->dataEntries[hash]._key != key) {
			 // collision happneds -> handle
			 hash = this->CollisionHandlingForSet();
		 }
		 if (hash == -1) {
			 throw new exception("Invalid Hash Table");
		 }
		 if (this->dataEntries[hash] == NULL) {
			 // create new pair and add it to the hash table with the gevin hash
			 KeyValuePair* pair = new KeyValuePair(key, value);
			 this->dataEntries[hash] = pair;
			 this->entriesCount++;
		 }
		 if (this->dataEntries[hash]._key == key) {
			 this->dataEntries[hash]._value = value;
		 }
		 else
			 throw new exception("Invalid Hash Table");

	 }//AddToEntries

	 void ResizeOrNot() {
		 if (this->size - 1 == this->entriesCount) {
			KeyValuePair* CopyDataEntries = new KeyValuePair[this->size]; // new array with the new size 
			copy(this->dataEntries, dataEntries + this->size, CopyDataEntries);
			int newSize = this->size * 2; 
	    	this->dataEntrie = new KeyValuePair[newSize];  
			for (int i = 0; i < this->size; i++) {
				this->AddToEntries(this->CopyDataEntries[i]._key, this->CopyDataEntries[i]._value);// add with new hashing 
			}
			this->size = newSize;  //update size
		 }

	 }// ResizeOrNot


	 // to avoid Circular Dependency Resolution
	 void Set(TKey key, TValue value) {
		 ResizeOrNot();
		 AddToEntries(key, value);
		
	 }// Set


	 TValue Get(TKey) {
		 int hash = GetHash(key);
		 // collision checking 
		 if (this->dataEntries[hash]._key != NULL && this->dataEntries[hash]._key != key) {
			 // there is another existing  key in the hash table ( collision)
			 hash = CollisionHandlingForGet();
			
		 }
		 if (hash == -1 || this->dataEntries[hash] == NULL) {  // key = -1 means not exist after collision
			 return NULL;
		 }

		 if(this->dataEntries[hash]._key == key){
			 return this->dataEntries[hash]._value;
		 }
		 else {
			throw exception("Invalid hash table") ; // not of any other cases happends -> something is wrong
		 }
	     
	 } // Get


	 void Remove(TKey key) {
		 int hash = GetHash(key);
		 if (this->dataEntries[hash]._key == NULL) return;// if not exist return;
		 if (this->dataEntries[hash]._key != key) { // if collision (hash already has value but not the value of given key) collision handling
			 hash = CollisionHandlingForGet();
		 }
		 if (hash == -1 || this->dataEntries[hash]._key == NULL) { // check value of hash -> if -1 : not exist or if quual null return 
			 return;
		 }
		
		 // if hash key == given key -> delete it 
		 if (this->dataEntries[hash]._key == key) {
			 this->dataEntries[hash] = NULL;
			 this->entriesCount--;
		 }
		 // else something wrong throw an exeption
		 else {
			 throw exception("Invalid hash table");
		 }
	 }
}; // class hash



