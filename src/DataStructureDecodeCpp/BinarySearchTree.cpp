# include "BinarySearchTree.h"


int main() {
	BinarySearchTree<int>* BSTree = new  BinarySearchTree<int>();
	BSTree->BSInsert(90);
	BSTree->BSInsert(10);
	BSTree->BSInsert(78);
	BSTree->BSInsert(79);
	BSTree->BSInsert(56);
	BSTree->BSInsert(87);
	BSTree->BSInsert(100);

	cout << "Original Data: ";
	BSTree->PrintInOrder();

	BSTree->BSDelete(87);
	cout << "\nTree data after delete 87 : ";
	BSTree->PrintInOrder();

	BSTree->BSDelete(79);
	cout << "\nTree data after delete 79 : ";
	BSTree->PrintInOrder();

	BSTree->BSDelete(78);
	cout << "\nTree data after delete 78 : ";
	BSTree->PrintInOrder();

	BSTree->BSDelete(10);
	cout << "\nTree data after delete 10 : ";
	BSTree->PrintInOrder();




}