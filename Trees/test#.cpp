#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left ;
    Node* right;
    int data;
    
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// preorder
void preorder(Node* root){
    if(root==NULL) return;

    cout<< root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

vector<int> preorder1(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* node = st.top();
        st.pop();

        ans.push_back(node->data);
        if(node->right) st.push_back(node->right);
        if(node->left) st.push_back(node->left);
    }
    return ans;
}

// inorder
void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}

vector<int> inorder1(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;

    Node* curr = root;
    stack<Node*> st;

    while(true){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            if(st.empty()) break;
            curr = st.top();
            ans.push_back(curr->data);
            st.pop();
            curr = curr->right;
        }
    }
    return ans;
}

// postorder
void postorder(Node* root){
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<< root->data
}

int main(){
    return 0;
}