// Binary Search Tree
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// void inorder(Node* root){
//     if(root==NULL){
//         return;
//     }

//     inorder(root->left);
//     cout<< root->data << " ";
//     inorder(root->right);
// }

// search in BT
// t.c log2(n)
bool searchBT(Node *root, int d)
{
    if (root == NULL)
        return false;

    if (root->data == d)
        return true;

    if (d > root->data)
    {
        return searchBT(root->right, d);
    }
    else
    {
        return searchBT(root->left, d);
    }
    return false;
}
// or
Node *searchBST(Node *root, int val)
{
    while (root != NULL && root->data != val)
    {
        root = val < root->data ? root->left : root->right;
    }
    return root;
}

// Ceil in BST
// given a key you have to find number greatest then aur equal to  it.
// t.c log2(n)
void CeilBST(Node *root, int key, int &ceil)
{

    if (root == NULL)
        return;

    if (root->data >= key && ceil == -1)
    {
        ceil = root->data;
    }
    if (root->data >= key && root->data < ceil)
    {
        ceil = root->data;
    }
    if (root->data > key)
        CeilBST(root->left, key, ceil);
    else
        CeilBST(root->right, key, ceil);
}
// or
int findCeil(Node *root, int key)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }

        if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

// Floor in a BST
// t.c log2(n)
void floorBST(Node *root, int key, int &floor)
{
    if (root == NULL)
        return;

    if (root->data <= key && floor == -1)
    {
        floor = root->data;
    }
    if (root->data <= key && root->data > floor)
    {
        floor = root->data;
    }
    if (root->data > key)
        floorBST(root->left, key, floor);
    else
        floorBST(root->right, key, floor);
}
// or
int findFloor(Node *root, int key)
{
    int floor = -1;
    while (root)
    {
        if (root->data == key)
        {
            floor = root->data;
            return floor;
        }
        if (root->data < key)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}

// Insert a given Node in BST
// t.c O(log2(n))
void InsertNode(Node *root, int val)
{
    if (root == NULL)
    {
        Node *node = new Node(val);
        return;
    }
    Node *curr = root;
    while (true)
    {
        if (curr->data <= val)
        {
            if (curr->right != NULL)
                curr = curr->right;
            else
            {
                curr->right = new Node(val);
                break;
            }
        }
        else
        {
            if (curr->left != NULL)
                curr = curr->left;
            else
            {
                curr->left = new Node(val);
                break;
            }
        }
    }
}

// Delete a node in BST

Node *findLastRight(Node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findLastRight(root->right);
}
Node *helper(Node *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    else if (root->right == NULL)
    {
        return root->left;
    }

    Node *rightChild = root->right;
    Node *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

// K th smallest element in a BST
// inorder of bst ins always sorted
// recursive T.C O(n) S.C O(n)
// Morris T.c O(n) S.c O(1)
void inorder(Node *root, int k, int &cnt, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, k, cnt, ans);
    cnt++;
    if (cnt == k)
        ans = root->data;
    inorder(root->right, k, cnt, ans);
}
int kthSmallest(Node *root, int k)
{
    int cnt = 0, ans = 0;
    inorder(root, k, cnt, ans);
    return ans;
}

// kth larget element  n-k th smallest element
int findHeightLeft(Node *node)
{
    int hght = 0;
    while (node)
    {
        hght++;
        node = node->left;
    }
    return hght;
}
int findHeightRight(Node *node)
{
    int hght = 0;
    while (node)
    {
        hght++;
        node = node->right;
    }
    return hght;
}
int nodesInCBT(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if (lh == rh)
        return pow(2, lh) - 1;

    return 1 + nodesInCBT(root->left) + nodesInCBT(root->right);
}
void inorder1(Node *root, int k, int &cnt, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder1(root->left, k, cnt, ans);
    cnt++;
    if (cnt == k)
        ans = root->data;
    inorder1(root->right, k, cnt, ans);
}
int kthLargest(Node *root, int k)
{
    int cnt = 0, ans = 0;
    int num = nodesInCBT(root) - k + 1;
    inorder1(root, num, cnt, ans);
    return ans;
}

// Validate a BST
bool isValidBST(Node *root, int mini, int maxi)
{
    if (root == NULL)
        return true;
    if (root->data >= maxi || root->data <= mini)
        return false;
    return isValidBST(root->left, mini, root->data) && isValidBST(root->right, root->data, maxi);
}
bool validation(Node *root)
{
    return isValidBST(root, INT_MIN, INT_MAX);
}

// LCA -> Lowest Common ancestor
// T.C O(H)  .C O(n)// recursion stack space
Node *lowestCommonancestor(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return NULL;
    int curr = root->data;
    if (curr < p->data && curr < q->data)
    {
        return lowestCommonancestor(root->right, p, q);
    }
    if (curr > p->data && curr > q->data)
    {
        return lowestCommonancestor(root->left, p, q);
    }
    return root;
}

// Construct BST from preorder Traversal
// naive approach :- compare each node greater then root or not
// T.C O(n*n)
// second approach:-we have preorder, in bst inorder
// is sorted sort the preorder then by preorder and inorder construct the tree T.C O(n*log(n))+ O(n) S.C O(n)
// Optimized approach:- carrying one upper bound and keep checking by preorder and bst properties.
// T.C O(3*n)~O(n) S.C O(n)->recursion stack space
// IMP
Node *build(vector<int> &pre, int &i, int bound)
{
    if (i == pre.size() || pre[i] > bound)
        return NULL;
    Node *root = new Node(pre[i++]);
    root->left = build(pre, i, root->data);
    root->right = build(pre, i, bound);
    return root;
}
Node *bstFromPreorder(vector<int> &pre)
{
    int i = 0; // pointer in vector
    return build(pre, i, INT_MAX);
}

// Inorder Successor in BST
// it means after inordering the bst the element just after given value.
// brute :- T.C O(n) S.C O(n) store inorder then search elemnt print element after it.(sorted) if no successor return NULL.
// second :- in inorder next value greater then eight just print it. T.C O(n) S.C O(1) Not assume recursion stack space. or morris traversal
// optimized :- traverse tree by bst rules and keep one successor element.
Node *inorderSuccessor(Node *root, Node *p)
{
    Node *successor = NULL;

    while (root != NULL)
    {
        if (p->data >= root->data)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}
Node *inorderPrecessor(Node *root, Node *p)
{
    Node *precessor = NULL;

    while (root != NULL)
    {
        if (p->data > root->data)
        {
            precessor = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return precessor;
}

// BST Iterator
// brute force :- make inorder vector then print according to rules T.C O(1) S.C O(n)
// optimised :- take a stack in which put all element left then during time of removing check its right also.
// T.C O(1)-> per call O(1) S.C O(h)
// IMP
class BSTIterator
{
private:
    stack<Node*> myStack;

public:
    BSTIterator(Node *root)
    {
        pushAll(root);
    }
    //  return wether we have a next smallest number.
    bool hasNext()
    {
        return !myStack.empty();
    }

    // return the next smallest number.
    int next()
    {
        Node *tmpNode = myStack.top();
        mySrack.pop();
        pushAll(tmp->right);
        return tmpNode->data;
    }

private:
    void pushAll(Node *node)
    {
        for (; node != myStack.push(node), node = node->left)
            ;
    }
};

// Two Sum IV  (BST)
// sum of two nodes is equal to given value.
// brute force:- store inorder(sorted) in array by two pointer at start and end find two sum. T.C O(n) S.C O(n)
// optimised:-reduce space by traverse and continue see by self made constructor maintain prei=vious and next.
// T.C O(n) S.C O(h)*2

// IMP
// -------------------DOUBT----------------------
class BSTIterator
{
private:
    stack<Node *> myStack;
    // reverse -> true -> before
    // reverse -> false -> next
    bool reverse = true;

public:
    BSTIterator(Node *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }
    //  return wether we have a next smallest number.
    bool hasNext()
    {
        return !myStack.empty();
    }

    // return the next smallest number.
    int next()
    {
        Node *tmpNode = myStack.top();
        mySrack.pop();
        if (!reverse)
            pushAll(tmpNode->right);
        else
            pushAll(tmpNode->left);
        return tmpNode->data;
    }

private:
    void pushAll(Node *node)
    {
        for (; node != NULL;)
        {
            if (revrse == true)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
};
classs solution{
    public :
        bool findTarget(Node * root, int k){
            if (!root) return false;
// next
BSTIterator l(root, false);
// before
BSTIterator r(root, true);

int i = l.next();
int j = r.next(); // r.before();
while (i < j)
{
    if (i + j == k)
        return true;
    else if (i + j < k)
        i = l.next();
    else
        j = r.next();
}
return false;
}
}
;

// Recover a BST
// brute:- find inorder if wrong inorder not sorted then sort thw=e inorder check the tree with inorder change value in tree. T.C O(2*n)+O(nLog(n)) S.C O(n)
// better solution:- During inorder traversal check that curr node is greater then prev else make a pointer
// at end we get two node swap them.or paired voilation.if no second them first and middle will be swapped.
// T.C O(n) S.C O(1)
class Solve
{
private:
    Node *first;
    Node *prev;
    Node *middle;
    Node *last;

    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        if (prev != NULL && (root->datab < prev->data))
        {
            // if this is first violation,mark these as 'first' and 'middle'
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                // if this is second violation, mark this node as last
                last = root;
            }
        }
        // Mark this node as previous
        prev = root;
        inorder(root->left);
    }

public:
    void recoverTree(node *root)
    {
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->data, last->data);
        else if (first && middle)
            swap(first->data, middle->data);
    }
};

// largest BST in BT return size
//  T.C O(n) S.C O(1)
// store maximum and minimum at each node
// now for valid bst root > maximum left , root < minimum right , if this thing is wrong then assign max and min as max = int min and min = int max
// similarly at the end we get highest bst
class NodeValue
{
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
class Solve1
{
private:
    NodeValue largestBSTSubtreeHelper(Node *root)
    {
        // an empty tree is a bst of size 0
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // get values from left and right subtree of current tree
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // current node is greater than max in left and smaller than min in right, it is a BST
        if (left.maxNode < root->data && root->data < right.minNode)
        {
            // It is BST
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
        }

        // Otherwise, return [-inf,inf] so that parent can't be valdi BST
        return Nodevalue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBSTSubTree(Node *root)
    {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

int main()
{

    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(12);
    root->left->left = new Node(6);
    root->right->left = new Node(11);
    root->left->right = new Node(9);
    root->right->right = new Node(14);

    // cout<< searchBT( root,11) << endl;
    // cout<< searchBST(root,11) << endl;

    // int ceil = -1;
    // CeilBST(root,1,ceil);
    // cout << ceil << endl;
    // cout << findCeil(root, 1) << endl;

    // int floor = -1;
    // floorBST(root,8,floor);
    // cout<< floor << endl;
    // cout << findFloor(root,8);

    // inorder(root);cout<< endl;
    // InsertNode(root,8);
    // inorder(root);cout << endl;

    // cout << kthSmallest(root,3) << endl;
    // cout << kthLargest(root,3) << endl;

    // cout<< validation(root) << endl;

    // cout<< lowestCommonancestor(root,root->left->left,root->left->right)->data ;

    // cout<< inorderSuccessor(root,root->left)->data;
    cout << inorderPrecessor(root, root->left)->data;

    return 0;
}