/*
Edge Reverse

Description
Given a directed graph with 
N vertices and M edges.

What is the minimum number of edges needed to reverse in order to have at least one path from vertex 
1 to vertex N, where the vertices are numbered from 1 to N ?
​
Input Format
The first line contains T - the number of test cases.
The first line of each test case contains two space-separated integers N
and M, denoting the number of vertices and the number of edges in the
graph respectively.
The ith line of the next M lines of each test case contains two space-
separated integers Xi and Yi, denoting that the ith edge connects
vertices from Xi to Yi
 

Sample Input 1
1
7 7
1 2 
3 2
3 4
7 4
6 2
5 6
7 5
Sample Output 1
2

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<vector<pair<int,int>>> graph;
vector<int>visited;

int bfs(int st, int fin){

    deque <int> q;
    q.push_front(st);
    visited[st]=0;

    while(!q.empty()){
        int curr = q.front();
        q.pop_front();

        for(auto v: graph[curr]){
            int node = v.first;
            int weight = v.second;

            if(visited[node] > visited[curr] + weight){
                visited[node] = visited[curr] + weight;
                if(weight==1) q.push_back(node);
                else q.push_front(node);
            }
        }
    }

    if (visited[fin] == 1e9) return -1;
	else return visited[fin];
}


void solve(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    visited.assign(n+1, 1e9);

    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        
        
        graph[a].push_back({b,0});
        graph[b].push_back({a,1});
        
    }

    cout << bfs(1, n)<<endl;
    graph.clear();
    visited.clear();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t; while(t--)
    solve();

}

