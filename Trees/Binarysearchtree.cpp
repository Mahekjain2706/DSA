#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root,int d){
   // base case
   if(root ==NULL){
     root = new Node(d);
     return root;
   }

   if(d>root->data){
    root->right = insertIntoBST(root->right,d);
   }
   else{
    root->left = insertIntoBST(root->left,d);
   }
   return root;
}

int takeInput(Node* root){
   int data;
   cin>>data;

   while(data !=-1){
     root = insertIntoBST(root,data);
     cin>>data;
   }
}

// vector<vector<int>> levelorder(Node* root){
//     vector<vector<int>> ans;

//     if(root==NULL) return ans;
//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()){
//         int size = q.size();
//         vector<int>level;
//         for(int i=0;i<size;i++){
//             root = q.front();
//             q.pop();
//             level.push_back(root->data);
//             if(root->left) q.push(root->left);
//             if(root->right) q.push(root->right);
//         }
//         ans.push_back(level);
//     }

//     return ans;
// }

int main(){

    Node* root = NULL;

    cout<< "Enter data to create BST" << endl;
    takeInput(root);

    // vector<vector<int>> ans = levelorder(root);
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //        cout<< ans[i][j] << " ";
    //     }
    //     cout<< endl;
    // }

return 0;
}