# include "BinarySearchTree.h"


int main() {
	BinarySearchTree<int>* BSTree = new  BinarySearchTree<int>();
	BSTree->BSInsert(90);
	BSTree->BSInsert(10);
	BSTree->BSInsert(78);
	BSTree->BSInsert(79);
	BSTree->BSInsert(56);
	BSTree->BSInsert(87);
	
	BSTree->Print();

	cout << "Parent of node 87 : " << BSTree->FindParentNode(87)->data; 


}