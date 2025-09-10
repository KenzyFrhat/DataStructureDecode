#pragma once

#include<iostream>
#include<string>
using namespace std;
#include <variant>
	

namespace MyDoublyLinkedList
{

// Define a type alias for readability
	using MyVariant = std::variant<int, double, string>;
	// Overload operator<< so we can print MyVariant directly
	ostream& operator<<(ostream& os, const MyVariant& v) {
		visit([&os](auto&& val) { os << val; }, v);
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
	private:
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

		DoublyLinkedList(DoublyLinkedList& other) {
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
		void Delete(MyVariant data) {
			this->DeleteNode(this->FindNode(data));
		}



	};

}
