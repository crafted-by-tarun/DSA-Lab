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

int find_max(int a, int b) {
    return (a > b) ? a : b;
}

int max_depth(Node* root) {
    if (root == NULL)
        return 0;

    int left_depth = max_depth(root->left);
    int right_depth = max_depth(root->right);

    return find_max(left_depth, right_depth) + 1;
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

    cout << "The maximum depth of the BST is: " << max_depth(tree.root);
    return 0;
}
