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

	enum enLeftOrRight {Left, Right};
	
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

		if (node->Right != NULL)
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

	TreeNode<T>* FindNode(T _data) {

		if (this->Root == NULL) {
			cout << "Empty Binary Tree!" << endl;
			return;
		}

		queue< TreeNode<T>* > q;
		q.push(this->Root);


		while (!q.empty()) {
			TreeNode<T>* currentNode = q.front();
			q.pop();

			if (currentNode->data == _data) {
				return currentNode;
			}

			if (currentNode->Left != NULL) {
				q.push(currentNode->Left);
			}

			if (currentNode->Right != NULL) {
				q.push(currentNode->Right);
			}

		}// while

		return NULL;

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

	}// print


	TreeNode<T>* InternalFindLastNode(TreeNode<T>* node) {
		int LeftHight = 0;
		int RightHight = 0;
		int MaxHight = 0;

		
		(node->Right == NULL ? RightHight = 0 : RightHight = InternalHight(node->Right));
        (node->Left == NULL ? LeftHight = 0 : LeftHight = InternalHight(node->Left));

		MaxHight = max(LeftHight, RightHight);
		
		if (MaxHight == 0)
			return node;
		

		(MaxHight == RightHight ? InternalFindLastNode(node->Right) : InternalFindLastNode(node->Left));


	}//InternalFindLastNode

	TreeNode<T>* FindLastNode() {
		if (this->Root == NULL)
			return NULL;

		return InternalFindLastNode(this->Root);
	}//FindLastNode


	enLeftOrRight LeftOrRight(TreeNode<T>* nodeParent, TreeNode<T>* nodeChild) {
		if (nodeParent->Left == nodeChild) {
			return enLeftOrRight::Left;
		}
		else if (nodeParent->Right == nodeChild) {
			return enLeftOrRight::Right;
		}
		else {
			throw exception("SomeThing Wrong!");
		}
	}//LeftOrRight



	void Delete(T data) {
		// find chosen node to be deleted // treavese by level 
		TreeNode* node = FindNode(data);
		if (node == NULL) return; // node is not exist !
		TreeNode* nodeParent = FindParentNode(data);

		TreeNode* LastNode =  FindLastNode();
		TreeNode* LastNodeParent = FindParentNode(LastNode->data);

		LastNode->Left = node->Left;
		LastNode->Right = node->Right;


		// make node parent points to the last node 
		if (enLeftOrRight(nodeParent, node) == enLeftOrRight::Left) {
			nodeParent->Left = LastNode;
		}

		else {
			nodeParent->Right = LastNode;
		}

	
		// make parent of last node points to null
		if (enLeftOrRight(LastNodeParent, LastNode) == enLeftOrRight::Left) {
			LastNodeParent->Left = NULL;
		}
		else  {
			LastNodeParent->Right = NULL;
		}
		

		delete node;

	}



};//BinaryTree


