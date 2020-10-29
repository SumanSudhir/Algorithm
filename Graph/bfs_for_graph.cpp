#include<bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& edges, int start=1){
    unordered_set<int> visited;

    queue<int> q;
    q.push(start);
    visited.insert(start);

    while(!q.empty()){
        int c_node = q.front()-1;
        visited.insert(c_node);

        for(int node:edges[c_node]){
            if(visited.find(node) == visited.end()){
                visited.insert(node);
                q.push(node);
            }
        }

        q.pop();
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


    bfs(edges);
}
