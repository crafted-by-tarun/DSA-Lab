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
//Doing recursively

// bool search(Node* root,int x){
//         if(root==NULL) return false;

//    else if(root->data == x){
//         return true;
//     }
//     else if(root->data<x)  return search(root->right,x);
//     else{
//        return  search(root->left,x);
//     }
  
// }

//Doing non recursively

bool search(Node* root,int x){
    while(root!=NULL){
     if(root->data==x) return true;
     else if(root->data<x){
        root = root->right;
     }
     else{
        root = root->left;
     }
    }
return false;
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
if(search(tree.root,10)){
    cout<<"Element found."<<endl;
}
else{
    cout<<"Element is not present."<<endl;
}

    return 0;
}
