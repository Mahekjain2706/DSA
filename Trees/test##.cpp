#include<bits/stdc++.h> 
using anmespace std;

// Trees
class Node{
    publc:
    Node* left;
    Node* right;
    int data;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

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
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    return ans;
}

void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<< root->data << ' ';
    inorder(root->right);
}
vector<int> inorder1(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;

    Node* curr = root;
    stack<Node*> st;

    while(true){
        if(curr!=NULL){
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

void postorder(Node* root){
    if(root==NULL) return NULL;

    postorder(root->left);
    postorder(root->right);
    cout<< root->data << " ";
}
vector<int> postorder1(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        Node* node = st.top();
        st.pop();

        st2.push(node);
        if(node->left) st1.push(node->left);
        if(node->right) st1.push(node->right);
    }

    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}
vector<int> postorder2(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;

    stack<Node*> st;
    Node* curr = root;

    while(!st.empty() || curr!=NULL){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            if(st.empty()) break;
            Node* temp = st.top()->right;
            if(temp==NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.top() && temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else{
                curr = temp;
            }
        }
    }
    return ans;
}


int main(){
    return 0;
}