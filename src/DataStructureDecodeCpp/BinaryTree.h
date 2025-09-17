#pragma once

# include <iostream>
#include <algorithm>
# include <string>
#include <queue>
using namespace std;

template <typename Tdata>
class TreeNode {
public:
	TreeNode<Tdata>* Left;
	TreeNode<Tdata>* Right;
	Tdata data;

public:
	TreeNode(Tdata _data) {
		this->Left = NULL;
		this->Right = NULL;
		this->data = _data;
	}

	Tdata Data() {
		return this->data;
	}

};

template <typename T>
class BinaryTree {
private:
	TreeNode<T>* Root;

public:
	BinaryTree(T _data) {
		Root = new TreeNode<T>(_data);

	}

	BinaryTree() {
		Root = NULL;

	}

	~BinaryTree() { delete Root; }

	void Insert(T _data) { // traverse by level using queue
		TreeNode<T>* newNode = new TreeNode<T>(_data);
		if (Root == NULL) {
			Root = newNode;
			return;
		}
		queue< TreeNode<T>* > q; 
		q.push(Root);

		while (!q.empty()) {
			TreeNode<T>* currentNode = q.front();
			q.pop();
			if (currentNode->Left == NULL) {
				currentNode->Left = newNode;
				break;
			}
			else {
				q.push(currentNode->Left);
			}
			if (currentNode->Right == NULL) {
				currentNode->Right = newNode;
				break;
			}
			else {
				q.push(currentNode->Right);
			}

		}// while


	}// Insert


	void print() {

		if (this->Root == NULL) {
			cout << "Empty Binary Tree!" << endl;
            return;
		}
			
		queue< TreeNode<T>* > q;
		q.push(Root);
		while (!q.empty()) {
			TreeNode<T>* currentNode = q.front();
			q.pop();
			cout << currentNode->Data();
			
			if (currentNode->Left != NULL) {
				q.push(currentNode->Left);
			}

			if (currentNode->Right != NULL) {
				q.push(currentNode->Right);
			}

		}// while

	}// print

	int InternalHight(TreeNode<T>* Node) {
		if (Node == NULL) return 0;
		return 1 + max(InternalHight(Node->Left), InternalHight(Node->Right));
	}

	int Hight() {
		return InternalHight(this->Root);
	}

	void InternalPreOrder(TreeNode<T>* node) {
       
		cout << node->data << " -> ";

		if (node->Left != NULL) {
			
			InternalPreOrder(node->Left);
		}

	    if (node->Right != NULL) {

			InternalPreOrder(node->Right);

		}
	}

	void PreOrder() {

		if (this->Root == NULL) {
			cout << "Empty Tree!";
			return;
		}


		InternalPreOrder(this->Root);
	}
	

	void InternalInOrder(TreeNode<T>* node) {

		if (node->Left != NULL)
			InternalInOrder(node->Left);
		    
		cout << node->data << " -> ";

		if (node->Right)
			InternalInOrder(node->Right);

	}

	void InOrder() {
		if (this->Root == NULL)
		{
			cout << "Empty Tree!";
			return;
		}

		InternalInOrder(this->Root);
	}


	void InternalPostOrder(TreeNode<T>* node) {

		if (node->Left != NULL)
			InternalPostOrder(node->Left);

		if (node->Right)
		InternalPostOrder(node->Right);

	
        cout << node->data << " -> ";
	}

	void PostOrder() {
		if(this->Root == NULL) {
			cout << "Empty Tree!";
			return;
		}

		InternalPostOrder(this->Root);

	}

};//BinaryTree


