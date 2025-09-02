#include<iostream>
#include<string>
using namespace std;

class LinkedListNode {
public:
	int data = 0;
	LinkedListNode* next = NULL;

	LinkedListNode(int _data) {
		this->data = _data;
		this->next = NULL;
	}
};


class LinkedListIterator {
public:
	LinkedListNode* currentNode = NULL;

public:
	LinkedListIterator() { }

	LinkedListIterator(LinkedListNode* node) { currentNode = node; }

	//TODO: the return data type may be NULL which is not suited with the return data type int CurrentData() 
	/*int CurrentData() {
		return currentNode->data;
	}*/


	LinkedListIterator next() {
		this->currentNode = this->currentNode->next;
		return *this;
	}

};

class LinkedList {
public:
	LinkedListNode* head;
	LinkedListNode* tail;
	int length;
	LinkedListIterator begin() {
		LinkedListIterator itr(this->head);
		return itr;
	}

	void PrintList() {
		for (LinkedListIterator itr = this->begin(); itr.currentNode != NULL; itr.next()) {
			cout << itr.currentNode->data << " -> ";
		}
		cout << '\n';
	}

	void InsertLast(int _data) {
		LinkedListNode* AddedNode = new LinkedListNode(_data);
		if (this->head == NULL) {
			this->head = AddedNode;
			this->tail = AddedNode;
		}
		else {
			this->tail->next = AddedNode;
			this->tail = AddedNode;
		}
	}

	LinkedListNode* FindNodeWithData(int data) {
		//validations
		// linkedlist is empty -> null
		if (this->head == NULL) {
			return NULL;
		}

		// use iterator to itrate through list and check for the linked list data 
		for (LinkedListIterator itr = this->begin(); itr.currentNode != NULL; itr.next()) {
			if (itr.currentNode->data == data)
				return  itr.currentNode;
		}

		return NULL;
	}


	LinkedListNode* InsertAfter(int _data, LinkedListNode* nodeToInsertAfter) {
		if (this->head == NULL || nodeToInsertAfter == NULL)  //no data , no list -> no action
			return NULL;

		LinkedListNode* newNode = new LinkedListNode(_data);

		//default state 
		newNode->next = nodeToInsertAfter->next;
		nodeToInsertAfter->next = newNode;
		
        if (this->tail == nodeToInsertAfter)
			this->tail = newNode;

		return newNode;

	}

	void InsertBefore(int newData, int DataAfter) {
		LinkedListNode* newNode = new LinkedListNode(newData);
		LinkedListNode* nodeAfter = NULL; 
		LinkedListNode* nodeBefore = NULL;

		// validation
		// list is empty -> return  null 
		if (this->head == NULL)  return ;  //list is empty
		
		if (this->head->data == DataAfter) {
			newNode->next = this->head; // insert as head node
			this->head = newNode;
			return; 
		}
        
		// search for existing of the nodeAfter
		for (LinkedListIterator itr = this->begin(); itr.currentNode->next != NULL; itr.next()) {
			if (itr.currentNode->next->data == DataAfter) {
				nodeBefore = itr.currentNode;
				nodeAfter = itr.currentNode->next;
			}
		}

		if (nodeAfter == NULL)  return; //node not found 

		newNode->next = nodeAfter; // insert in the list middle
		nodeBefore->next = newNode;

	}

	LinkedListNode* FindParent(LinkedListNode* node) {
		for (LinkedListIterator itr = this->begin(); itr.currentNode->next != NULL; itr.next()) {
			if (itr.currentNode->next == node) {
				return itr.currentNode ;
			}
		}
	}

	void DeleteNode(LinkedListNode* node) {
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
			LinkedListNode* parentNode = FindParent(node);
			parentNode->next = node->next;
			// update tail if needed
			if (this->tail == node) {
				this->tail = parentNode;
			}
		}

		length--;

	}

	void Delete(int data) {
		//get node 
		LinkedListNode* node = FindNodeWithData(data);
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



int main() {

	LinkedList* list = new LinkedList();
	list->InsertLast(77);
	list->PrintList(); cout << endl;
	list->InsertBefore(22, 77); // 22-> 77
	list->PrintList(); cout << endl;
	list->InsertBefore(55, 77); // 22-> 55-> 77
	list->PrintList(); cout << endl;

	list->InsertBefore(88, 90); // no changing
	list->PrintList(); cout << " no changing " << endl;


	LinkedList* emptyList = new LinkedList();
	cout << "The head of list2 : " << emptyList->head;
	emptyList->InsertBefore(99, 100); //no change=ing
	cout << "The head of list2 after tring adding before : " << emptyList->head;



}