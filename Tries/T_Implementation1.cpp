#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* links[26];
    bool flag = false;

    bool containKeys(char ch){
        return (links[ch-'a']!=NULL);
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        flag = true;
    }
};

class Trie{
    public: Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKeys(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node* node = root;

        for(int i=0;i<word.size();i++){
            if(!node->containKeys(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string word){
        Node* node = root;

        for(int i=0;i<word.size();i++){
            if(!node->containKeys(word[i])){
                return false;
            }
            node = node->get(word[i]); 
        }
        return true;
    }
};

int main(){
    int n;
    cin>> n;
    vector<string> st;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st.push_back(s);
    }
    Trie trie;
    for(int i=0;i<n;i++){
        trie.insert(st[i]);
    }
    cout << trie.search(st[1]) << endl;
    cout << trie.startsWith(st[0]) << endl;

    return 0;
}