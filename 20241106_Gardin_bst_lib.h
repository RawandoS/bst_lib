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
    Node* addLeaf_I(int val);
    void inOrder();
};  