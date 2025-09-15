#include "DictionaryBasedOnArray.h"

//int main(){
//	dictionary<string, int>* dict = new dictionary<string, int>();
//	//dict->Print();
//	//cout << "Length: " << dict->Size() << endl;
//
//	cout << "Adding key-value pairs:" << endl;
//	dict->Set("One", 1);
//	dict->Set("Two", 2);
//	dict->SetUsing_KeyPairMethods("Three", 3);
//	dict->Set("Four", 4);
//	//dict->Print();
//	cout << "Length: " << dict->Size() << endl;
//
//	cout << "Using Get method to retrieve values:" << endl;
//	cout << "Key: One, Value: " << (dict->GetPair("One")->GetValue()) << endl;
//	cout << "Key: Two, Value: " << *(dict->Get("Two")) << endl;
//	cout << "Key: Three, Value: " << *(dict->Get("Three")) << endl;
//	cout << "Key: Four, Value: " << *(dict->Get("Four")) << endl;
//
//	cout << "Updating value for key 'Two':" << endl;
//	dict->Set("Two", 22); // update value for key "Two"
//	cout << "After updating, Key: Two, Value: " << *(dict->Get("Two")) << endl;
//
//	cout << "Updating value for key 'Three':" << endl;
//	dict->SetUsing_KeyPairMethods("Three", 22); // update value for key "Two"
//	cout << "After updating  in another way, Key: Two, Value: " << *(dict->Get("Three")) << endl;
//
//
//	cout << "Removing key 'Three':" << endl;
//	dict->Remove("Three");
//	cout << "After removing key 'Three', Length: " << dict->Size() << endl;
//	if (dict->Get("Three") == NULL) {
//		cout << "Key 'Three' not found." << endl;
//	}
//
//	dict->Set("Five", 5); 
//	cout << "After adding key 'Five', Length: " << dict->Size() << endl;
//	cout << "Key: Five, Value: " << *(dict->Get("Five")) << endl;
//
//	dict->Set("Six", 6);
//	cout << "After adding key 'Five', Length: " << dict->Size() << endl;
//	cout << "Key: Five, Value: " << *(dict->Get("Five")) << endl;
//
//	delete dict;
//
//	//return 0;
//}