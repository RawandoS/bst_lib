#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int v)
    :val{ v }, weight{ 1 }, lfchild{ nullptr }, rgchild{ nullptr } {
};
Node* Node::insertR(int k) {                                 //inserimento ricorsivo
    if (this == nullptr) {
        return new Node(val);
    }
    if (this->val == k) {
        this->weight++;
        return this;
    }
    if (k < this->val) {
        this->lfchild = this->lfchild->insertR(k);
    }
    else if(k > this->val) {
        this->rgchild = this->rgchild->insertR(k);
    }
    return this;
}
void Node::preOrder() {                             // cout inOreder ricorsivo
    cout << this->val << " ";
    if (this->lfchild != nullptr) {
        this->lfchild->inOrder();
    }
    if (this->rgchild != nullptr) {
        this->rgchild->inOrder();
    }
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
void Node::postOrder() {                             // cout inOreder ricorsivo
    if (this->lfchild != nullptr) {
        this->lfchild->inOrder();
    }
    if (this->rgchild != nullptr) {
        this->rgchild->inOrder();
    }
    cout << this->val << " ";
}