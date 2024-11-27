#pragma once
using namespace std;

class Node {
private:
    int val;
    int weight;
    Node* lfchild;
    Node* rgchild;
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