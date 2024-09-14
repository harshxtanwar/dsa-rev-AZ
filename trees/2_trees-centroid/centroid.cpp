/*
Description
Given a tree of n nodes, your task is to find a centroid, i.e., 
a node such that when it is appointed the root of the tree, each subtree has at most ⌊n/2⌋ nodes.

Input Format
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.

Then there are n−1 lines describing the edges. Each line contains two integers 
a and b: there is an edge between nodes a and b.

Output Format
Print one integer: a centroid node. If there are several possibilities, print the smallest one.

Constraints
1≤n≤2⋅10^5
1≤a,b≤n

Sample Input 1
5
1 2
2 3
3 4
3 5
Sample Output 1
3

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<vector<int>> graph;
vector<int> subTreeSize;
vector<int> centroids;
int n; 

void dfs(int node, int par){

    bool is_centroid = true;

    for(auto v: graph[node]){
        if(v != par){
            dfs(v, node);
            subTreeSize[node] += subTreeSize[v];
            if(subTreeSize[v] > n/2 ) is_centroid = false;
        }   
    }

    if(n - subTreeSize[node] > n/2) is_centroid = false;
    if(is_centroid) centroids.push_back(node);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    graph.resize(n+1);
    subTreeSize.assign(n+1, 1);

    for(int i=1; i<n; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    sort(centroids.begin(), centroids.end())

}