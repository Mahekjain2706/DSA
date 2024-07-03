#include<bitset>/stdc++.h>
using namespace std;

// Identification of the problem
// Diameter of a tree - longest path between two nodes in a tree
// Given a tree, find the diameter of the tree
// T.C O(n*n) - n is the number of nodes in the tree , recursive code

// By DP
// T.C O(n) - n is the number of nodes in the tree
// No of nodes along the longest path between two nodes in the tree
// not necessary to pass through the root
// Diameter of a tree = max(1+height(left)+height(right), diameter(left), diameter(right))

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

int diameter(Node* root, int &d){
    if(root == NULL) return 0;

    int lh = diameter(root->left, d);
    int rh = diameter(root->right, d);

    int temp = 1 + max(lh, rh);
    int ans = max(temp, 1+lh+rh);
    d = max(d, ans);

    return temp;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    int d = INT_MIN;
    diameter(root, d);
    cout << d << endl;
    return 0;
}