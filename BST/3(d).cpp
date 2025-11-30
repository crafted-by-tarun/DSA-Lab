#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }
};

int find_min(int a, int b) {
    return (a < b) ? a : b;
}

int min_depth(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return min_depth(root->right) + 1;

    if (root->right == NULL)
        return min_depth(root->left) + 1;

    return find_min(min_depth(root->left), min_depth(root->right)) + 1;
}

int main() {
    BST tree;
    tree.root = new Node(5);
    tree.root->left = new Node(2);
    tree.root->right = new Node(12);
    tree.root->left->left = new Node(1);
    tree.root->left->right = new Node(3);
    tree.root->right->left = new Node(9);
    tree.root->right->right = new Node(21);
    tree.root->right->right->left = new Node(19);
    tree.root->right->right->right = new Node(25);

    cout << "The minimum depth of the BST is: " << min_depth(tree.root);
    return 0;
}
