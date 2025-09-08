//TODO: make it generic type using templates
//TODO: add copy constructor and assignment operator to avoid shallow copy problems


#include<iostream>
#include<string>
using namespace std;

template <typename T>
class SinglyLinkedListNode {
public:
	T data = T{};
	SinglyLinkedListNode<T>* next = NULL;

	SinglyLinkedListNode(T _data) {
		this->data = _data;
		this->next = NULL;
	}
};



template <typename T>
class LinkedListIterator {
public:
	SinglyLinkedListNode<T>* currentNode = NULL;

public:
	LinkedListIterator() { }
	LinkedListIterator(SinglyLinkedListNode<T>* node) { currentNode = node; }

	//TODO: the return data type may be NULL which is not suited with the return data type int CurrentData() 
	/*int CurrentData() {
		return currentNode->data;
	}*/

	T CurrentData() {
			return currentNode->data;
	}


	LinkedListIterator next() {
		this->currentNode = this->currentNode->next;
		return *this;
	}

	SinglyLinkedListNode<T>* CurrentNode() {
		return this->currentNode;
	}

};


template <typename T>
class SinglyLinkedList {
public:
	SinglyLinkedListNode<T>* head;
	SinglyLinkedListNode<T>* tail;
	int length;

	SinglyLinkedList() {
		this->head = NULL;
		this->tail = NULL;
		this->length = 0;
	}

	SinglyLinkedList(SinglyLinkedList& other) {
		this->head = other.head;
		this->tail = other.tail;

		//loop thriugh other list and copy each node data to new node in this list
		for (LinkedListIterator<T> itr = other.begin(); itr.CurrentNode() != NULL; itr.next()) {
			this->InsertLast(itr.CurrentData());
		}
	}

	LinkedListIterator<T> begin() {
		LinkedListIterator<T> itr(this->head);
		return itr;
	}

	void PrintList() {
		if (this->head == NULL) {
			cout << "Empty List";
			return;
		}
		for (LinkedListIterator<T> itr = this->begin(); itr.currentNode != NULL; itr.next()) {
			cout << itr.currentNode->data << " -> ";
		}
		cout << '\n';
	}


	void InsertLast(T _data) {
		SinglyLinkedListNode<T>* AddedNode = new SinglyLinkedListNode<T>(_data);
		if (this->head == NULL) {
			this->head = AddedNode;
			this->tail = AddedNode;
		}
		else {
			this->tail->next = AddedNode;
			this->tail = AddedNode;
		}
		length++;
	}

	SinglyLinkedListNode<T>* FindNodeWithData(T _data) {
		//validations
		// linkedlist is empty -> null
		if (this->head == NULL) {
			return NULL;
		}

		// use iterator to itrate through list and check for the linked list data 
		for (LinkedListIterator<T> itr = this->begin(); itr.currentNode != NULL; itr.next()) {
			if (itr.currentNode->data == _data)
				return  itr.currentNode;
		}

		return NULL;
	}


	SinglyLinkedListNode<T>* InsertAfter(T _data, SinglyLinkedListNode<T>* nodeToInsertAfter) {
		if (this->head == NULL || nodeToInsertAfter == NULL)  //no data , no list -> no action
			return NULL;

		SinglyLinkedListNode<T>* newNode = new SinglyLinkedListNode<T>(_data);

		//default state 
		newNode->next = nodeToInsertAfter->next;
		nodeToInsertAfter->next = newNode;
		
        if (this->tail == nodeToInsertAfter)
			this->tail = newNode;
		length++;
		return newNode;

	}

	void InsertBefore(T newData, T DataAfter) {
		SinglyLinkedListNode<T>* newNode = new SinglyLinkedListNode<T>(newData);
		SinglyLinkedListNode<T>* nodeAfter = NULL; 
		SinglyLinkedListNode<T>* nodeBefore = NULL;

		// validation
		// list is empty -> return  null 
		if (this->head == NULL)  return ;  //list is empty
		
		if (this->head->data == DataAfter) {
			newNode->next = this->head; // insert as head node
			this->head = newNode;
			return; 
		}
        
		// search for existing of the nodeAfter
		for (LinkedListIterator<T> itr = this->begin(); itr.currentNode->next != NULL; itr.next()) {
			if (itr.currentNode->next->data == DataAfter) {
				nodeBefore = itr.currentNode;
				nodeAfter = itr.currentNode->next;
			}
		}

		if (nodeAfter == NULL)  return; //node not found 

		newNode->next = nodeAfter; // insert in the list middle
		nodeBefore->next = newNode;
		length++;

	}

