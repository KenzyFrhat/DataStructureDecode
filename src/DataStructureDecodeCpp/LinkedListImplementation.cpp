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
private:
	LinkedListNode* currentNode = NULL;

public:
	LinkedListIterator() { currentNode = NULL; }

	LinkedListIterator(LinkedListNode* node) { currentNode = node; }

	int CurrentData() {
		return currentNode->data;
	}


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
		for (LinkedListIterator itr = this->begin(); itr.CurrentData() != NULL; itr.next()) {
			cout << itr.CurrentData() << " -> ";
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


};



int main() {
	LinkedList* linkedlist = new LinkedList();
	cout << "The head of linked list is " << linkedlist->head << endl;
	LinkedListNode* node = new LinkedListNode(88);

	for (int i = 1; i < 11; i++) {
		cout << "index " << i - 1 << ": " << i << endl;
		linkedlist->InsertLast(i);
	}

	linkedlist->PrintList();


}