#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* links[26];
    bool flag = false;

    bool containKeys(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        flag = true;
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;

        for(int i=0;i<word.size();i++){
            if(!node->containKeys(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkSubstr(string &word){
        Node* node = root;
        
        for(int i=0;i<word.size();i++){
            if(node->containKeys(word[i])){
                node = node->get(word[i]);
                if(node->isEnd()==false) return false;
            }else{
                return false;
            }
        }
        return true;
    }
};

string completeString(int n,vector<string> &st){

    Trie trie;
    for(auto &it:st){
        trie.insert(it);
    }

    string ans = "";
    for(auto &it:st){
        if(trie.checkSubstr(it)){
            if(ans.size()<it.size()){
                ans = it;
            }
            else if(ans.size()==st.size()){
                if(it<ans){
                    ans = it;
                }
            }
        }
    }
    if(ans=="") return "None";
    return ans;
}
int main(){

    int n;cin>>n;
    vector<string> vec;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        vec.push_back(s);
    }

    cout<< completeString(n,vec) << endl;
    return 0;
}