#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}
// symmetric BT
bool identical(Node* p,Node* q){
    if(p==NULL || q==NULL){
        return p==q;
    }
    if(p->data !=q->data) return false;
    return identical(p->left,q->left) &&
    identical(p->right,q->right);
}
bool Symmetric(Node* root){
    return root==NULL || identical(root->left,root->right);
}

// root to Node Path
// given node leaf or any we have to return its path from root
// we use inorder Traversal
// T.c O(n)  s.c O(h)
bool getPath(Node* root,vector<int> &arr,int x){
    if(!root){
        return false;
    }
    arr.push_back(root->data);
    if(root->data==x){
        return true;
    }

    if(getPath(root->left,arr,x) || getPath(root->right,arr,x)) return true;

    arr.pop_back();
    return false; 
}
vector<int> Path(Node* root,int val){
    vector<int> arr;
    if(root==NULL){
        return arr;
    }
    getPath(root,arr,val);
    return arr;
}

// Lowest Common Ancestors
// lca of two nodes which is ancestor of both and more near that node
// T.c O(n)+O(h) S.c O(h1*h2)
int Lca(Node* root,int a,int b){
    vector<int> first = Path(root,a);
    vector<int> second = Path(root,b);
    int ans = 0;
    for(int i=0;i<min(first.size(),second.size());i++){
        if(first[i]!=second[i]){
            ans = first[i-1];
            break;
        }
    }
    return ans;
}
// or
Node* lowestCommonAncestor(Node* root,Node* p,Node* q){
    // base case
    if(root==NULL || p==NULL || q==NULL){
        return root;
    }
    Node* left = lowestCommonAncestor(root->left,p,q);
    Node* right = lowestCommonAncestor(root->right,p,q);

    // result
    if(left==NULL){
        return right;
    }
    else if(right==NULL){
        return left;
    }
    else{ // both is not NULL
        return root;
    }
}

// Maximum Width of Binary Tree
// T.c O(n) s.c o(h)
// int widthOfBT(Node* root){
//     if(root==NULL){
//         return 0;
//     }
//     int ans = 0;
//     queue<pair<Node*,int>> q;
//     q.push({root,0});

//     while(!q.empty()){
//         int size = q.size();
//         int min = q.front().second;  // to make the id starting from zero
//         int first,last;
//         for(int i=0;i<size;i++){
//             int cur_id = q.front().second-min;
//             Node* node = q.front().first;
//             q.pop();
//             if(i==0) first = curr_id;
//             if(i==size-1) last = curr_id;
//             if(node->left){
//                 q.push({node->left,curr_id*2+1});
//             }
//             if(node->right){
//                 q.push({node->right,curr_id*2+2});
//             }
//         }
//         ans = max(ans,last-first+1);
//     }
//     return ans;
// }

// Children Sum Property
// in this sum of child node must be equal to parent node to make this we can increase anynode by +1 any number of time
// sol - we check the sum of value of child nodes of root<root then assign value same as root 
// and continue check else if sum is greater then parent node then sum of root = parent node

// try
// Node* childrenSumProp(Node* root){
//     if(root==NULL){
//         return NULL;
//     }
    
//     int lh = childrenSumProp(root->left) ->data;
//     int rh = childrenSumProp(root->right) ->data;

//     if(lh+rh < root->data){
//         if(root->left) root->left->data = root->data;
//         if(root->right) root->right->data = root->data;
//         root->data = 2*root->data;
//     }
//     else{
//         root->data = lh + rh;
//     }
//     return root;
// }

// solution
// T.c o(n)
void changeTree(Node* root){
    if(root==NULL) return;
    int child = 0;
    if(root->left){
        child += root->left->data;
    }
    if(root->right){
        child += root->right->data;
    }

    if(child>=root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data += tot;
}

// Nodes at a distance k
// T.C O(n)parent + bfs S.C O(n)unordered_map+O(n)visited
void markParents(Node* root,unordered_map<Node*,Node*> &parent_track,Node* target){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->left){
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
vector<int> distanceK(Node* root,Node* target,int k){
    unordered_map<Node*,Node*> parent_track;
    markParents(root,parent_track,target);

    unordered_map<Node*,bool> visit;
    queue<Node*> q;
    q.push(target);
    visit[target] = true;
    int curr_level = 0;
    while(!q.empty()){
        int size = q.size();
        if(curr_level++ == k) break;// level order
        for(int i=0;i<size;i++){ // indentation
            Node* curr = q.front();
            q.pop();
            if(curr->left && !visit[curr->left]){
                q.push(curr->left);
                visit[curr->left] = true;
            }
            if(curr->right && !visit[curr->right]){
                q.push(curr->right);
                visit[curr->right] = true;
            }// same for parent
            if(parent_track[curr] && !visit[parent_track[curr]]){
                q.push(parent_track[curr]);
                visit[parent_track[curr]] = true;
            }
        }
    }
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front()->data);
        q.pop();
    }// example ke through kar
    return ans;// indentation theek kar
}



// Min Time taken to burn a BT from a node
// my Sol
// T.c O(n) S.c O(n)
Node* markParent_Node(Node* root,unordered_map<Node*,Node*> &parent_track,int &k){
    queue<Node*> q;
    q.push(root);
    Node* target;
    while(!q.empty()){
       Node* curr = q.front(); 
       q.pop();
       if(curr->data == k) target = curr;
       if(curr->left){
        parent_track[curr->left] = curr;
        q.push(curr->left);
       }
       if(curr->right){
        parent_track[curr->right] = curr;
        q.push(curr->right);
       }
    }
    return target;
}
int burnTime(Node* root,int k){
    unordered_map<Node*,Node*> parent_track;
    
    Node* node = markParent_Node(root,parent_track,k);
    unordered_map<Node*,bool> visit;
    visit[node] = true;
    queue<Node*> q;
    q.push(node);
    int time = 0;
    while(!q.empty()){
        time++;
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left && !visit[curr->left]){
                q.push(curr->left);
                visit[curr->left] = true;
            }
            if(curr->right && !visit[curr->right]){
                q.push(curr->right);
                visit[curr->right] = true;
            }
            if(parent_track[curr] && !visit[parent_track[curr]]){
                q.push(parent_track[curr]);
                visit[parent_track[curr]] = true;
            }
        }
    }
    return time;
}

