#include <iostream>
using namespace std;

struct Node {
    int val, weight;
    Node* lfchild, * rgchild;

    Node(int x) {
        val = x;
        weight = 1;
        lfchild = nullptr;
        rgchild = nullptr;
    }
};
Node* addLeaf_R(Node* r, int val) {                                 //inserimento ricorsivo
    if (r == NULL) {
        return new Node(val);
    }
    if (r->val == val) {
        r->weight++;
        return r;
    }
    if (val < r->val) {
        r->lfchild = addLeaf_R(r->lfchild, val);
    }
    else if (val > r->val) {
        r->rgchild = addLeaf_R(r->rgchild, val);
    }
    return r;
}
Node* addLeaf_I(Node* r, int val) {                                 //inserimento iterativo
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
void cout_Nodeptr(Node* r) {
    cout << endl << "-------------------------------" << endl;                              //cout membri di un nodo
    cout << "Il valore del nodo e': " << r->val << endl;
    cout << "Il numero di copie del nodo e': " << r->weight << endl;
    cout << "Il lfchild: " << r->lfchild << "| il rgchild: " << r->rgchild << endl;
    cout << "-------------------------------" << endl;
}
bool checkN(Node* r, int val) {                     // ricerca e conferma di un valore ricorsivo
    bool check;
    if (r == NULL) {
        check = false;
        return check;
    }
    if (r->val == val) {
        check = true; \
            return check;
    }
    if (val < r->val) {
        check = checkN(r->lfchild, val);
    }
    else if (val > r->val) {
        check = checkN(r->rgchild, val);
    }
    return check;
}
Node* find_smallest(Node* r) {
    while (r->lfchild != nullptr) {
        r = r->lfchild;
    }
    return r;
}
void preOrder(Node* r) {                             // cout preOreder ricorsivo
    if (r == nullptr) return;
    cout << r->val << " ";
    preOrder(r->lfchild);
    preOrder(r->rgchild);
}
void inOrder(Node* r) {                             // cout inOreder ricorsivo
    if (r == nullptr) return;
    inOrder(r->lfchild);
    cout << r->val << " ";
    inOrder(r->rgchild);
}
void postOrder(Node* r) {                             // cout postOreder ricorsivo
    if (r == nullptr) return;
    postOrder(r->lfchild);
    postOrder(r->rgchild);
    cout << r->val << " ";
}
Node* rm_Node(Node* r, int val) {                //cancellazione nodo foglia ricorsivo
    cout << endl << "r->val:" << r->val << endl;
    Node* smallest{ nullptr };
    Node* dad{ nullptr };
    bool is_left;
    while (r != nullptr) {
        if (r->val == val) {
            break;
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

    if (r == NULL) {
        cout << "Nodo non trovato" << endl;
        return r;
    }
    if (r->val == val) {
        cout << "Nodo trovato" << endl;
        if (r->lfchild == nullptr && r->rgchild == nullptr) {
            delete r;
            if (is_left) {
                dad->lfchild = nullptr;
            }
            else {
                dad->rgchild = nullptr;
            }
            return r;
        }
        else if (r->lfchild == nullptr) {
            r->val = r->rgchild->val;
            delete r->rgchild;
            r->rgchild = nullptr;
            return r;
        }
        else if (r->rgchild == nullptr) {
            r->val = r->lfchild->val;
            delete r->lfchild;
            r->lfchild = nullptr;
            return r;
        }
        else if (r->lfchild != nullptr && r->rgchild != nullptr) {
            smallest = find_smallest(r->rgchild);
            cout << smallest->val << endl;
            Node* small_dad{ nullptr };
            Node* small_r{ r->rgchild };
            while (small_r != nullptr) {
                if (small_r->lfchild->val == smallest->val) {
                    small_dad = small_r;
                    break;
                }
                else {
                    small_r = small_r->lfchild;
                }
            }
            r->val = smallest->val;
            delete smallest;
            small_dad->lfchild = nullptr;
            return r;
        }
        else {
            cout << "ultimo caso" << endl;
            return r;
        }
    }
    else if (val < r->val) {
        r = rm_Node(r->lfchild, val);
    }
    else if (val > r->val) {
        r = rm_Node(r->rgchild, val);
    }
}
int altezza(Node* rt) {                              //altezza bst ricorsivo
    if (rt == NULL) return 0;

    int l = altezza(rt->lfchild);
    int r = altezza(rt->rgchild);

    int max = (l >= r) ? l : r;
    return max + 1;
}
bool is_bst(Node* r) {                               // controllo se è un bst ricorsivo
    bool bst{ true };
    if (r->lfchild->val > r->val && r->rgchild->val < r->val) {
        return false;
    }
    else if (r->lfchild == nullptr && r->rgchild == nullptr) {
        return true;
    }
    else if (r->lfchild->val < r->val && r->rgchild->val > r->val) {
        bst = is_bst(r->lfchild);
        bst = is_bst(r->rgchild);
    }
    return bst;
}