	SinglyLinkedListNode<T>* FindParent(SinglyLinkedListNode<T>* node) {
		for (LinkedListIterator<T> itr = this->begin(); itr.currentNode->next != NULL; itr.next()) {
			if (itr.currentNode->next == node) {
				return itr.currentNode ;
			}
		}
	}

	void DeleteNode(SinglyLinkedListNode<T>* node) {
		if (node == NULL)  return;

		// if length = 1 , node is the head and tail , delete head and tail value
		if (this->head == this->tail) {
			this->head = NULL;
			this->tail = NULL;
		}

		// node is head node
		else if (this->head == node) {
			this->head = node->next;
		}

		else {
			//search for parent
			SinglyLinkedListNode<T>* parentNode = FindParent(node);
			parentNode->next = node->next;
			// update tail if needed
			if (this->tail == node) {
				this->tail = parentNode;
			}
		}

		length--;

	}

	void Delete(T data) {
		//get node 
		SinglyLinkedListNode<T>* node = FindNodeWithData(data);
		if (node == NULL) return;
		DeleteNode(node);

	}

	void DeleteHead() {
		if (this->head == NULL)
			return;
		DeleteNode(this->head);
	}

	void DeleteTail() {
		if (this->tail == NULL) return;
		DeleteNode(this->tail);
	}

};

//////////////////////////////////////////////////////////////Doubly linked list/////////////////////////////////////////////////////


#include <variant>
// Define a type alias for readability
using MyVariant = std::variant<int, double, string>;
// Overload operator<< so we can print MyVariant directly
ostream& operator<<(ostream& os, const MyVariant& v) {
	std::visit([&os](auto&& val) { os << val; }, v);
	return os;
}

class DoublyLinkedListNode {

public:
	MyVariant data = NULL;
	DoublyLinkedListNode* next = NULL;
	DoublyLinkedListNode* prev = NULL;

	DoublyLinkedListNode(MyVariant _data) {
		this->data = _data;
		this->next = NULL;
		this->prev = NULL;
	}
};



class DoublyLinkedListIterator {
private :
	DoublyLinkedListNode* currentNode = NULL;

public:
	DoublyLinkedListIterator(DoublyLinkedListNode* node) {
		this->currentNode = node;

	}

	DoublyLinkedListNode* CurrentNode() {
		return this->currentNode;
	}

	MyVariant CurrentData() {
		return currentNode->data;
	}

	DoublyLinkedListIterator next() {
		this->currentNode = this->currentNode->next;
		return *this;

		//TODO: what is the real difference between this->currentNode = this->currentNode->next; return *this; and return new DoubdlyLinkedListIterator(currentNode->next);
	}
};



class DoublyLinkedList {
public:
	DoublyLinkedListNode* head = NULL;
	DoublyLinkedListNode* tail = NULL;
	int length = 0;

	DoublyLinkedList() {
		this->head = NULL;
		this->tail = NULL;
		this->length = 0;
	}

    DoublyLinkedList( DoublyLinkedList& other) {
		this->head = other.head;
		this->tail = other.tail;

		//loop thriugh other list and copy each node data to new node in this list
		for (DoublyLinkedListIterator itr = other.begin(); itr.CurrentNode() != NULL; itr.next()) {
			this->InsertLast(itr.CurrentData());
		}
	}



	DoublyLinkedListIterator begin() {
		return DoublyLinkedListIterator(this->head);
	}

	DoublyLinkedListNode* FindNode(MyVariant data) {
		if (this->head == NULL) return NULL; // list is empty

		for (DoublyLinkedListIterator itr = this->begin(); itr.CurrentNode() != NULL; itr.next()) {
			if (itr.CurrentData() == data) {
				cout << "Correct value\nThe current data is  " << itr.CurrentData() << " and the searched data is " << data << endl;
				return itr.CurrentNode();
			}
		}
		return NULL;
	}
	// print doubly linked list 
	void PrintList() {
		if (this->head == NULL) {
			cout << "Empty List";
			return;
		}

		for (DoublyLinkedListIterator itr = this->begin(); itr.CurrentNode() != NULL; itr.next()) {
			cout << itr.CurrentData() << " <=> ";
		}
		cout << '\n';
	}


