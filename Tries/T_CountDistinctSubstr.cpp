#include<bits/stdc++.h>
using namespace std;

// given string you have to find the number of distinct substring you can form from that string....
class Node{
    public:

    Node* links[26];

    bool containKeys(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word,int &cnt){
        Node* node = root;
        
        for(int i=0;i<word.size();i++){
            if(!node->containKeys(word[i])){
                cnt++;
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
    }
};

int countDistinctSubstring(string &s){
    Trie trie;
    int cnt = 0;
    for(int i=0;i<s.length();i++){
        string word = s.substr(i,s.length()-i+1);
        trie.insert(word,cnt);
    }
    return cnt+1;
}
int main(){
    string s;
    cin>>s;
    cout<< countDistinctSubstring(s) << endl;

    return 0;
}