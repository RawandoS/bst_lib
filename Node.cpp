#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int v)
    :data{ v }, weight{ 1 }, lchild{ nullptr }, rchild{ nullptr } {
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
    else if(k > this->data) {
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
bool Node::searchR(int k){                     // ricerca ricorsiva
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
bool Node::isBst() {                               // controllo se è un bst ricorsivo
    if (this == nullptr) {
        return true;
    }
    if (this->lchild != nullptr && this->lchild->data < this->data) {
        return this->lchild->isBst();
    }
    else if (this->lchild != nullptr && this->lchild->data > this->data) {
        return false;
    }
    if (this->rchild != nullptr && this->rchild->data > this->data) {
        return this->rchild->isBst();
    }
    else if (this->rchild != nullptr && this->rchild->data < this->data) {
        return false;
    }
    return true;
}
Node* Node::deleteNode(int k) {
    Node* smallest{ this };
    Node* dad{ nullptr };
    bool is_left;
    while (smallest != nullptr) {
        if (smallest->data == k) {
            break;
        }
        if (k < smallest->data) {
            dad = smallest;
            smallest = smallest->lchild;
            is_left = true;
        }
        else if (k > smallest->data) {
            dad = smallest;
            smallest = smallest->rchild;
            is_left = false;
        }
    }
    if (smallest->lchild == nullptr && smallest->rchild == nullptr) {
        if (is_left) {
            dad->lchild = nullptr;
        }
        else {
            dad->rchild = nullptr;
        }
        delete smallest;
        return this;
    }
    else if (smallest->rchild == nullptr && smallest->lchild != nullptr) {
        smallest->data = smallest->lchild->data;
        delete smallest->lchild;
        smallest->lchild = nullptr;
        return this;
    }
    else if (smallest->lchild == nullptr && smallest->rchild != nullptr) {
        smallest->data = smallest->rchild->data;
        delete smallest->rchild;
        smallest->rchild = nullptr;
        return this;
    }
    else if (smallest->lchild != nullptr && smallest->rchild != nullptr) {
        Node* r = smallest->rchild;
        Node* r_dad {nullptr};
        while (r->lchild != nullptr) {
            r_dad = r;
            r = r->lchild;
        }
        smallest->data = r->data;
        delete r;
        r_dad->lchild = nullptr;
        return this;
    }
    else {
        cout << "ultimo caso" << endl;
        return this;
    }
}