// HEIGHT OF TREE IN WORST CASE IS  O(LOG(N))
// IF H HEIGHT NO.OF NODES POW(2,H)-1 if all node are their

// Complete Tree - all nodes are filled first in left and level wise.
// to find the nodes in complete BT we check that lh and rh if same or not.
// if same then 2^h-1 nodes + root else recursive travel to their leafs.
// t,c O((log(n))^2)  S.c O(log(n))
int findHeightLeft(Node* node){
    int hght = 0;
    while(node){
        hght++;
        node = node->left;
    }
    return hght;
}
int findHeightRight(Node* node){
    int hght = 0;
    while(node){
        hght++;
        node = node->right;
    }
    return hght;
}
int nodesInCBT(Node* root){
    if(root==NULL) return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if(lh==rh) return pow(2,lh)-1;

    return 1 + nodesInCBT(root->left)+ nodesInCBT(root->right);
}

// preorder , inorder
// T.c O(n) S.c O(n)
Node* buildTree1(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &mp){
    if(preStart>preEnd || inStart>inEnd){
        return NULL;
    }

    Node* root = new Node(preorder[preStart]);

    int inRoot = mp[root->data];
    int numLeft = inRoot - inStart;

    root->left = buildTree1(preorder,preStart+1,preStart+numLeft,inorder,inStart,inRoot-1,mp);

    root->right = buildTree1(preorder,preStart+numLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);

    return root;
}
Node* preInOrder(vector<int> &inorder,vector<int> &preorder){
    if(inorder.size()!=preorder.size()) return NULL;
    map<int,int> mp;

    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]] = i;
    }
    Node* root = buildTree1(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    return root;
}

// postorder, inorder
// T.c O(n) x log(n)  S.c O(n)
Node* buildTree2(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int postStart,int postEnd,map<int,int> &mp){
    if(postStart>postEnd || inStart>inEnd) return NULL;

    Node* root = new Node(postorder[postEnd]);

    int inRoot = mp[root->data];
    int numLeft = inRoot-inStart;

    root->left = buildTree2(inorder,inStart,inRoot-1,postorder,postStart,postStart+numLeft-1,mp);
    root->right = buildTree2(inorder,inRoot+1,inEnd,postorder,postStart+numLeft,postEnd-1,mp);

    return root;
}
Node* postInOrder(vector<int> &postorder,vector<int> &inorder){
    if(inorder.size()!=postorder.size()) return NULL;
    map<int,int> mp;

    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]] = i;
    }

    Node* root = buildTree2(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);

    return root;
}

// Serialize : root->string 
// De-serialize : string->root
string serialize(Node* root){
    if(!root) return "";

    string s = "";
    queue<Node*> q;
    q.push(root);
    s.append(to_string(root->data)+",");
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        // 1.
        if(node==NULL) s.append("#,");
        else s.append(to_string(node->data)+",");
        if(node!=NULL){
            q.push(node->left);
            q.push(node->right);
        }
        // Or
        // 2.
        // if(node->left){
        //     s.append(to_string(node->left->data)+",");
        //     q.push(node->left);
        // }
        // else{
        //     s.append("#,");
        // }

        // if(node->right){
        //     s.append(to_string(node->right->data)+",");
        //     q.push(node->right);
        // }
        // else{
        //     s.append("#,");
        // }
    }
    return s;
}

// t.c O(n) s.c O(n)
Node* deserialize(string data){
    if(data.size()==0) return NULL;
    stringstream s(data); // string to be traverse as object
    string str;
    getline(s,str,',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        getline(s,str,',');
        if(str == '#'){
            node->left = NULL;
        }
        else{
            Node* leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s,str,',');
        if(str == '#'){
            node->right = NULL;
        }
        else{
            Node* rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// morris Traversal
// same as inorder convert to preorder by one line change in In,Pre,Post take T.c O(n) S.c O(n) 
// In morris Traversal take T.c O(n) s.c O(1) uses Threaded Binary Tree
// video 38 DOUBT

// Flatten a BT
// rearrange the tree to linklist in preorder traversal
// video 39 DOUBT



int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->left->left->left= new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    // cout<< Symmetric(root) << endl;
    // vector<int> ans = Path(root,7);
    // for(int i=0;i<ans.size();i++){
    //     cout<< ans[i] << " ";
    // }
    
    // cout<< Lca(root,5,9) << endl;
    // Node* node = lowestCommonAncestor(root,root->left->left,root->left->right);
    // cout<< node->data << endl;

    // vector<vector<int>> ans = levelOrder(root);
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<< ans[i][j] << " ";
    //     }cout<< endl;
    // }
    // root = childrenSumProp(root);
    // changeTree(root);

    // vector<int> ans = distanceK(root,root->left,2);
    // for(int i=0;i<ans.size();i++){
    //     cout<< ans[i] << " ";
    // }cout<< endl;

    // cout<< burnTime(root,4)<< endl;
    // cout<< nodesInCBT(root)<< endl;
    cout<< serialize(root) << endl;
    return 0;
}