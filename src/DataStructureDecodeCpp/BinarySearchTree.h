#pragma once

# include <iostream>
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
class BinarySearchTree {
private:
	TreeNode<T>* Root;

public:
	BinarySearchTree(T _data) {
		Root = new TreeNode<T>(_data);

	}

	BinarySearchTree() {
		Root = NULL;

	}

	~BinarySearchTree() { delete Root; }

	enum enLeftOrRight { Left, Right };

	void BSInsert(T _data) {
		TreeNode<T>* node = new TreeNode<T>(_data);
		if (this->Root == NULL) {
			this->Root = node;
			return;
		}

        TreeNode<T>* currentNode = this->Root;
		while (true) {
			if (_data < currentNode->data) { // lower -> insert in the left 
				if (currentNode->Left == NULL) {
					currentNode->Left = node;
					break;
				}
				else {
					currentNode = currentNode->Left;
				}
			} // big if
			else {
				if (currentNode->Right == NULL) {
					currentNode->Right = node;
					break;
				}
				else {
					currentNode = currentNode->Right;
				}
			}// big else

		}//while

	}//BSInsert


	void Print() {

		if (this->Root == NULL) {
			cout << "Empty Binary Tree!" << endl;
			return;
		}

		queue< TreeNode<T>* > q;
		q.push(Root);
		while (!q.empty()) {
			TreeNode<T>* currentNode = q.front();
			q.pop();
			cout  << currentNode->Data() << "-> ";

			if (currentNode->Left != NULL) {
				q.push(currentNode->Left);
			}

			if (currentNode->Right != NULL) {
				q.push(currentNode->Right);
			}

		}// while

	}// print

	TreeNode<T>* FindParentNode(T _data) {

		if (this->Root == NULL) {
			cout << "Empty Binary Tree!" << endl;
			return NULL;
		}

		queue< TreeNode<T>* > q;
		q.push(this->Root);


		while (!q.empty()) {
			TreeNode<T>* currentNode = q.front();
			q.pop();


			if (currentNode->Left != NULL) {

				if (currentNode->Left->data == _data) {
					return currentNode;
				}

				q.push(currentNode->Left);
			}

			if (currentNode->Right != NULL) {

				if (currentNode->Right->data == _data) {
					return currentNode;
				}

				q.push(currentNode->Right);
			}

		}// while

		return NULL;

	}// FindNodeParent

};//BinarySearchClass