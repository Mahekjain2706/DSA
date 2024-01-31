#include<bits/stdc++.h>
using namespace std;


// Shortest path in DIRECTED ACYCLIC GRAPH
// 1. topo sort
// 2. take the node out of stack and relax the edges.
// 3. declare distance edges initially as infinity.
// T.C = topo sort + stack loop O(n + m)   
// S.C = stack + dist + adj = O(n)+ O(n) + O(n*m) = O(n*m)
// Throw topological sort we start from the node for which distance is 0 (indegree=0) and find distance of each node 
// in this way we minimize the number of step and T.C O(N+M) which is less then any of the standard algorithm.
 void topoSort(int node,vector<pair<int,int>> adj[],int vis[],stack<int> &st){
        vis[node]=1;
        for(auto it:adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v,adj,vis,st);
            }
        }
        st.push(node);
}
 vector<int> shortestPath(int N,int M,vector<vector<int>>& edges){
    vector<pair<int,int>> adj[N];
    for(int i=0;i<M;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        
        adj[u].push_back({v,wt});
    }
    
    // step 1 Topo Sort
    // T.C O(N + M)
    int vis[N]={0};
    stack<int> st;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            topoSort(i,adj,vis,st);
        }
    }
    
    // step 2 do the distance thing
    // T.C O(N + M)
    vector<int> dist(N);
    for(int i=0;i<N;i++) dist[i] = INT_MAX;
    dist[0]=0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        for(auto it:adj[node]){
            int v = it.first;
            int w = it.second;
            
            if(dist[node] + w < dist[v]){
                dist[v] = dist[node] + w;
            }
        }
    }
    return dist;
}

// Shortest path in UNDIRECTED  GRAPH
// source given  , Unit distance
// BFS 
// T.C O(N+2E) S.C O(N+N+N)=O(N)
// we use queue as all node at unit distance so no need to 
vector<int> shortestDist(vector<int> adj[],int n,int source){
    int dist[n];
    for(int i=0;i<n;i++) dist[i]=INT_MAX;
    queue<int> q;
    q.push(source);
    dist[source]=0;
    while(!q.empty()){
       int sr = q.front();
       q.pop();
       for(auto it:adj[sr]){
            if(dist[sr] + 1 < dist[it]){
                dist[it] = dist[sr] + 1; 
                q.push(it);
            }
       }
    }
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        if(dist[i]!=INT_MAX){
            ans[i] = dist[i];
        }    
    }
    return ans;
}

// word lader 1
// string array of word is given and begin word and last word given we have to 
// change one letter and make word from one to another.minimum steps.
// T.C wordList*wordLength*26*logN(set)    S.C O(n)
int wordLader1(vector<string> &wordList,string startWord,string targetWord){
    queue<pair<string,int>> q;
    q.push({startWord,1});
    unordered_set<string> st(wordList.begin(),wordList.end());
    st.erase(startWord);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == targetWord) return steps;
        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                    break;
                }
            }
            word[i]=original;
        }
    }
    return 0;
}

// Word Lader 2
// return the array of string form during getting target string.
// T.C it is changes example to example
vector<vector<string>> findSequence(string beginWord,string targetWord,vector<string> &wordList){
    unordered_set<string> st(wordList.begin(),wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedLevel;
    usedLevel.push_back(beginWord);
    int level=0;
    vector<vector<string>> ans;
    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        // erase all words that has been
        // used in the previous levels to transform
        if(vec.size()>level) {
            level++;
            for(auto it:usedLevel){
            st.erase(it);
            }
            usedLevel.clear();
        }
        
        string word = vec.back();
        if(word == targetWord){
            // the first sequence where we reached end
            if(ans.size()==0){
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }
        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(st.count(word) > 0){
                    vec.push_back(word);
                    q.push(vec);
                    // mark visit on tha level
                    usedLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}
// OR 
// Optmized Solution
// CP way of solving video
// step 1 follow Word Ladder 1 and find the min steps and store the steps for every string.
// step 2 backtrack in the mao from end to begin to get the answer
unordered_map<string,int> mpp;
vector<vector<string>> ans;
string b;
void dfsCall(string word,vector<string> &seq){
    if(word == b){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    int steps = mpp[word];
    for(int i=0;i<word.size();i++){
        char original = word[i];
        for(char ch='a';ch<='z';ch++){
            word[i]=ch;
            if(mpp.find(word)!=mpp.end() && mpp[word]+1 == steps){
                seq.push_back(word);
                dfsCall(word,seq);
                seq.pop_back();
            }
        }
        word[i] = original;
    }

}
vector<vector<string>> findLadders(string beginWord,string endWord,vector<string> &wordList){
    b = beginWord;
    unordered_set<string> st(wordList.begin(),wordList.end());
    queue<string> q;
    q.push(beginWord);
    st.erase(beginWord);
    mpp[beginWord]=1;
    int sz = beginWord.size();
    while(!q.empty()){
        string word = q.front();
        int steps = mpp[word];
        q.pop();
        if(word==endWord) break;
        for(int i=0;i<sz;i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(st.count(word)>0){
                    q.push(word);
                    st.erase(word);
                    mpp[word] = steps + 1;
                }
            }
            word[i] = original;
        }
    }
    if(mpp.find(endWord)!=mpp.end()){
        vector<string> seq;
        seq.push_back(endWord);
        dfsCall(endWord,seq);
    }

    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    // Directed Weighted Graph
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    return 0;
}
