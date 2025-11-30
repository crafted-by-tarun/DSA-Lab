#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class BST{
    public:
    Node* root;
    BST(){
        root = NULL;
    }
};
vector<int> v;

void inorder(Node* root){
if(root==NULL){
    return;
}
inorder(root->left);
v.push_back(root->data);
inorder(root->right);
}
bool is_BST(vector<int> &v){
    if((v[0]>v[1]) || (v[v.size()-2]>v[v.size()-1])) return false;

    for(int i=1;i<v.size()-1;i++){
        if(v[i]>=v[i+1]) return false;
    }
    return true;
}
int main(){
      BST tree;
    tree.root = new Node(5);
    tree.root->left = new Node(2);
    tree.root->right = new Node(4);
    tree.root->left->left = new Node(1);
    tree.root->left->right = new Node(3);
    tree.root->right->left = new Node(9);
    tree.root->right->right = new Node(21);
    tree.root->right->right->left = new Node(19);
    tree.root->right->right->right = new Node(25);
inorder( tree.root);
if(is_BST(v)) cout<<"The given binary tree is BST"<<endl;
else cout<<"The given binary tree is not BST"<<endl;
    return 0;
}
