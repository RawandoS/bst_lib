#include "Node.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, Node* p) {
    os << "Data: " << (*p).data << " | Weight: " << (*p).weight;
    if ((*p).lchild != nullptr) {
        os << " | Left Child Data: " << (*p).lchild->data;
    }
    else if ((*p).rchild != nullptr) {
        os << " | Right Child Data: " << (*p).rchild->data;
    }
    return os;
}
istream& operator>>(istream& is, Node* p) {
    int n;
    is >> n;
    p->data = n;
    p->lchild = nullptr;
    p->rchild = nullptr;
    return is;
}
Node::Node(int v)
    :data{ v }, weight{ 1 }, lchild{ nullptr }, rchild{ nullptr } {
};
Node::Node()
    :data{ 0 }, weight{ 1 }, lchild{ nullptr }, rchild{ nullptr } {
};
Node* Node::insertR(int k) {                                 //inserimento ricorsivo 
    if (this == nullptr) {
        return new Node(k);
    }
    if (this->data == k) {
        this->weight++;
        return this;
    }
    if (k < this->data) {
        this->lchild = this->lchild->insertR(k);
    }
    else if (k > this->data) {
        this->rchild = this->rchild->insertR(k);
    }
    return this;
}
Node* Node::insertI(int k) {                                 //inserimento iterativo
    Node* current = this;
    Node* dad{ nullptr };
    bool is_left;
    while (current != nullptr) {
        if (current->data == k) {
            current->weight++;
            return this;
        }
        if (k < current->data) {
            dad = current;
            current = current->lchild;
            is_left = true;
        }
        else if (k > current->data) {
            dad = current;
            current = current->rchild;
            is_left = false;
        }
    }
    if (is_left) {
        dad->lchild = new Node(k);
    }
    else if (!is_left) {
        dad->rchild = new Node(k);
    }
    return this;
}
bool Node::searchR(int k) {                     // ricerca ricorsiva
    bool check;
    if (this == NULL) {
        check = false;
        return check;
    }
    if (this->data == k) {
        check = true;
        return check;
    }
    if (k < this->data) {
        check = this->lchild->searchR(k);
    }
    else if (k > this->data) {
        check = this->rchild->searchR(k);
    }
    return check;
}
bool Node::searchI(int k) {                                 //inserimento iterativo
    bool check{ false };
    Node* current = this;
    while (current != nullptr) {
        if (current->data == k) {
            return true;
        }
        if (k < current->data) {
            current = current->lchild;
        }
        else if (k > current->data) {
            current = current->rchild;
        }
    }
    return false;
}
void Node::preOrder() {                             // cout inOreder ricorsivo
    cout << this->data << " ";
    if (this->lchild != nullptr) {
        this->lchild->preOrder();
    }
    if (this->rchild != nullptr) {
        this->rchild->preOrder();
    }
}
void Node::inOrder() {                             // cout inOreder ricorsivo
    if (this->lchild != nullptr) {
        this->lchild->inOrder();
    }
    cout << this->data << " ";
    if (this->rchild != nullptr) {
        this->rchild->inOrder();
    }
}
void Node::postOrder() {                             // cout inOreder ricorsivo
    if (this->lchild != nullptr) {
        this->lchild->postOrder();
    }
    if (this->rchild != nullptr) {
        this->rchild->postOrder();
    }
    cout << this->data << " ";
}
bool Node::isBst() {
    bool bst{ true };
    if (this->lchild->data > this->data && this->rchild->data < this->data) {
        return false;
    }
    else if (this->lchild == nullptr && this->rchild == nullptr) {
        return true;
    }
    else if (this->lchild->data < this->data && this->rchild->data > this->data) {
        bst = this->lchild->isBst();
        bst = this->rchild->isBst();
    }
    return bst;
}