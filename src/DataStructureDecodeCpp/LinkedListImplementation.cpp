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


};



int main() {

	LinkedList* list = new LinkedList();
	list->InsertLast(70);
	LinkedListNode* node  = list->FindNodeWithData(70);
	cout << "node data : " << node->data << endl;
	cout << "node next : " << node->next;
}