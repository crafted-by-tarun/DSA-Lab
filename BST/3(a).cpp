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
void insert(Node* &root,Node* x){
    Node* temp = root;
if(root==NULL){ root = x;
return;
}
else if(temp->left==NULL && temp->right==NULL){
    if(temp->data<x->data){
        temp->right = x;
    }
    else{
        temp->left = x;
    }
}
else{
    while(temp!=NULL){
        if(temp->data<x->data){
            if(temp->right==NULL){
                temp->right = x;
                break;
            }
            else{
                temp = temp->right;
            }
        }
        else{
            if(temp->left==NULL){
                temp->left = x;
                break;
            }
            else{
                temp = temp->left;
            }
        }
    }
}
}
int main(){
BST tree;
insert(tree.root,new Node(5));
insert(tree.root,new Node(7));
insert(tree.root,new Node(9));
insert(tree.root,new Node(2));
insert(tree.root,new Node(3));
insert(tree.root,new Node(4));
insert(tree.root,new Node(11));
insert(tree.root,new Node(13));
insert(tree.root,new Node(10));

    return 0;
}
