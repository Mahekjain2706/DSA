#include<bitset>/stdc++.h>
using namespace std;

// Maximum Path Sum in a Binary Tree from Any Node to Any Node

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxiSum(Node* root, int &res){
    if(root == NULL){
        return 0;
    }
    int l = maxiSum(root->left, res);
    int r = maxiSum(root->right, res);
    int temp = max(max(l, r) + root->data, root->data);
    int ans = max(temp, l + r + root->data);
    res = max(res,ans);

    return temp;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);


    return 0;
}