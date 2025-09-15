#pragma once

# include <iostream>
# include <string>
using namespace std;

template <typename TKey, typename TValue>
class dictionary {

private:
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

		TKey GetKey() { return _key; }
		TValue GetValue() { return _value; }
		TValue& GetValueRef() { return _value; } // return by reference to allow modification
		void SetValue(TValue value) { _value = value; }


	};


private:
	KeyValuePair* pairs;
	int length;
	int capacity;
	const int initialCapacity;
public:
	dictionary(int initialCapacity = 4) : initialCapacity(initialCapacity) {
		this->capacity = initialCapacity;
		this->length = 0;
		this->pairs = new KeyValuePair[initialCapacity];
	}

	/*~dictionary() {
		delete[] pairs;
	}*/

	int Size() { return length; }

	void ResizeIfNeeded() {
		if (length == capacity) {
			capacity += initialCapacity; // add the initial capacity to the current capacity
			// create new array of pairs :
			KeyValuePair* newPairs = new KeyValuePair[capacity];
			// copy old array to new array
			copy(pairs, pairs + length, newPairs);
			// delete old array
			delete[] pairs;
			// point to new array
			pairs = newPairs;

			cout << "Resized to capacity from " << capacity - initialCapacity << "  to: " << capacity << endl;
		}
	}


	TValue* Get(TKey key) {
		// leaniar search
		for (int i = 0; i < length; i++) {
			if (pairs[i].GetKey() == key) {
				return  &this->pairs[i].GetValueRef();
			}
		}
		return NULL;
	}


	void Set(TKey key, TValue value) { // useing pointers to reset the value by its address
		// check if key exists 
		TValue* existingValue = Get(key);
		if (existingValue != NULL) { // key exists
			*existingValue = value; // update the value
			return;
		}

		// key does not exist , add new keypair
		ResizeIfNeeded();
		pairs[length] = KeyValuePair(key, value);
		length++;
	}


	KeyValuePair* GetPair(TKey key) {
		// leaniar search
		for (int i = 0; i < length; i++) {
			if (pairs[i].GetKey() == key) {  // GetKey inside the keypair class
				return &pairs[i]; // return the address of the keypair ( TODOL why & not * ) => 

			}
		}
		return NULL;

	}

	void SetUsing_KeyPairMethods(TKey key, TValue value) {
		KeyValuePair* existingPair = GetPair(key);
		if (existingPair != NULL) { // key exists
			existingPair->SetValue(value); // update the value using SetValue inside the keypair class
			return;
		}

		// key does not exist , add new keypair
		ResizeIfNeeded();
		pairs[length] = KeyValuePair(key, value);
		length++;
	}


	void Remove(TKey key) {
		// search for the key pair
		if (length == 0) return; // empty dictionary

		for (int i = 0; i < length; i++) {
			if (pairs[i].GetKey() == key) { // key found
				pairs[i] = pairs[length - 1];
				pairs[length - 1] = KeyValuePair(); // optional to clear the last pair
				length--;
				return;
			}
		}
		// key not found , do nothing

	}

	void Print() {
		if (length == 0) {
			cout << "Empty dictionary" << endl;
			return;
		}
		// print all key value pairs
		for (int i = 0; i < length; i++) {
			cout << "Key: " << pairs[i].GetKey() << ", Value: " << pairs[i].GetValue() << endl;
		}
	}

};