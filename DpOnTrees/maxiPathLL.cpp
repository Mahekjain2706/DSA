#include<bitset>/stdc++.h>
using namespace std;

// Identification of the problem
// Maximum path sum between two nodes in a tree - leaf to leaf
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
 
int maxiPathLL(Node* root, int &res){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->data;
    int l = max(maxiPathLL(root->left, res),0);
    int r = max(maxiPathLL(root->right, res),0);
    
    int temp = max(l, r) + root->data;
    if(root->left != NULL && root->right != NULL){
        temp = max(temp, root->data);
    }
    int ans = max(temp, l+r+root->data);
    res = max(res, ans);
    return temp;
}


int main(){

    return 0;
}