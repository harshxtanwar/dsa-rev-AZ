/*
Graph Girth

Description
Given an undirected graph, your task is to determine its girth, i.e., the length of its shortest cycle.

Input Format
The first input line has two integers 
n and m: the number of nodes and edges. The nodes are numbered 
1,2,…,n.


After this, there are 
m lines describing the edges. Each line has two integers 
a and b:there is an edge between nodes a and b.


You may assume that there is at most one edge between every two nodes.

Output Format
Print one integer: the girth of the graph. If there are no cycles, print −1.

Constraints
1≤n≤2500
1≤m≤5000

Sample Input 1
5 6
1 2
1 3
2 4
2 5
3 4
4 5
Sample Output 1
3
Sample Input 2
10 9
5 6
4 5
8 9
9 10
1 2
6 7
3 4
2 3
7 8
Sample Output 2
-1


*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n,m; 
vector<vector<int>> graph;
vector<int> visited;
vector<int> par;

int ans = LLONG_MAX;

void dfs(int node, int parent){
    visited[node] = 1;
    par[node] = parent;

    for(auto v: graph[node]){
        if(!visited[v]){
            dfs(v,node);
        }else if(visited[v]==1 && v!=parent){
            vector<int> cycle;
            int temp = node;
            cycle.push_back(temp);
            while(temp!=v){
                cycle.push_back(temp);
                temp = par[temp];
            }
            // cycle.push_back(v);
            int cycle_len = cycle.size();
            ans = min(ans, cycle_len);
        }
    }
    visited[node]=2;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    graph.resize(n+1);
    visited.assign(n+1, 0);
    par.assign(n+1, -1);

    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        if(a!=b) graph[b].push_back(a);
    }   

    for(int i=1; i<n+1; i++){
        if(!visited[i]){
            dfs(i, -1);
        }
    }

    if (ans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

}