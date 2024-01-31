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

void preorder(Node* root){
    if(root==NULL) return ;

    cout<< root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// OR
vector<int> preorderI(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right!=NULL) st.push(root->right);
        if(root->left!=NULL) st.push(root->left);
    }
    return ans;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}
// or
vector<int> inorder1(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st;
    Node* curr = root;

    while(true){
        if(curr!=NULL){
           st.push(curr);
        curr = curr->left;
        }
        else{
            if(st.empty()==true) break;
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
    return ans;
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data << " ";
}
// or 
vector<int> postorderI(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL) st1.push(root->left);
        if(root->right!=NULL) st1.push(root->right);
    }

    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}
// or
vector<int> postorderII(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st;
    Node* curr = root;

    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr= curr->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp==NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else{
                    curr = temp;
            }
        }
    }
    return ans;
}

vector<vector<int>> levelorder(Node* root){
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

vector<vector<int>> piporder(Node* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    vector<int> pre,in,post;
    stack<pair<Node*,int>> q;
    q.push(make_pair(root,1));

    while(!q.empty()){
        auto it = q.top();
        q.pop();

        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            q.push(it);

            if(it.first->left!=NULL){
                q.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            q.push(it);

            if(it.first->right!=NULL){
                q.push({it.first->right,1});
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

int maxDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh,rh);
}
// or
int maxDepth1(Node* root){
    if(root==NULL) return 0;
    queue<Node*> q;
    q.push(root);
    int cnt=0;

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        cnt++;
    }
    return cnt;
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
bool checkBT(Node* root){
    if(check(root)==-1) return false;
    else  return true;
}

int diameter(Node* root,int &maxi){
    if(root==NULL) return 0;

    int lh = diameter(root->left,maxi);
    int rh = diameter(root->right,maxi);
    maxi = max(maxi,lh+rh);

    return 1 + max(lh,rh);
}
int diameterBT(Node* root){
    int dia=0;
    diameter(root,dia);
    return dia;
}

int maxP(Node* root,int &maxi){
    if(root==NULL) return 0;

    int lh = max(maxP(root->left,maxi),0);
    int rh = max(maxP(root->right,maxi),0);
    maxi = max(maxi,root->data + lh + rh);

    return root->data + max(lh,rh);
}
int maxiPath(Node* root){
    int maxi=0;
    maxP(root,maxi);
    return maxi;
}

bool Identical(Node* p, Node* q){
    if(p==NULL || q==NULL){
        return p==q;
    }

    return (p->data == q->data) 
    && Identical(p->left,q->left)
    && Identical(p->right,q->right);
}

vector<vector<int>> zigzag(Node* root){
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
            int index = (flag==0) ? i : (size-1-i);
            zig[index] = root->data;
            if(root->left!=NULL) q.push(root->left);
            if(root->right!=NULL) q.push(root->right);
        }
        flag = !flag;
        ans.push_back(zig);
    }
    return ans;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(4);
    root->left->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    // Node* root1 = new Node(1);
    // root1->left = new Node(2);
    // root1->right = new Node(3);
    // root1->left->left = new Node(4);
    // root1->left->right = new Node(3);
    // root1->left->left->left = new Node(5);
    // root1->right->right = new Node(6);
    // root1->right->right->left = new Node(7);

    
//    preorder(root);
//    inorder(root);
//    postorder(root);

//    vector<int> ans = preorderI(root);
//    vector<int> ans = inorderI(root);
//    vector<int> ans = postorderI(root);
//    vector<int> ans = postorderII(root);

//    for(int i=0;i<ans.size();i++){
//     cout<< ans[i] << " ";
//    }

//    vector<vector<int>> ans = levelorder(root);
//    vector<vector<int>> ans = piporder(root);
//    vector<vector<int>> ans = zigzag(root);
    
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[i].size();j++){
//             cout<< ans[i][j] << " ";
//         }
//         cout<< endl;
//     }

//     cout<< maxDepth(root) << endl;
//     cout<< maxDepth1(root) << endl;
//     cout<< checkBT(root) << endl;
//     cout<< diameterBT(root) << endl;
//     cout<< maxiPath(root) << endl;
//     cout<< Identical(root,root1) << endl;


    return 0;
}

