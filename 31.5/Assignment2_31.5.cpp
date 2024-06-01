#include <iostream>
using namespace std; 

template <typename T>
class BinaryTree {
    private: 
    struct BinaryNode {
        T element; 
        BinaryNode* left; 
        BinaryNode* right; 
    BinaryNode (T value, BinaryNode* l, BinaryNode* r) {
        element = value; 
        left = l; 
        right = r;
    }
    }; 
    BinaryNode* root; 
    void InsertParent (T x, BinaryNode* p, BinaryNode*& n) {
        if (n == NULL) return; 
        if (n->left == p || n->right ==p) {
            BinaryNode* temp = n;
            BinaryNode* newnode = new BinaryNode (x, n->left, n->right); 
            n = newnode; 
            delete temp; 
        }
        else {
            InsertParent (x, p, n->left);
            InsertParent (x, p, n->right); 
        }
    }
    void InsertLeftChild (T x, BinaryNode* p, BinaryNode*& n) {
        if (n == NULL) return; 
        if (n==p) {
            BinaryNode* temp = p->left;
            BinaryNode* newnode = new BinaryNode (x, p->left->left, p->left->right); 
            p->left = newnode; 
            delete temp;
        }
        else {
            InsertLeftChild (x, p, n->left); 
            InsertLeftChild (x, p, n->right); 
        }
    }
    void InsertRightChild (T x, BinaryNode* p, BinaryNode*& n) {
        if (n == NULL) return; 
        if (n==p) {
            BinaryNode* temp = p->right; 
            BinaryNode* newnode = new BinaryNode (x, p->right->left, p->right->right); 
            p->right = newnode;
            delete temp; 
        }
        else {
            InsertRightChild (x, p, n->left); 
            InsertRightChild (x, p, n->right); 
        }
    }

    Node * FindNode(T x, Node *& t) {
        if (t == NULL) return NULL;
        if (x < t->element) {
            t = t->left;
            search (sbd, t); } 
        else if (x > t->element) {
            t = t->right;
            search (sbd, t); }
        return t; }
    
    void DeleteCurrentNode (BinaryNode* p, BinaryNode*& t) {
        if (t == NULL) return; 
        if (t == p) {
            BinaryNode* tmp = p; 
            if (p->left->element >= p->right->element) {p = p->left; 
            delete p->left;}
            else {p = p->right;
            delete p->right; } 
            delete tmp; 
        }
        else {
            DeleteCurrentNode (p, t->left); 
            DeleteCurrentNode (p, t->right);
        }
    }
    int GetSize (BinaryNode*& t) {
        if (t==NULL) return 0;
        else return 1 + GetSize(t->left) + GetSize (t->right);
    }
    public: 
    void InitBTree () {root = NULL; }
    void InsertParent(T x, BinaryNode* p) {InsertParent(x, p, root);}
    void InsertLeftChild (T x, BinaryNode* p) {InsertLeftChild (x, p, root);}
    void InsertRightChild (T x, BinaryNode* p) {InsertRightChild (x, p, root);}
    Node* FindNode (T x) {Node* temp = Node* FindNode (x, root);
    return temp;}
    void DeleteCurrentNode (BinaryNode* p) {DeleteCurrentNode (p, root);}
    int GetSize () {int tmp = GetSize (root);
    return tmp;}
};