#include<bits/stdc++.h>;
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;   
};

Node* insert(Node* root, int key){
    if(root == NULL){
        root = (Node*)malloc(sizeof(Node));
        root->data = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if(root->data == key){
        return root;
    }
    if(key < root->data){
        root->left = insert(root->left, key);
    }else if(key < root->data){
        root->right = insert(root->right, key);}
    return root;
}

bool search(Node* root, int key){
    while(root != NULL){   
        if( key == root->data) return true;
        else if(key < root->data){
            root = root->left;
        }else{
            root = root->right;
        }
        
    }
    return false;
}
//recursive
bool searchInBST(Node* root, int key){
    if(root == NULL) return false;
    if(root->data == key) return true;
    if(key < root->data){
        searchInBST(root->left, key);
    }else{
        searchInBST(root->right, key);
    }
}

Node* deleteNode(Node* root, int key){
    if(root == NULL) return NULL;

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //both child nodes present
        Node* curr = root->right;
        while(curr->left != NULL){
            curr = curr->left;
        }
        root->data = curr->data;
        root->right = deleteNode(root->right, curr->data);
    }
    return root;
}

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}


int main(){


    return 0;
}

