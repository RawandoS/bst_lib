#include <iostream>
#include "Node.h"
using namespace std;

int main() {
	Node* root = new Node(64);
	root = root->insertI(32)->insertI(15)->insertI(40)->insertI(15)->insertI(80)->insertI(70);
	root = root->insertR(145)->insertR(42)->insertR(84);
	root->preOrder();
	cout << endl;
	root->inOrder();
	cout << endl;
	root->postOrder();
	cout << endl;
	cout << root;
	cout << endl;
	Node* r;
	cin >> r;
	cout << endl;
	cout << r;
	cout << endl;
	if (root->searchI(15)) {
		cout << "the number was found " << endl;
	}
	else {
		cout << "the number wasn't found  " << endl;
	}
	return 0;
}