//# include "  .h"

//int main(){
//	stack<string>* myStack = new stack<string>;
//	myStack->push("10");
//	myStack->push("20");
//	myStack->push("30");
//	myStack->PrintList();
//	cout << "Top element is: " << myStack->Peek() << endl; // Should print 30
//	cout << "Stack size is: " << myStack->Size() << endl; // Should print 3
//	myStack->pop();
//	cout << "Top element after pop is: " << myStack->Peek() << endl; // Should print 20
//	cout << "Stack size after pop is: " << myStack->Size() << endl; // Should print 2
//
//	while (!myStack->IsEmpty()) {
//		myStack->PrintStack();
//		cout << myStack->pop() << " has been deleted \n";
//		cout << myStack->Size() << '\n';
//
//	}
//	return 0;


//	SinglyLinkedList<string>* list1 = new SinglyLinkedList<string>;
//	list1->PrintList();
//	// insert last 
//	list1->InsertLast("Kannoza");
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//
//	//// insert After 
//	list1->InsertAfter("Frahat", "Kannoza");
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//	//// insert before  as head
//	list1->InsertBefore("Engineer", "Kannoza");
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//	//// insert after node that is after head
//	list1->InsertBefore("Sheper", "Kannoza");
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//	//// insert before tail
//	//
//	list1->InsertBefore("Allazoza", "Frahat");
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//	//// insert before in the middle 
//	//
//	list1->InsertBefore("Robot", "Kannoza");
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//
//	//// insert after ( as tail)
//	//
//	list1->InsertAfter("Mohamed", "Frahat");
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//
//	//// insert after head 
//	//
//	list1->InsertAfter("Bloul", "Engineer");
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//
//	//// insert in the middle 
//	//
//	list1->InsertAfter("Mansoura", "Robot");
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//
//
//	// delete node 
//	list1->Delete("Bloul");
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//
//
//	list1->DeleteTail();
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//
//	list1->DeleteHead();
//	list1->PrintList();
//	cout << "Head : " << list1->head->data << ", Tail : " << list1->tail->data << endl << endl;
//
//}
