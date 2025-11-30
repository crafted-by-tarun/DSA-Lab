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
int max(Node* root){
    if(root==NULL) return-1;
    while(root->right!=NULL){
        root = root->right;
    }
    return root->data;
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
if(max(tree.root)==-1) cout<<"The tree is empty."<<endl;
else{
    cout<<"The maximum element is: "<<max(tree.root)<<endl;
}







    return 0;
}
