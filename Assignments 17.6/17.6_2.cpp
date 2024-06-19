#include <iostream>
#include <string>
using namespace std;

struct Node {
    int index;
    string title;
    Node* left;
    Node* right;
};

Node* createNode(int index, string title) {
    Node* newNode = new Node;
    newNode->index = index;
    newNode->title = title;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

bool areBooksIdentical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;

    if (root1 == nullptr || root2 == nullptr)
        return false;

    if (root1->index != root2->index || root1->title != root2->title)
        return false;

    return areBooksIdentical(root1->left, root2->left) && areBooksIdentical(root1->right, root2->right);
}

int main() {
    Node* root1 = createNode(1, "Chương 1");
    root1->left = createNode(2, "Mục 1.1");
    root1->right = createNode(3, "Mục 1.2");
    root1->left->left = createNode(4, "Mục 1.1.1");
    root1->left->right = createNode(5, "Mục 1.1.2");

    Node* root2 = createNode(1, "Chương 1");
    root2->left = createNode(2, "Mục 1.1");
    root2->right = createNode(3, "Mục 1.2");
    root2->left->left = createNode(4, "Mục 1.1.1");
    root2->left->right = createNode(5, "Mục 1.1.2");

    if (areBooksIdentical(root1, root2))
        cout << "Hai cuốn sách là bản copy của nhau." << endl;
    else
        cout << "Hai cuốn sách không phải bản copy." << endl;

    return 0;
}