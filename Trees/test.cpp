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

void preorder(Node* &root){
    if(root==NULL){
        return;
    }

    cout<< root->data<<' ';
    preorder(root->left);
    preorder(root->right);
}
// or
vector<int> preorder1(Node* &root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* root = st.top();
        st.pop();

        ans.push_back(root->data);
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }
    return ans;
}

void inorder(Node* &root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}
// or
vector<int> inorder1(Node* &root){
    vector<int> ans;
    if(root==NULL) return ans;
    Node* curr = root;
    stack<Node*> st;
    
    while(true){
        if(curr){
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

void postorder(Node* &root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data << ' ';
}
// or 
vector<int> postorder1(Node* &root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        root = st1.top();
        st1.pop();

        st2.push(root);
        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
    }

    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}
// or 
vector<int> postorder2(Node* &root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st;
    Node* curr = root;

    while(curr!=NULL || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp==NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp = st.top();
                    ans.push_back(temp->data);
                    st.pop();
                }
            }else{
                curr = temp;
            }
        }
    }
    return ans;
}

vector<vector<int>> levelorder(Node* &root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            root = q.front();
            q.pop();
            level.push_back(root->data);
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        ans.push_back(level);
    }

    return ans;
}

vector<vector<int>> piporder(Node* &root){
    vector<vector<int>> ans;
    vector<int> pre,in,post;
    if(root==NULL) return ans;
    stack<pair<Node*,int>> st;
    st.push({root,1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second==1){
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it);

            if(it.first->left){
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second = 3;
            st.push(it);

            if(it.first->right){
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

vector<vector<int>> zigzagorder(Node* &root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);
    bool flag=0;
    while(!q.empty()){
        int size = q.size();
        vector<int> zig(size);

        for(int i=0;i<size;i++){
            root = q.front();
            q.pop();

            int index = (flag==0) ? i :(size-i-1);
            zig[index] = root->data;
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        flag =! flag;
        ans.push_back(zig);
    }
    return ans;
}

int maxDepth(Node* &root){
    if(root==NULL) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh,rh);
}

int diameter(Node* root,int &dia){
    if(root==NULL) return 0;

    int lh = diameter(root->left,dia);
    int rh = diameter(root->right,dia);
    dia = max(dia,lh + rh);

    return 1 + max(lh,rh);
}
int diameterP(Node*  &root){
    int dia = 0;
    diameter(root,dia);
    return dia;
}

int check(Node* &root){
    if(root==NULL) return -1;

    int lh = check(root->left);
    if(lh==-1) return -1;
    int rh = check(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    
    return 1 + max(lh,rh);
}
bool checkBT(Node* &root){
    if(check(root)==-1) return false;
    return true;
}

int maxP(Node* &root,int &maxi){
    if(root==NULL) return 0;

    int lh = max(maxP(root->left,maxi),0);
    int rh = max(maxP(root->right,maxi),0);
    maxi = max(maxi,root->data + lh + rh);

    return root->data + max(lh,rh);
}
int maxPath(Node*  &root){
    int maxi = 0;
    maxP(root,maxi);
    return maxi;
}

bool isSame(Node* &p,Node* &q){
    if(p==NULL || q==NULL){
        return (p==q);
    }

    return (p->data==q->data) && isSame(p->left,q->left) && isSame(p->right,q->right);
}

// boundary level
bool isLeaf(Node* &root){
    if(root==NULL){
        return false;
    }

    if(root->left==NULL && root->right==NULL){
        return true;
    }
    
    isLeaf(root->left);
    isLeaf(root->right);
}
void addLeftNode(Node* &root,vector<int> &res){
    if(root==NULL){
        return;
    }

    while(root){
        if(isLeaf(root)) res.push_back(root->data);
        if(root->left) root = root->left;
        else root = root->right;
    }
}
void addLeaveNode(Node* &root,vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaveNode(root->left,res);
    if(root->right) addLeaveNode(root->right,res);
}
void addRightNode(Node* &root,vector<int> &res){
    vector<int> temp;
    if(root==NULL){
        return;
    }

    while(root){
        if(isLeaf(root)) temp.push_back(root->data);
        if(root->right) root = root->right;
        else root = root->left;
    }

    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}
vector<int> Boundryorder(Node* &root){
    vector<int> res;
    if(root==NULL) return res;

    if(isLeaf(root)) res.push_back(root->data);
    addLeftNode(root,res);
    addLeaveNode(root,res);
    addRightNode(root,res);
    return res;
}

// Vertical Order
vector<vector<int>> VerticalOrder(Node* &root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    
    queue<pair<Node*,pair<int,int>>> q;
    map<int,map<int,multiset<int>>> mp;
    q.push({root,{0,0}});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* root = it.first;
        int x = it.second.first;
        int y = it.second.second;

        mp[x][y].insert(root->data);
        if(root->left) q.push({root->left,{x-1,y+1}});
        if(root->right) q.push({root->right,{x+1,y+1}});
    }
    
    for(auto it:mp){
        vector<int> level;
        for(auto p:it.second){
            level.insert(level.end(),p.second.begin(),p.second.end());
        }
        ans.push_back(level);
    }
    return ans;
}

// top 
vector<int> TopLevel(Node* &root){
    vector<int> ans;
    // if(root==NULL){
    //     return ans;
    // }
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* root = it.first;
        int x = it.second;
        if(mp.find(x)==mp.end()) mp[x] = root->data;
        if(root->left) q.push({root->left,x-1});
        if(root->right) q.push({root->right,x+1});
    }

    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}

// Bottom Level

vector<int> bottomLevel(Node* &root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    queue<pair<Node*,int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* root = it.first;
        int x = it.second;
        mp[x] = root->data;
        if(root->left) q.push({root->left,x-1});
        if(root->right) q.push({root->right,x+1});
    }

    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}

void RightSideView(Node* &root,int level,vector<int>&res){
    if(root==NULL){
        return;
    }
    if(res.size()==level) res.push_back(root->data);
    RightSideView(root->right,level+1,res);
    RightSideView(root->left,level+1,res);
}
vector<int> RightSide(Node* &root){
    vector<int> res;
    RightSideView(root,0,res);
    return res;
}

void LeftSideView(Node* &root,int level,vector<int> &res){
    if(root==NULL){
        return;
    }

    if(res.size()==level) res.push_back(root->data);
    LeftSideView(root->left,level+1,res);
    LeftSideView(root->right,level+1,res);
}
vector<int> LeftSide(Node*  &root){
    vector<int> res;
    LeftSideView(root,0,res);
    return res;
}


int main(){
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(7);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(13);

    // preorder(root);
    // cout<< endl;

    // inorder(root);
    // cout<< endl;

    // postorder(root);
    // cout<< endl;

    // vector<int> ans = preorder1(root);
    // vector<int> ans = inorder1(root);
    // vector<int> ans = postorder1(root);
    // vector<int> ans = postorder2(root); 
    // for(int i=0;i<ans.size();i++){
    //     cout<< ans[i]<< " ";
    // }
    
    // vector<vector<int>> ans = levelorder(root);
    // vector<vector<int>> ans = piporder(root);
    // vector<vector<int>> ans = zigzagorder(root);
    // vector<vector<int>> ans = VerticalOrder(root);
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<< ans[i][j] << ' ';
    //     }
    //     cout<< endl;
    // }

    // cout<< maxDepth(root) << endl;
    // cout<< diameterP(root) << endl;
    // cout<< checkBT(root) << endl;

    // vector<int> ans = Boundryorder(root);
    // vector<int> ans = TopLevel(root);
    // vector<int> ans = bottomLevel(root);
    // vector<int> ans = LeftSide(root);
    // vector<int> ans = RightSide(root);
    // for(int i=0;i<ans.size();i++){
    //     cout<< ans[i] << endl;
    // }

    return 0;
}