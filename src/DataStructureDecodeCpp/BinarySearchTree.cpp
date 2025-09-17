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
	if (BSTree->BSFindParentNode(90) != NULL)
		cout << "the parent of node 100 : " << BSTree->BSFindParentNode(90)->data;


}