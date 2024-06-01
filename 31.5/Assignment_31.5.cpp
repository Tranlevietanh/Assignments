#include <iostream>
using namespace std; 

struct Node {
    int sbd; 
    string hoTen; 
    Node * left; 
    Node * right;
    Node(int s, string h, Node * l, Node * r) {
        sbd = s;
        hoTen = h; 
        left = l; 
        right = r; }
};

class BSTree {
    private:
    Node * root;
    void makeEmpty(Node *&t) { 
        if (t == NULL) return; 
        else {makeEmpty (t->left); 
        makeEmpty (t->right); 
        delete t; 
        t = NULL; }
    }
    void insert(int sbd, string hoTen, Node *& t) {
        if (t == NULL) t = new Node (sbd, hoTen, NULL, NULL);
        else if (sbd < t->sbd) insert (sbd, hoTen, t->left); 
        else if (sbd > t->sbd) insert (sbd, hoTen, t->right); }
    
    Node * search(int sbd, Node *& t) {
        if (t == NULL) return NULL;
        if (sbd < t->sbd) {
            t = t->left;
            search (sbd, t); } 
        else if (sbd > t->sbd) {
            t = t->right;
            search (sbd, t); }
        return t; }
    
    void NLR (Node* node) {
	if (node != NULL) {
		cout << node->sbd << " " << node->hoTen;
        cout << endl;  
		NLR (node->left); 
		NLR (node->right); }
	}
		
    void LNR (Node* node) {
	if (node != NULL) {
		LNR (node->left); 
		cout << node->sbd<< " " << node->hoTen;
        cout << endl;  
		LNR (node->right); }
	}
    
    void LRN (Node* node) {
	if (node!= NULL) {
		LRN (node->left); 
		LRN (node->right); 
		cout << node->sbd<<" "<<node->hoTen;
        cout << endl; }
	}

    public:
    BSTree() {root = NULL; }

    ~BSTree() {makeEmpty (); }

    bool isEmpty() {return (root==NULL); }
    
    void makeEmpty() {makeEmpty (root); }

    void insert(int sbd, string hoTen) {insert (sbd, hoTen, root); }
    
    Node* search(int sbd) {
        Node* n1 = search (sbd, root); 
        return n1;}
    
    void LRN() {LRN (root);}
    void LNR() {LNR (root);}
    void NLR() {NLR (root);}

};

int main()
{
BSTree bst;
bst.insert(5, "Tuan");
bst.insert(6, "Lan");
bst.insert(3, "Cong");
bst.insert(8, "Huong");
bst.insert(7, "Binh");
bst.insert(4, "Hai");
bst.insert(2, "Son");
bst.NLR();
Node * n1 = bst.search(4);
Node * n2 = bst.search(9);
if (n1 != NULL)
cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl;
if (n2 == NULL)
cout << "Khong tim thay sinh vien voi SBD=9" << endl;
bst.makeEmpty();
if (bst.isEmpty())
cout << "Cay da bi xoa rong" << endl;
}
