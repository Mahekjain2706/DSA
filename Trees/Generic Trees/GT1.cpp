#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> child;

    Node(int d){
        this->data = d;
        for(auto it:child){
            it=NULL;
        }
    }
};

// T.C O(n) S.C O(n)
vector<vector<int>> levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;

    while(!q.empty()){
        int size = q.size();
        // vector<int> level;

        for(int i=0;i<size;i++){
            Node* node = q.front();q.pop();
            // level.push_back(node->data);
            cout<< node->data << " ";
            for(int i=0;i<node->child.size();i++){
                q.push(node->child[i]);
            }
        }
        cout<< endl;
        // ans.push_back(level);
    }
    return ans;
}

int main(){
    Node* root = new Node(0);
    (root->child).push_back(new Node(1));
    (root->child).push_back(new Node(2));
    (root->child).push_back(new Node(3));
    (root->child).push_back(new Node(4));
    (root->child[0]->child).push_back(new Node(111));
    (root->child[0]->child).push_back(new Node(122));
    (root->child[0]->child).push_back(new Node(133));
    (root->child[1]->child).push_back(new Node(211));
    (root->child[1]->child).push_back(new Node(222));
    (root->child[1]->child).push_back(new Node(233));

    vector<vector<int>> ans = levelOrder(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<< ans[i][j]<<" ";
        }
        cout<< endl;
    };
    
    return 0;
}