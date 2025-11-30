#include <iostream>
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
Node* mini(Node* root){
    if(root==NULL) return NULL;
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}
Node* Successor(Node* root,Node* x){
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
  
   if(successor!=NULL) return successor;
        else{
            return NULL;
        }
    }

}
void remove (Node *&root, int x)
{
    Node *temp = root;
    if(temp->right==NULL && temp->left==NULL){ delete root;root = NULL; return;}
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data < x)
        {
            prev = temp;
            temp = temp->right;
        }
        else if (temp->data > x)
        {
            prev = temp;
            temp = temp->left;
        }
        else
        {
            break;
        }
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        if (temp->data > prev->data)
        {
            prev->right = NULL;
            delete temp;
        }
        else
        {
            prev->left = NULL;
            delete temp;
        }
    }
    else if(temp->left!=NULL && temp->right==NULL){
        if(temp->data > prev->data){
            prev->right = temp->left;
            delete temp;
        }
        else{
            prev->left = temp->left;
            delete temp;
        }
    }
    else if(temp->left==NULL && temp->right!=NULL){
        if(temp->data >prev->data){
            prev->right = temp->right;
            delete temp;
        }
        else{
            prev->left = temp->right;
            delete temp;
        }
    }
    else{
        Node* temp2 = root;
        Node* g = temp;
        Node *cur_Successor = Successor(temp2,g);
        temp->data = cur_Successor->data;
        remove(temp->right,cur_Successor->data);
    }
}

int main()
{
    return 0;
}
