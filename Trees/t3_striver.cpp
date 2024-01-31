#include<bits/stdc++.h>
using namespace std;

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
};

// Maximum Width->maximum no.of nodes in a level btw to nodes
int maxWidth(Node* root){ // T.c O(n)  S.c O(n)
    if(!root){
        return 0;
    }
    int ans = 0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second; // to make the id starting from zero
        int first,last;
        for(int i=0;i<size;i++){
            int cur_id = q.front().second-mmin;
            Node* node = q.front().first;
            q.pop();
            if(i==0) first = cur_id;
            if(i==size-1) last = cur_id;
            if(node->left) 
                q.push({node->left,cur_id*2+1});
            if(node->right)
                q.push({node->right,cur_id*2+2});
        }
        ans = max(ans,last-first+1);
    }
    return ans;
}

// tree from preorder and inorder
// inorder left,root,right   preorder root,left,right
// T>C O(N)      S>C O(N)
Node* buildtree(vector<int>&preorder,vector<int>&inorder){  
    map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    Node* root = buildtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1, mp );
    
    ret urn root;
}
Node* buildtree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>mp){
    if(preStart>preEnd || inStart>inEnd) return NULL;

    Node* root = new Node(preorder[preStart]);

    int inRoot = mp[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildtree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mp);

    root->right = buildtree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);

    return root;
}

// Tree feom postorder,inorder
// postorder left,right,root    inorder left,root,right
Node* MakeTree(vector<int>&inorder,vector<int>&postorder){
    if(inorder.size() != postorder.size()) return NULL;
    map<int,int> mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }

    Node* root = MakeTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);

    return root;
}
Node* MakeTree(vector<int>&inorder,int inStart,int inEnd,vector<int>&postorder,int postStart,int postEnd,map<int,int>mp){
   if(inStart>inEnd || postStart>postEnd) return NULL;

   Node* root = new Node(postorder[postEnd]);

   int inRoot = mp[node->data];
   int inLeft = inRoot - inStart;

   root->left = MakeTree(inorder,inStart,inRoot-1,postorder,postStart,postStart+inLeft-1,mp);
   root->right = MakeTree(inorder,inRoot+1,inEnd,postorder,inLeft+postStart,postEnd-1,mp);
   return root;
}

vector<int> preorder(Node* root){
    vector<int>ans;
    if(root==NULL){
      return ans;
    }
    stack<Node*> st;
    st.push(root);

    while(!q.empty()){
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right!=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
    }
    return ans;
}

// DOUBT // LECT-25
// flatten a binary tree to linklist
// Recursive T.c O(n) S.c O(n)
Node* prev = NULL;
void Flatten(Node* node){
    if(node==NULL) return;
    Flatten(node->right);
    Flatten(node->left);

    node->right = prev;
    node->left = NULL;
    prev = node;
}
// Or
// Stack



int main(){
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(4);
    // root->left->left->left = new Node(5);
    // root->right->right = new Node(6);
    // root->right->right->left = new Node(7);

    vector<int> inorder = {5,4,2,4,1,3,6,7};
    vector<int> preorder = {1,2,4,5,4,3,6,7};
    vector<int> postorder = {5,4,4,2,7,6,3,1};
    Node* node = buildtree(inorder,preorder);
    cout<< node->data << " ";

    return 0;
}

