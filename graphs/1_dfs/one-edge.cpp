/*
One Edge

Description
You have given an undirected graph with n nodes, and m edges between them. 
The goal is to add exactly one edge between two nodes such that the total 
number of connected components in the graph decreases.
Your task is to find out the number of ways to add such edge.

Input Format
The first input line has two integers n and m: the number of nodes and edges. 
The nodes are numbered 1, 2, …, n.
After that, there are m lines describing the edges. Each line has two integers a and b: 
there is an edge between those nodes.
An edge always connects two different nodes, and there is at most one edge between any two nodes.

Output Format
Print the number of ways to add such edge, described in the statement.

Constraints
1 ≤ n ≤ 10^5
1 ≤ m ≤ 2 x 10^5
1 ≤ a, b ≤ n

Sample Input 1
5 4
1 2
2 3
1 3
4 5
Sample Output 1
6
Sample Input 2
4 3
1 2
2 3
3 4
Sample Output 2
0

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> visited;
vector<vector<int>> graph;
vector<int> cnt_nodes;
int cnt_for_index = 0;

void dfs(int node) {
    visited[node] = 1;
    cnt_nodes[cnt_for_index]++;

    for(auto v : graph[node]){  
        if(!visited[v]){
            dfs(v);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }  

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt_nodes.push_back(0);
            dfs(i);
            cnt_for_index++;
        }
    }
    
    int totalWays = 0;
    int num_of_nodes = 0;

    for (int i = 0; i < cnt_for_index; i++) {
        num_of_nodes += cnt_nodes[i];
    }

    for (int i = 0; i < cnt_for_index; i++) {
        totalWays += cnt_nodes[i] * (num_of_nodes - cnt_nodes[i]);
        num_of_nodes -= cnt_nodes[i];
    }
    
    cout << totalWays << endl;
    return 0;
}
