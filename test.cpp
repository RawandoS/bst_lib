#include <iostream>
#include "Node.h"
using namespace std;

int main() {
	Node* root = new Node(64);
	root = root->insertI(32)->insertI(15)->insertI(40)->insertI(15)->insertI(80)->insertI(70);

	root->inOrder();

	bool is = root->searchR(14);
	if (is) {
		cout << "there is 14" << endl;
	}
	else {
		cout << "there isn't 14" << endl;
	}
	return 0;
}