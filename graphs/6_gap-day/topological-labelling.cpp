/*
Topological Labelling

Description
You are given a directed acyclic graph with n vertices and m edges.
There are no self-loops or multiple edges between any pair of vertices.
The graph can be disconnected.
You should assign labels to all vertices in such a way that:
• Labels form a valid permutation of length n - an integer sequence
such that each integer from 1 to n appears exactly once in it.
• If there exists an edge from vertex u to vertex u then labelv, should
be smaller than labelu..
• Permutation should be lexicographically smallest among all suitable.
Find such a sequence of labels to satisfy all the conditions.
​
 .
Permutation should be lexicographically smallest among all suitable.
Find such a sequence of labels to satisfy all the conditions.

Input Format
The first line contains two integer numbers 
n, m.


Next 
m lines contain two integer numbers 
v and u — edges of the graph. Edges are directed, the graph doesn't contain loops or multiple edges.

Output Format
Print n numbers — lexicographically smallest correct permutation of labels of vertices.

Sample Input 1
3 3
1 2
1 3
3 2
Sample Output 1
1 3 2 
Sample Input 2
4 5
3 1
4 1
2 3
3 4
2 4
Sample Output 2
4 1 2 3 
Sample Input 3
5 4
3 1
2 1
2 3
4 5
Sample Output 3
3 1 2 4 5 

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n,m;
vector<vector<int>> graph;
vector<int> indeg;
vector<int> order;

int label = 1;

void kahn(){
    int t = n;
    priority_queue<int> q;
    for(int i=1; i<n+1; i++){
        if(indeg[i]==0){
            q.push(i);
        }  
    }
    
    while(!q.empty()){
        int curr = q.top();
        q.pop();
        order[curr]= t--;
        for(auto v: graph[curr]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }

    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    graph.resize(n+1);
    indeg.assign(n+1,0);
    order.resize(n+1);

    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[b].push_back(a);
        indeg[a]++;
    }

    kahn();

    for(int i=1; i<n+1; i++){
        cout<<order[i]<<' ';
    }
}

