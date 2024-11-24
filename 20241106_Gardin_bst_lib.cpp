#include "bst_lib.h"
#include <iostream>
using namespace std;

Node::Node(int v)
    :val{ v }, weight{ 1 }, lfchild{ nullptr }, rgchild{ nullptr } {
};
Node* Node::addLeaf_I(int val) {                                 //inserimento iterativo
    Node* r = this;
    Node* current = r;
    Node* dad{ nullptr };
    bool is_left;
    while (r != nullptr) {
        if (r->val == val) {
            r->weight++;
            return current;
        }
        if (val < r->val) {
            dad = r;
            r = r->lfchild;
            is_left = true;
        }
        else if (val > r->val) {
            dad = r;
            r = r->rgchild;
            is_left = false;
        }
    }
    if (is_left) {
        dad->lfchild = new Node(val);
    }
    else if (!is_left) {
        dad->rgchild = new Node(val);
    }
    return current;
}
void Node::inOrder() {                             // cout inOreder ricorsivo
    if (this->lfchild != nullptr) {
        this->lfchild->inOrder();
    }
    cout << this->val << " ";
    if (this->rgchild != nullptr) {
        this->rgchild->inOrder();
    }
}