#pragma once

#include<iostream>
#include<string>
using namespace std;

namespace MyNamespace
{
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
		LinkedListIterator() {}
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
		bool unique = false;
		SinglyLinkedList(bool unique = false) {
			this->head = NULL;
			this->tail = NULL;
			this->length = 0;
			this->unique = false;
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


		bool IsExist(T data) {
			return (this->FindNodeWithData(data) ? true : false);
		}

		bool CanInsert(T data) {
			return !(this->unique && IsExist(data));
		}


		void InsertLast(T _data) {
			SinglyLinkedListNode<T>* AddedNode = new SinglyLinkedListNode<T>(_data);
			if (!CanInsert(_data)) return; // no action if unique is true and data already exists
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


		SinglyLinkedListNode<T>* InsertAfter(T newData, T data) {
			if (this->head == NULL)  // list is empty
				return;
			if (!CanInsert(newData)) return; // no action if unique is true and data already exists

			SinglyLinkedListNode<T>* SelectedNode = this->FindNodeWithData(data);
			if (SelectedNode == NULL)
				return;  // node is not found

			SinglyLinkedListNode<T>* newNode = new SinglyLinkedListNode<T>(newData);

			newNode->next = SelectedNode->next;
			SelectedNode->next = newNode;

			if (SelectedNode == this->tail) {
				newNode = this->tail;
			}

			length++;

		}

		void InsertBefore(T newData, T Data) {
			if (this->head == NULL)  return;  //list is empty
			if (!CanInsert(newData)) return; // no action if unique is true and data already exists
			SinglyLinkedListNode<T>* SelectedNode = this->FindNodeWithData(Data);
			if (SelectedNode == NULL) return;  // node not found
			// create the new node to be inserted
			SinglyLinkedListNode<T>* newNode = new SinglyLinkedListNode<T>(newData);
			// find parent of selected node
			SinglyLinkedListNode<T>* parentNode = FindParent(SelectedNode);
			// progress
			newNode->next = SelectedNode;
			if (parentNode == NULL) { // selected node is head node
				this->head = newNode;
			}
			length++;

		}

		void InsertHead(T data) {
			this->InsertBefore(data, this->head->data);
		}


		SinglyLinkedListNode<T>* FindParent(SinglyLinkedListNode<T>* node) {
			for (LinkedListIterator<T> itr = this->begin(); itr.currentNode->next != NULL; itr.next()) {
				if (itr.currentNode->next == node) {
					return itr.currentNode;
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
			delete node;
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

}
