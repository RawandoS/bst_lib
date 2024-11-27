#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int v)
    :val{ v }, weight{ 1 }, lfchild{ nullptr }, rgchild{ nullptr } {
};
Node* Node::insertR(int k) {                                 //inserimento ricorsivo NON FUNZIONANTE
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
Node* Node::insertI(int k) {                                 //inserimento iterativo
    Node* current = this;
    Node* dad{ nullptr };
    bool is_left;
    while (current != nullptr) {
        if (current->val == k) {
            current->weight++;
            return this;
        }
        if (k < current->val) {
            dad = current;
            current = current->lfchild;
            is_left = true;
        }
        else if (k > current->val) {
            dad = current;
            current = current->rgchild;
            is_left = false;
        }
    }
    if (is_left) {
        dad->lfchild = new Node(k);
    }
    else if (!is_left) {
        dad->rgchild = new Node(k);
    }
    return this;
}
bool Node::searchR(int k){                     // ricerca ricorsiva
    bool check;
    if (this == NULL) {
        check = false;
        return check;
    }
    if (this->val == k) {
        check = true; 
        return check;
    }
    if (k < this->val) {
        check = this->lfchild->searchR(k);
    }
    else if (k > this->val) {
        check = this->rgchild->searchR(k);
    }
    return check;
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