	// insert Last
	void InsertLast(MyVariant data) {
		DoublyLinkedListNode* node = new  DoublyLinkedListNode(data);
		if (this->head == NULL) { //list is empty
			this->head = node;
			this->tail = node;

		}
		else {
		this->tail->next = node;
		node->prev = this->tail;
		this->tail = node;
	}
		length++;

	}

	// insert After 
	void InserAfter(MyVariant insertedData, MyVariant beforeData) {
		if (this->head == NULL) return; // list is empty, no action
		DoublyLinkedListNode* NodeBefore = FindNode(beforeData);
		if (NodeBefore == NULL)
		{
			cout << "Node not found !" << endl;
			return;
		}

		DoublyLinkedListNode* InsertedNode = new DoublyLinkedListNode(insertedData); // creating no to be inserted

		// insertion process at the end
		if (this->tail == NodeBefore) {
			InsertedNode->next = NULL;
			InsertedNode->prev = this->tail;
			this->tail->next = InsertedNode;
			this->tail = InsertedNode;
		}
		else {
			//insertion process in the middle
			cout << "tail node is " << this->tail->data << endl;
			InsertedNode->next = NodeBefore->next;
			InsertedNode->prev = NodeBefore;
			NodeBefore->next->prev = InsertedNode;
			NodeBefore->next = InsertedNode;
		}

		length++;
		// any chaning to NodeBefore will effect the existing data inside the linkedlist - they are just pointers that point to the same data 
		// so in case the nodeBefore was the head - no nead to change head data it is already has been changed by the other pointer NodeBefore

		/*if (NodeBefore == this->tail->prev) {
			this->tail->prev = InsertedNode;
			return;
		}*/

		

	}

	// insert Before
	void InsertBefore(MyVariant InsertedData, MyVariant SelectedData) {
		// validation
		if (this->head == NULL)
			return;

		// search for SelectedNode
		DoublyLinkedListNode* SelectedNode = FindNode(SelectedData);
		if (SelectedNode == NULL)
			return;

		DoublyLinkedListNode* InsertedNode = new DoublyLinkedListNode(InsertedData);
		// progress

		InsertedNode->next = SelectedNode;
		InsertedNode->prev = SelectedNode->prev;

		if (SelectedNode->prev != NULL) {
			SelectedNode->prev->next = InsertedNode;
		}

		SelectedNode->prev = InsertedNode;

		/*if(this->head->next == SelectedNode) {
			this->head->next = InsertedNode;
		}*/

	    if (SelectedNode == this->head) {
			this->head = InsertedNode;
		}
	
		length++;
	}
	// delete node
	void DeleteNode(DoublyLinkedListNode* NodeToDelete) {
		if (this->head == NULL)  return;

		if (NodeToDelete == NULL) return;

		if (this->head == this->tail) {
			this->head = NULL;
			return;
		}

		if (NodeToDelete == this->head) {
			this->head = this->head->next;
		}

		else if (NodeToDelete == this->tail) {
			this->tail = this->tail->prev;
		}
		else {
			NodeToDelete->next->prev = NodeToDelete->prev;
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		NodeToDelete = NULL;

	}
	// delete head
	void DeleteHead() {
		this->DeleteNode(this->head);
	}
	// delete tail
	void DeleteTail() {
		this->DeleteNode(this->tail);
	}
	// delete by data 
	void Delete(int data) {
		this->DeleteNode(this->FindNode(data));
	}
	
	

};



int main() {
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
    
SinglyLinkedList<string>* list1 = new SinglyLinkedList<string>();
	
  list1->InsertLast("Kannoza");
  list1->InsertLast("Farahat");
  list1->InsertLast("Mohamed");
  list1->InsertLast("Bloul");
	
	cout << "Singly List 1 is : "; list1->PrintList();


	DoublyLinkedList* list2 = new DoublyLinkedList();

	list2->InsertLast(45);
	list2->InsertLast(45.2);
	list2->InsertLast("Mohamed");
	list2->InsertLast("Bloul");
	list2->InsertBefore("Taweela", "Bloul");
	list2->InserAfter("Samakka", "Bloul");
	
	cout << "List 1 is : "; list2->PrintList(); 
	cout << "List length is : " << list2->length << endl;
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



}