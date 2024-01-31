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

void preorder(Node* root){
    if(root==NULL) return;

    cout<< root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// or
vector<int> preorder1(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;

    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();

        ans.push_back(node->data);
        if(node->right){
            st.push(node->right);
        }
        if(node->left){
            st.push(node->left);
        }
    }
    return ans;
}

void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}
// or
vector<int> inorder(Node* root){
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
            if(st.empty()==true) break;

            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            curr = temp->right;
        }
    }
    return ans;
}

void postorder(Node* root){
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<< root->data << " ";
}
// or
vector<int> postorder1(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;

    stack<Node*> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        Node* node = st1.top();
        st1.pop();

        st2.push(node);
        if(node->left) st1.push(root->left);
        if(node->right) st1.push(root->right);
    }

    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}
// or
vv=ector<int> postorder2(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;

    stack<Node*> st;
    Node* curr - root;

    while(curr!=NULL || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }else{
            Node* temp = st.top()->right;
            if(temp==NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);

                while(!st.empty() && temp == st.top()->right){
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

vector<vector<int>> levelOrder(Node* &root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            level.push_back(node->data);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<vector<int>> zigzagOrder(Node* &root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;

    queue<Node*> q;
    q.push(root);
    bool flag = 0;
    while(!q.empty()){
        int size = q.size();
        vector<int> zig(size);
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();

            int ind = (flag==0) i : (size-i+1);
            zig[ind] = node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
        flag = !flag;
    }
    return ans;
}

vector<vector<int>> pipOrder(Node* root){
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    vector<int> pre,ini,post;
    stack<pair<int,int>> st;
    st.push({root,1});

    while(!q.empty()){
        auto it = st.front();
        st.pop();

        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL){
                st.push({it.first->left,1});
            }
        }
        else if(t.second==2){
            ini.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL){
                st.push({it.first->right,1});
            }
        }else{
            post.push_back(it.first->data);
        }
    }

    ans.push_back(pre);
    ans.push_back(ini);
    ans.push_back(post);
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
    dia = max(dia,lh+rh);

    return 1 + max(lh,rh);
}
int diaM(Node* root){
    int dia = 0;
    diameter(root,dia);
    return dia;
}

int check(Node* root){
    if(root==NULL) return -1;

    int lh = check(root->left);
    if(lh==-1) return -1;
    int rh = check(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;

    return 1 + max(lh,rh);
}
bool isTree(Node* root){
    if(check(root)==-1) return false;
    return true; 
}

int maxiP(Node* root,int maxi){
    if(root==NULL) return 0;

    int lh =max(0,maxiP(root->left,maxi));
    int rh = max(0,maxiP(root->right,maxi));
    maxi = max(maxi,lh+root->data+rh);

    return root->data + max(h,rh);
}
int maxPath(Node* root){
    int maxi = 0;
    return maxiP(root,maxi);
}

bool isSame(Node* &p,Node* q){
    if(p==NULL || q==NULL){
        return (p==q);
    }

    return (p->data==q->data) && isSame(p->left,q->left) && isSame(p->right,q->right);
}

// maxi path
int maxiDepth(Node* root){
    if(root==NULL) return 0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    int max_depth = 0;
    while(!q.empty()){
        int size = q.size();
        int curr_min = q.front().second;
        int first = 0,last = 0;
        for(int i=0;i<size;i++){
            auto it = q.front();
            Node* node = it.first;
            q.pop();
            int curr_id = it.second-curr_min;
            if(i==0) first = it.second;
            if(i==size-1) last = it.second;

            if(node->left){
                q.push({node->left,2*curr_id+1});
            }
            if(node->right){
                q.push({node->right,2*curr_id+2});
            }
        }
        max_depth = max(max_depth,last_first+1);
    }
    return max_depth;
}

// root to node Path
bool getPath(Node* root,int val,vector<int> ans){
    if(root==NULL) return false;

    ans.push_back(root->data);
    if(root->data==val) return true;
    if(getPath(root->left,val,ans) || getPath(root->right,val,ans)) return true;
    ans.pop_back();
    return false;
}
vector<int> Path(Node* root,int val){
    vector<int> ans;
    if(getPath(root,val,ans)==true) return ans;
    return ans;
}

// Lowest Common Ancestor
Node* Lca(Node* root,Node* a,Node* b){
    if(root==NULL) return root;
    if(root==p || root==q) return root;

    Node* left = Lca(root->left,p,q);
    Node* right = Lca(root->right,p,q);

    if(left==NULL) return right;
    if(right==NULL) return left;
    else return root;
}

//Children Sum property

void ChangeTree(Node* root){
    if(root==NULL) return;
    int child = 0;
    if(root->left !=NULL){
        child+= root->left->data;
    }
    if(root->right!=NULL){
        child+= root->right->data;
    }
    if(child>root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }
    
    int tot = 0;
    if(root->left) tot+= root->left->data;
    if(root->right) tot+= root->right->data;
    if(root->right || root->left) root->data = tot;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return 0;
}