/*
Center of Tree
Description
You are given a tree consisting of n nodes. Find the center of a tree. If there exist multiple centers, print -1.

Input Format
The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format
Print the center of a tree. If there exist multiple centers, print -1.

Constraints
1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
3
1 2
1 3
Sample Output 1
1

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> par;
vector<int> dep;

void dfs(int node, int parent, int depth){
    par[node] = parent;
    dep[node] = depth;

    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    g.resize(n+1);
    par.assign(n+1,0);
    dep.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,0);
    int max_child = 1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[max_child]){
            max_child = i;
        }
    }
    dfs(max_child,0,0);
    max_child = 1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[max_child]){
            max_child = i;
        }
    }

    int diameter = dep[max_child];
    int ans = max_child;

    if(diameter%2){
        cout<<-1<<"\n";
    }
    else{
        for(int i=0;i<(diameter/2);i++){
            ans = par[ans];
        }
        cout<<ans<<"\n";
    }
    return 0;
}