#include "BinaryTree.h"



int main() {
	BinaryTree<char>* Tree = new BinaryTree<char>('A');
	Tree->Insert('B');
	Tree->Insert('X');
	Tree->Insert('Q');
	Tree->Insert('W');
	Tree->Insert('V');
	Tree->Insert('K');
	Tree->Insert('M');
	Tree->Insert('P');
	Tree->Insert('H');

	//cout << Tree->Hight();
	Tree->PreOrder();


}