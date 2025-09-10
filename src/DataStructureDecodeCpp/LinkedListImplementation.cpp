
#include<iostream>
#include<string>
using namespace std;
# include <variant>
#include "MyDoublyLinkedList.h"

//int main() {
	//TODO: do the same fuctions on the douply linked list 
	
	/*list->InsertLast(100);
	list->InsertLast(200);
	list->InsertLast(300);
	list->InsertLast(400);

	list->PrintList();*/

	//list->InserAfter(100, 200);  //no change 
	//if (list->head == NULL)
	//	cout << "Empty list";

	//list->InsertLast(600);  
	////list->InserAfter(300, 100);  // no change 
	//list->PrintList();  //600
 //   //cout << "no chaging, selected node is not found\n";

	//
	///*list->InserAfter(350, 500);*/
	//
	//cout << "||| adding 500, 400 ||| using insertLast\n";
	//list->InsertLast(500);
	//list->InsertLast(400);
 //   list->PrintList();// 600, 500, 350, 400
	////cout << "||| Insert after head |||\n";
	////list->InserAfter(100, 600); // after head
	////list->PrintList(); //600, 100, 500, 350, 400
	//cout << "=====================================================" << endl;
	//cout << "[ | List details | ]\n";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

 //   cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;
	//cout << "=====================================================" << endl << endl;


	//list->InserAfter(50, 400); // after tail
	//cout << "||| Add 50 after 400 |||" << endl;
	//list->PrintList();
	//cout << "=====================================================";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;


	//cout << "=====================================================" << endl;


	////cout << "\nHead: " << list->head << "\nTail: " << list->tail;

	//list->InserAfter(90, 400); // previous of tail
	//cout << "||| Add 90 after 400 |||" << endl;
	//list->PrintList();
	//cout << "=====================================================";
	//cout << "[ | List details | ]\n";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;
	//cout << "=====================================================" << endl;


	//list->InserAfter(77, 400); // previous of tail
	//cout << "||| Add 77 after 400 |||" << endl;
	//list->PrintList();
	//cout << "=====================================================";
	//cout << "[ | List details | ]\n";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;
	//cout << "=====================================================" << endl;

	//list->InserAfter(80, 600); // previous of tail
	//cout << "||| Add 80 after 600 |||" << endl;
	//list->PrintList();
	//cout << "=====================================================";
	//cout << "[ | List details | ]\n";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;
	//cout << "=====================================================" << endl;

	//list->InserAfter(54, 50); // after tail
	//cout << "||| Add 54 after 50 |||" << endl;
	//list->PrintList();
	//cout << "=====================================================";
	//cout << "[ | List details | ]\n";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;
	//////////////////////////////////////////////////////////////
    
//SinglyLinkedList<string>* list1 = new SinglyLinkedList<string>();
//	
//  list1->InsertLast("Kannoza");
//  list1->InsertLast("Farahat");
//  list1->InsertLast("Mohamed");
//  list1->InsertLast("Bloul");
//	
//	cout << "Singly List 1 is : "; list1->PrintList();
//
//
//	DoublyLinkedList* list2 = new DoublyLinkedList();
//
//	list2->InsertLast(45);
//	list2->InsertLast(45.2);
//	list2->InsertLast("Mohamed");
//	list2->InsertLast("Bloul");
//	list2->InsertBefore("Taweela", "Bloul");
//	list2->InserAfter("Samakka", "Bloul");
//	
//	cout << "List 1 is : "; list2->PrintList(); 
//	cout << "List length is : " << list2->length << endl;
	/*list->InsertLast(45);
	list->InsertBefore(800, 45);
	cout << "new list : ";  list->PrintList(); 

	list->DeleteNode(list->FindNode(800));
	cout << "After deleting 800 : "; list->PrintList();
	
	cout << "Adding 85 at the start: " << endl;
	list->InsertBefore(85, list->head->data);
	list->PrintList();  
	cout << "Deleting tail (45): ";
	list->DeleteNode(list->FindNode(45));


	cout << "Adding 90, 43, 32 , 65 at the end: ";
	list->InsertLast(90);
	list->InsertLast(43);
	list->InsertLast(32);
	list->InsertLast(65);

	cout << "new list : ";  list->PrintList();

	list->DeleteNode(list->FindNode(32));
	cout << "Delete 32: "; list->PrintList();*/

	//cout << "||| adding 500, 400 ||| using insertLast\n";
	//list->InsertLast(500);
	//list->InsertLast(400);
	//list->PrintList();
	//cout << "=====================================================" << endl;
	//cout << "[ | List details | ]\n";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;
	//cout << "=====================================================" << endl << endl;


	//list->InsertBefore(50, 400); // after tail
	//cout << "||| Add 50 before 400 |||" << endl;
	//list->PrintList();
	//cout << "=====================================================";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;


	//cout << "=====================================================" << endl;


	////cout << "\nHead: " << list->head << "\nTail: " << list->tail;

	//list->InsertBefore(90, 400); // previous of tail
	//cout << "||| Add 90 before 400 |||" << endl;
	//list->PrintList();
	//cout << "=====================================================";
	//cout << "[ | List details | ]\n";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;
	//cout << "=====================================================" << endl;


	//list->InsertBefore(77, 400); // previous of tail
	//cout << "||| Add 77 before 400 |||" << endl;
	//list->PrintList();
	//cout << "=====================================================";
	//cout << "[ | List details | ]\n";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;
	//cout << "=====================================================" << endl;

	//list->InsertBefore(80, 600); // previous of tail
	//cout << "||| Add 80 before 600 |||" << endl;
	//list->PrintList();
	//cout << "=====================================================";
	//cout << "[ | List details | ]\n";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;
	//cout << "=====================================================" << endl;

	//list->InsertBefore(54, 50); // after tail
	//cout << "||| Add 54 before 50 |||" << endl;
	//list->PrintList();
	//cout << "=====================================================";
	//cout << "[ | List details | ]\n";
	//cout << "\nHead:  (obj) " << list->head << "    details: " << endl;
	//cout << "    data : " << list->head->data << endl;
	//cout << "    node next data: " << list->head->next->data << endl;

	//cout << "\nTail: (obj) " << list->tail << "    details: " << endl;
	//cout << "    data : " << list->tail->data << endl;
	//cout << "    node prev data : " << list->tail->prev->data << endl;


	//

//}