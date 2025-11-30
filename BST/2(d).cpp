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
int mini(Node* root){
    if(root==NULL) return-1;
    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;
}
int Successor(Node* root,Node* x){
      if(x->right!=NULL){
       return mini(x->right);
    }
     else{
    Node* successor = NULL;
    while(root!=NULL){
        if(root->data>x->data){
            successor = root;
            root = root->left;
        }
        else if(root->data<x->data){
            root = root->right;
        }
     else{
        break;
     }
    }
  
   if(successor!=NULL) return successor->data;
        else{
            return -1;
        }
    }

}
int main(){
BST tree;
tree.root = new Node(8);
tree.root->left = new Node(3);
tree.root->right = new Node(10);
tree.root->left->left = new Node(1);
tree.root->left->right = new Node(6);
tree.root->left->right->left = new Node(4);
tree.root->left->right->right = new Node(7);
tree.root->right->right = new Node(14);
tree.root->right->right->left = new Node(13);
cout<<Successor(tree.root,tree.root);
    return 0;
}
