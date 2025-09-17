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

	
	BSTree->Print();
	if (BSTree->BSFindParentNode(90) != NULL)
		cout << "the parent of node 100 : " << BSTree->BSFindParentNode(90)->data;

	BSTree->BSDelete(100);
	cout << "\nTree data after delete 100 : ";
	BSTree->Print();

	BSTree->BSDelete(79);
	cout << "\nTree data after delete 79 : ";
	BSTree->Print();

	BSTree->BSDelete(78);
	cout << "\nTree data after delete 78 : ";
	BSTree->Print();

	BSTree->BSDelete(10);
	cout << "\nTree data after delete 10 : ";
	BSTree->Print();




}