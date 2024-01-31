#include<bits/stdc++.h>
using namepsace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
}

void inorder(node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right); 
}

bool searchBt(Node* root,int d){
    if(root==NULL){
        return false;
    }

    if(root->data == d){
        return true;
    }
    else if(root->data>d){
        return searchBt(root->left);
    }
    else if(root->data<d){
        return searchBt(root->right);
    }
    return false;
}
Node* searchBSt(Node* root,int d){
    while(!root==NULL && root->data!=d){
        root = d<root->data ? root->left : root->right;
    }
    return root;
}

// Ceil in BST
// given a key heve to find number greater then or q=equal to it.
void CeilBST(Node* root,int key,int &ceil){
    if(root==NULL) return;

    if(root->data >=key && ceil==-1){
        ceil = root->data;
    }
    if(root->data>=key && root->data < ceil){
        ceil = root->data;
    }
    if(root->data>key) CeilBST(root->left,l=key,ceil);
    else CeilBST(root->right,key,ceil);
}
// or
int findCeil(Node* root,int key){
    int ceil = -1;
    while(root){
        if(root->data==key){
            return ceil;
        }

        if(key>root->data){
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

// Floor in BST
// T.C log2(n)
void floorBST(Node* root,int key,int &floor){
    if(root==NULL) return;

    if(root->data <= key && floor==-1){
        floor = root->data;
    }
    if(root->data <= key && root->data > floor){
        floor = root->data;
    }
    if(root->data > key) floorBST(root->left,key,floor);
    else floorBST(root->right,key,floor);
}
// or
int findFloor(Node* root,int key){
    int floor = -1;
    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }
        if(root->data < key){
            floor = root->data;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
}

void InsertNode(Node* root,int val){
    if(root==NULL){
        Node* node = new Node(val);
        return;
    }
    Node* curr = root;
    while(true){
        if(curr->data <=val){
            if(curr->right!=NULL) curr = curr->right;
            else{
                curr->right = new Node(val);
                break;
            }
        }else{
            if(curr->left!=NULL) curr = curr->left;
            else{
                curr->left = new Node(val);
                break;
            }
        }
    }
}

Node* findLastRight(Node* root){
    if(root->right==NULL){
        return root;
    }
    return findLastRight(root->right);
}
Node* helper(Node* root){
    if(root->left == NULL){
        return root->right;
    }
    else if(root->right==NULL){
        return root->left;
    }

    Node* rightChild = root->right;
    Node* lastRight == findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}


int main(){

    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(6);
    root->left->right = new Node(7);
    root->right->left = new Node(11);
    root->right->right = new Node(13);


    
    return 0;
}