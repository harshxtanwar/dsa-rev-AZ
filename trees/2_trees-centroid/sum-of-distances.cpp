/*
Sum of Distances

Description
You are given a tree consisting of n nodes. d(u, v) is the distance between nodes u and v, 
or number of edges in between the path connecting two nodes u and v. Your task is to find the 
sum of distances over all possible pairs of nodes.

Input Format
The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format
Print the sum as mentioned in the problem statement.

Constraints
1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
5
1 2
1 3
3 4
3 5
Sample Output 1
18

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n; 
vector<vector<int>> graph;
vector<int> sizeSubTree;

void dfs(int node, int par){
    sizeSubTree[node] = 1;
    for(auto v: graph[node]){
        if(v != par){
            dfs(v, node);
            sizeSubTree[node] += sizeSubTree[v];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    graph.resize(n+1);
    sizeSubTree.resize(n+1);
    for(int i=1; i<n; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    int ans = 0;
    for(auto v: sizeSubTree){
        ans += (v*(n-v));
    }
    cout<<ans;
}