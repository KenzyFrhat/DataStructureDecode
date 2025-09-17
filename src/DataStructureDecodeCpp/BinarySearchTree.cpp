# include "BinarySearchTree.h"


int main() {
	BinarySearchTree<int>* BSTree = new  BinarySearchTree<int>();
	BSTree->BSInsert(1);
	BSTree->BSInsert(2);
	BSTree->BSInsert(3);
	BSTree->BSInsert(4);
	BSTree->BSInsert(5);
	BSTree->BSInsert(6);
	BSTree->BSInsert(7);

	BSTree->Print();

	BSTree->Balance();

	cout << "\nAfter balancing process: ";

	BSTree->Print();




}