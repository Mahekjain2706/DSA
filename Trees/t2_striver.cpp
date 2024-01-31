#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node* left;
   Node* right;

   Node(int val){
    this->data = val;
    this->left = NULL;
    this->right = NULL;
   }
};

// vector<vector<int>> levelorder(Node* root){
//     vector<vector<int>> ans;
//     if(root==NULL) return ans;
//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()){
//         int size = q.size();
//         vector<int>level;
//         for(int i=0;i<size;i++){
//             Node* node = q.front();
//             q.pop();
            
//             if(node->left!=NULL) q.push(node->left);
//             if(node->right!=NULL) q.push(node->right);
//             level.push_back(node->data);
//         }
//         ans.push_back(level);
//     }
//     return ans;
// }

// // Boundary add // DOUBT
// bool isLeaf(Node* root){
//     if(root==NULL) return false;

//     if(root->left==NULL && root->right==NULL) return true;
//     isLeaf(root->left);
//     isLeaf(root->right);
// }
// void addLeftNodes(Node* root,vector<int> &res){
//     Node* curr = root;
//     while(curr!=NULL){
//         if(isLeaf(curr)) res.push_back(curr->data);
//         if(curr->left) curr = curr->left;
//         else curr = curr->right;
//     }
// }
// void addLeaves(Node* root,vector<int> &res){
//     if(isLeaf(root)) {
//         res.push_back(root->data);
//         return;
//     }
//     if(root->left) addLeaves(root->left,res);
//     if(root->right) addLeaves(root->right,res);
// }
// void addRightNodes(Node* root,vector<int> &res){
//     Node* curr = root->right;
//     vector<int>temp;
//     while(curr){
//         if(isLeaf(curr)) temp.push_back(curr->data);
//         if(curr->right) curr = curr->right;
//         else curr = curr->left;
//     }

//     for(int i=temp.size()-1;i>=0;i--){
//         res.push_back(temp[i]);
//     }
// }
// vector<int> printBoundary(Node* root){
//     vector<int> res;
//     if(!root) return res;
//     if(isLeaf(root)) res.push_back(root->data);
//     addLeftNodes(root,res);
//     addLeaves(root,res);
//     addRightNodes(root,res);
//     return res;
// }

// // Vertical order
// vector<vector<int>> vertical(Node* root){
//     map<int,map<int,multiset<int>>> nodes;
//     queue<pair<Node*,pair<int,int>>> todo;
//     todo.push({root,{0,0}});
//     while(!todo.empty()){
//         auto it = todo.front();
//         todo.pop(); 
//         Node* node = it.first;
//         int x = it.second.first;int y = it.second.second;
//         nodes[x][y].insert(node->data);
//         if(node->left){
//             todo.push({node->left,{x-1,y+1}});
//         }
//         if(node->right){
//             todo.push({node->right,{x+1,y+1}});
//         }
//     }

//     vector<vector<int>> ans;
//     for(auto it: nodes){
//         vector<int> level;
//         for(auto q:it.second){
//             level.insert(level.end(),q.second.begin(),q.second.end());
//         }
//         ans.push_back(level);
//     }
//     return ans;
// }

// vector<int> topLevel(Node* root){
//        map<int,int> nodes;
//        queue<pair<Node*,int>> todo;
//        todo.push({root,0});

//        while(!todo.empty()){
//          auto it = todo.front();
//          todo.pop();
//          Node* node = it.first;int x = it.second;
//          if(nodes.find(x)==nodes.end()) nodes[x] = node->data;
//          if(root->left) todo.push({root->left,x-1});
//          if(root->right) todo.push({root->right,x+1});
//        }
//        vector<int> ans;
//        for(auto it:nodes){
//            ans.push_back(it.second);
//        }
//        return ans;
// }

// vector<int> bottomView(Node* root){
//     vector<int> ans;
//     if(root==NULL) return ans;
//     map<int,int> node;
//     queue<pair<Node*,int>> q;
//     q.push({root,0});

//     while(!q.empty()){
//         auto it = q.front();
//         q.pop();
//         Node* root = it.first;int x = it.second;
//         node[it.second] = it.first-> data;
//         if(root->left) q.push({root->left,x-1});
//          if(root->right) q.push({root->right,x+1});
//     }

//     for(auto it: node){
//         ans.push_back(it.second);
//     }
//     return ans;
// }

// Iterative
vector<vector<int>> RightLeftSideView(Node* root){
    vector<int>right,left;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node* root = q.front();
            q.pop();
            level.push_back(root->data);
            if(root->left!=NULL) q.push(root->left);
            if(root->right!=NULL) q.push(root->right);
        }
        right.push_back(level[level.size()-1]);
        left.push_back(level[0]);
    }
    vector<vector<int>> ans;
    ans.push_back(right);
    ans.push_back(left);
    return ans;
}
// Recursive
// Root right 
vector<int> rightSideView(Node* root){
    vector<int> res;
    RightView(root,0,res);
    return res;
}
void RightView(Node* root,int level,vector<int>&res){
    if(root==NULL){
        return;
    }
    if(res.size()==level) res.push_back(root->data);
    RightView(root->right,level+1,res);
    RightView(root->left,level+1,res);
}
// Root left
vector<int> leftSideView(Node* root){
    vector<int> res;
    LeftView(root,0,res);
    return res;
}
void LeftView(Node* root,int level,vector<int>&res){
    if(root==NULL){
        return;
    }
    if(res.size()==level) res.push_back(root->data);
    LeftView(root->left,level+1,res);
    LeftView(root->right,level+1,res);
}

int main(){
    TreeNode* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(4);
    root->left->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    // vector<vector<int>> ans = levelorder(root);
    // vector<vector<int>> ans = vertical(root);
    vector<vector<int>> ans = RightLeftSideView(root);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<< ans[i][j] << " ";
        }
        cout<< endl;
    }

    // vector<int> ans = printBoundary(root);
    // vector<int> ans = topLevel(root);
    // for(int i=0;i<ans.size();i++){
    //     cout<< ans[i] << " ";
    // }

    return 0;
}