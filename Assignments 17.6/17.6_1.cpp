#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int index;
    string title;
    vector<Node*> children;
};

Node* createNode(int index, string title) {
    Node* newNode = new Node;
    newNode->index = index;
    newNode->title = title;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    parent->children.push_back(child);
}

int getNumChapters(Node* root) {
    int count = 0;
    for (Node* child : root->children) {
        if (child->children.empty()) {
            count++;
        }
    }
    return count;
}

Node* findLongestChapter(Node* root) {
    Node* longestChapter = root;
    int maxChildren = 0;
    for (Node* child : root->children) {
        if (child->children.size() > maxChildren) {
            maxChildren = child->children.size();
            longestChapter = child;
        }
    }
    return longestChapter;
}

void deleteSection(Node* root, int index) {
    for (int i = 0; i < root->children.size(); i++) {
        if (root->children[i]->index == index) {
            Node* deletedNode = root->children[i];
            root->children.erase(root->children.begin() + i);
            delete deletedNode;
            return;
        }
        deleteSection(root->children[i], index);
    }
}

void printChapterContents(Node* chapter) {
    cout << "Contents of chapter " << chapter->index << ":" << endl;
    for (Node* child : chapter->children) {
        cout << "- " << child->title << endl;
    }
}

int main() {
 
    Node* root = createNode(0, "Mục lục");
    Node* chapter1 = createNode(1, "Chương 1");
    Node* section1 = createNode(1, "Mục 1");
    Node* subsection1 = createNode(1, "Mục con 1");
    Node* subsubsection1 = createNode(1, "Mục con của mục con 1");
    addChild(root, chapter1);
    addChild(chapter1, section1);
    addChild(section1, subsection1);
    addChild(subsection1, subsubsection1);

    int numChapters = getNumChapters(root);
    cout << "Số chương của cuốn sách: " << numChapters << endl;

    Node* longestChapter = findLongestChapter(root);
    cout << "Chương dài nhất: " << longestChapter->title << endl;


    deleteSection(root, 1);
    cout << "Đã xoá mục có index 1 khỏi sách." << endl;

    printChapterContents(chapter1);

    return 0;
}