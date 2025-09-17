#pragma once

# include <iostream>
# include <string>
#include <queue>
# include <vector>
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

	void InternalPrintInOrder(TreeNode<T>* node) {

		if (node->Left != NULL)
			InternalPrintInOrder(node->Left);

		cout << node->data << " -> ";

		if (node->Right)
			InternalPrintInOrder(node->Right);

	}

	void PrintInOrder() {
		if (this->Root == NULL)
		{
			cout << "Empty Tree!";
			return;
		}

		InternalPrintInOrder(this->Root);
	}


	


	TreeNode<T>* BSFindNode(T _data) {

		if (this->Root == NULL) return NULL;
		TreeNode<T>* currentNode = this->Root;
		while (currentNode != NULL) { // if exist the while loop -> tree is finished 
			if (_data == currentNode->data) {
				return currentNode;
			}
			if (_data > currentNode->data) {
				currentNode = currentNode->Right;
			}
			else { // _data < currentNode->data
				currentNode = currentNode->Left;
			}
		}

		return NULL; // node not found 
	}// BSFindNode


	TreeNode<T>* BSFindParentNode(T _data) {

		if (this->Root == NULL)
			return NULL;

		if (_data == this->Root->data)
			return NULL; // no parent for the root node


	    TreeNode<T>* currentNode = this->Root;  // start with Root node 

		while (currentNode != NULL) { // if exist the while loop -> tree is finished 
			
			if (_data > currentNode->data) { // right
				if (currentNode->Right == NULL)
					return NULL; // reached at the end but not found !

				if (_data == currentNode->Right->data)
					return currentNode;
				else
					currentNode = currentNode->Right;
			}//big if

			else {
				if (_data < currentNode->data) { // Left
					if (currentNode->Left == NULL)
						return NULL; // reached at the end but not found !

					if (_data == currentNode->Left->data)
						return currentNode;
					else
						currentNode = currentNode->Left;
				}
			}// big else


		}// while

		return NULL; // node not found 

	}// BSFindNode

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


	private:
	void BSDelete_LeafNode(TreeNode<T>* NodeToDelete) {
		TreeNode<T>* parent = FindParentNode(NodeToDelete->data);

		if (parent == NULL) // it is the root 
		{
			this->Root = NULL;
			return;
		}

		if(parent->Left == NodeToDelete)
		{
			parent->Left = NULL;
		}
		else if(parent->Right == NodeToDelete){ //TODO: isn't it supposed to be both NodeToDelete and (parent->Left Or parent->Right) the same data and any operation on ( parent -> left for example ) or NodeToDelete must affect the data ?? 
			parent->Right = NULL;
		}

		 //NodeToDelete = NULL;

		delete NodeToDelete;

	}//BSDelete_LeafNode

	void BSDelete_NodeHasOneChild(TreeNode<T>* NodeToDelete) {
		// get the existing childNode
		TreeNode<T>* ChildNode = (NodeToDelete->Left == NULL ? NodeToDelete->Right : NodeToDelete->Left);
		NodeToDelete->data = ChildNode->data; // change the data 

		NodeToDelete->Left = ChildNode->Left;
		NodeToDelete->Right = ChildNode->Right;

		ChildNode = NULL;
		delete ChildNode;


	}//BSDelete_NodeHasOneChild

	void BSDelete_NodeHasTwoChilds(TreeNode<T>* NodeToDelete) {
    
		// move to the right subtree 
		TreeNode<T>* currentNode = NodeToDelete->Right;
		TreeNode<T>* parent = NULL;

		// search for the smallest value ( most left node)
		while (currentNode->Left != NULL) { //-> break -> if the next left is null 
			parent = currentNode;
			currentNode = currentNode->Left;
		}

		// move value of the current node to the deleted node 
		NodeToDelete->data = currentNode->data;

		if (parent == NULL) //-> node to delete is the parent  
		{   // get the right subtree before delete its point (currentNode)
			NodeToDelete->Right = currentNode->Right;
			// no need to do the same with the left side -> there is no left side !
			
		}
		else  {
		   // get the right subtree before delete its point (currentNode)
			parent->Left = currentNode->Right;
		}

		// delete hole node with pointers
		currentNode = NULL;
		delete currentNode;

	}//BSDelete_NodeHasTwoChilds

	public:
	void BSDelete(T _data) {
		if (this->Root == NULL)
			return; // tree is empty !

		// find node 
		TreeNode<T>* NodeToDelete =  BSFindNode(_data);

		if (NodeToDelete == NULL)
			return; // node not found !

		if (NodeToDelete->Left == NULL && NodeToDelete->Right == NULL) { // case 1   LeafNode
			BSDelete_LeafNode(NodeToDelete);
		}
		else if (NodeToDelete->Left != NULL && NodeToDelete->Right != NULL) {  // case 3   NodeHasTwoChilds
			BSDelete_NodeHasTwoChilds(NodeToDelete);
		}
		else { // case 2 NodeHasOneChild
            BSDelete_NodeHasOneChild(NodeToDelete);
		}


	}//BSDelete

	void CopyDataInOrderToArray(TreeNode<T>* StartNode, vector<TreeNode<T>*>& BSTreeNodes) {
		if (StartNode == NULL) {
			return;
		}
		CopyDataInOrderToArray(StartNode->Left, BSTreeNodes);
		BSTreeNodes.push_back(StartNode);
		CopyDataInOrderToArray(StartNode->Right, BSTreeNodes);

	}

	TreeNode<T>* RecursiveBalanced(int start, int end, vector< TreeNode<T>* > &BSTreeNodes) {
		if (start > end) return NULL;
		int mid = (start + end) / 2;
		TreeNode<T>* newRoot = BSTreeNodes[mid];
		newRoot->Left = RecursiveBalanced(start, mid - 1, BSTreeNodes);  // left part 
		newRoot->Right = RecursiveBalanced(mid + 1, end, BSTreeNodes);
		return newRoot;
	}
	
	void Balance() {
		vector<TreeNode<T>*> BSTreeNodes ;
		CopyDataInOrderToArray(this->Root, BSTreeNodes);
		this->Root = RecursiveBalanced(0, BSTreeNodes.size() - 1, BSTreeNodes);
	}


	///////////////////////////////////////////////
	
	

	


};//BinarySearchClass