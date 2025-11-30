#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int a){
    data = a;
    left = right =NULL;
}
};

class BST{
public:
Node* root;
BST(){
    root=NULL;
}

};
void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
BST a;
a.root = new Node(1);
a.root->left = new Node(2); 
a.root->right = new Node(3);
a.root->left->left = new Node(4);
a.root->left->right = new Node(5);
cout<<"Preorder  ";preorder(a.root);
cout<<endl;
cout<<"Inorder  ";inorder(a.root);
cout<<endl;
cout<<"postorder  ";postorder(a.root);

    return 0;
}
