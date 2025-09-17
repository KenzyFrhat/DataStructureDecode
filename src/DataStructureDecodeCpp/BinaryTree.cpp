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
    Tree->Insert('I');


	//cout << Tree->Hight();
	cout << "PreOrder Treaversal: ";
	Tree->PreOrder();
	cout << "\nInorder Traversal : ";
	Tree->InOrder();
	cout << "\nPostorder Traversal : ";
	Tree->PostOrder();

	TreeNode<char>* LastNode = Tree->FindLastNode();
	cout << "\nThe last node is " << LastNode->data << endl; 
	

	TreeNode<char>* Parent = Tree->FindParentNode(LastNode->data);

	cout << "\nIt is position is : " << Tree->LeftOrRight(Parent, LastNode); 

}