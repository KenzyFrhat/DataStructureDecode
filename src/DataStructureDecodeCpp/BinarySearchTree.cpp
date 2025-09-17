# include "BinarySearchTree.h"


int main() {
	BinarySearchTree<int>* BSTree = new  BinarySearchTree<int>();
	
	
	BSTree->Print();

	cout << " data of node 87 : " ;
	if (BSTree->BSFindNode(87) != NULL) {
		cout << BSTree->BSFindNode(87)->data;
	}

	else {
		cout << "not found";
	}
}