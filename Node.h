#pragma once
#include <iostream>
using namespace std;

class Node {
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;
    friend ostream& operator<<(ostream& os, Node*p);
    friend istream& operator>>(istream& is, Node* p);
public:
    Node(int val);
    Node* insertR(int k);
    Node* insertI(int k);
    bool searchI(int k);
    bool searchR(int k);
    void inOrder();
    void preOrder();
    void postOrder();
    //Node* deleteNode(int k);
    //bool isBst();
};