/*
Colour Tree

Description
You have been given a tree with N nodes and N - 1 edges. You want to colour each node, 
such that no two adjacent nodes (directly connected by an edge) and no two nearly-adjacent 
nodes (both directly connected to a common node with edges) has the same colour. 
Your task is to find the minimum number of colours required to accomplished this. 

Input Format
The first line of input contains N. Each of the remaining N−1 lines describes an edge in 
terms of the two nodes it connects.

Output Format
Print the minimum number of colours require.

Constraints
1 ≤ N ≤ 105

Sample Input 1
4
1 2
4 3
2 3
Sample Output 1
3

*/

#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;
vector<int> visited;
bool canBeSeated = true;

void dfs(int node, int colour){
    visited[node] = colour;

    for(auto x: graph[node]){
        if(!visited[x]){
            dfs(x, 3-colour);
        }else if(visited[x] == visited[node]){
            canBeSeated = false;
            return;
        }

    }
}

signed main(){
    cin>>n;
    graph.resize(n+1);
    visited.assign(n+1, 0);

    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i<=n; i++){
        if(!visited[i] && canBeSeated){
            dfs(i, 1);
        }
    }

    if(canBeSeated) cout<<1<<endl;
    else cout<<0<<endl;

}