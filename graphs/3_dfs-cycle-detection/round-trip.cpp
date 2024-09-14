/*
Round Trip

Description
Zenithland has n cities and m roads between them. Your task is to check for the existence 
of a round trip that begins in a city, goes through two or more other cities, and finally 
returns to the starting city. Every intermediate city on the route has to be distinct.

Input Format
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.

Output Format
Print ‘YES’ if such round trip exists, otherwise print ‘NO’.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
5 6
1 3
1 2
5 3
1 5
2 4
4 5
Sample Output 1
YES
Sample Input 2
4 3
1 2
1 3
3 4
Sample Output 2
NO
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int n, m;
vector<vector<int>> graph;
vector<int> visited;
vector<int> parent;
bool is_cycle = false;

bool dfs(int node, int par){
    visited[node] = 1;
    parent[node] = par;

    for(auto v: graph[node]){
        if(v == par) continue;

        if(!visited[v]){
            if (dfs(v, node)) return true;
        }else if(visited[v]==1){
            is_cycle = true;
            return true;
        }
    }

    visited[node] = 2;
    return false;
}

void solve() {
    cin >> n >> m;
    graph.resize(n + 1);
    visited.assign(n + 1, 0);
    parent.assign(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<n+1; i++){
        if(!visited[i] ){
            dfs(i, 0);
            if(is_cycle){
                cout<<"YES"<<endl;
                return;
            } 
        }
    }

    cout<<"NO"<<endl;

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
