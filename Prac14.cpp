#include<bits/stdc++.h>;
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
};

vector<int> inorder(Node* root) {
    vector<int> ans;
    stack<Node*> st;
    Node* curr = root;
    if(root == NULL) return ans;
    st.push(curr);
    while(!st.empty()){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        curr = curr->right;
        
    } 
    return ans;
}

vector<int> preorder(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    stack<Node* > st;
    Node* curr;
    st.push(root);
    while(st.empty()){
        curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        if(curr->right){
            st.push(curr->right);
        }
        if(curr->left){
            st.push(curr->left);
        }
    }
    return ans;
}

vector<int> postorder(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    return ans;
}

vector<int> postorder(Node* root){
    vector<int> ans;
    stack<Node* > at;
    Node* curr = root;


    return ans;
}
