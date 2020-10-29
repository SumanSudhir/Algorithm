#include<bits/stdc++.h>

using namespace std;


void dfs(vector<vector<int>> edges, int start=1){
    unordered_set<int> visited;
    stack<int> stk;

    stk.push(start);
    visited.insert(start);

    while(!stk.empty()){
        int c_node = stk.top()-1;
        stk.pop();

        for(int node: edges[c_node]){
            if(visited.find(node) == visited.end()){
                stk.push(node);
                visited.insert(node);
            }
        }

        cout << c_node+1 << " ";
    }
}

int main(){
    // Here edges[i] is eges from node i to egde[i]
    vector<vector<int>> edges;
    edges.push_back({2,3});
    edges.push_back({1,4,5});
    edges.push_back({1,5});
    edges.push_back({2,5,6});
    edges.push_back({2,3,4,6});
    edges.push_back({4,5});


    dfs(edges);
}
