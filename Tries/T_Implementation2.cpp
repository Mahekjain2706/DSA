#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* links[26];
    int cp=0;
    int ew=0;

    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    void increasePrefix(){
        cp++;
    }
    void increseEnd(){
        ew++;
    }

    void decresePrefix(){
        cp--;
    }
    void removeEnd(){
        ew--;
    }

    int getEnd(){
        return ew;
    }
    int getPrefix(){
        return cp;
    }

};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;

        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increseEnd();
    }

    int countWordsEqual(string word){
        Node* node = root;

        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartWith(string word){
        Node* node = root;

        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string word){
        Node* node = root;

        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
                node->decresePrefix();
            }else{
                return;
            }
        }
        node->removeEnd();
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

    cout<< trie.countWordsEqual("ninja") << endl;
    cout<< trie.countWordsStartWith("nin") << endl;
    trie.erase("ninja");
    cout<< trie.countWordsEqual("ninja") << endl;
    cout<< trie.countWordsStartWith("nin") << endl;

}