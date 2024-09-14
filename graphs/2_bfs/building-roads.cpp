/*
Building Roads

Description
Zenithland has n cities and m roads between them. The goal is to construct new roads 
so that there is a route between any two cities. A road is bidirectional.
Your task is to find out the minimum number of roads required.

Input Format
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
 

Output Format
Print the number of minimum roads required.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
4 2
1 2
3 4
Sample Output 1
1

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// now using BFS ! 
vector<vector<int>> graph;
vector<int>visited; 
int cnt = 0;

void bfs(int sc_node_component){

    visited[sc_node_component]=1;
    queue<int>q;
    q.push(sc_node_component);

    while(!q.empty()){
        int node_next_layer = q.front();
        q.pop();
        for(auto v: graph[node_next_layer]){
            if(!visited[v]) { 
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,m; cin>>n>>m;

    graph.resize(n+1);
    visited.assign(n+1, 0);

    for(int i = 0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        if(a!=b) graph[b].push_back(a);
    }   

    for(int i=1; i<n+1; i++){
        if(!visited[i]){ 
            cnt++; 
            bfs(i); 
        } 
    }
    
    cout<<cnt-1<<endl;
}

