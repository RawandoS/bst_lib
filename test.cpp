#include <iostream>
#include "Node.h"
using namespace std;

int main() {
	Node* root = new Node(64);
	root = root->insertR(32);
	root = root->insertR(15);
	root = root->insertR(40);
	root = root->insertR(80);
	root = root->insertR(70);

	root->inOrder();

	return 0;
}