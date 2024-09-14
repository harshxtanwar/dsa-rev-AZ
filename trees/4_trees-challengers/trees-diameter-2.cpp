/*
Trees Challengers 2

Description
You are given a tree consisting of n nodes. The diameter of a tree is the maximum 
distance between two nodes. Your task is to count the number of different diameters of the tree.

Input Format
The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format
Print the count of diameters of the tree.

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
2
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define nline '\n'
vector<vector<int>>g;
vector<int>dist;
vector<int>parent;
void dfs(int node,int par,int depth){
    parent[node] = par;
    dist[node] = depth;
    for(auto nbrs:g[node]){
        if(nbrs==par)continue;
        dfs(nbrs,node,depth+1);
    }
}
int countLeaf(int node,int par,int depth){
    if(depth==0){
        return 1;
    }
    int ans = 0;
    for(auto nbr:g[node]){
        if(nbr==par)continue;
        ans+=countLeaf(nbr,node,depth-1);
    }
    return ans;
}
void solve(){
    int n;cin>>n;
    g.resize(n+1);
    dist.assign(n+1,-1);
    parent.assign(n+1,-1);
    if(n==1){
        cout<<1<<nline;
        return;
    }
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    int u = 1;
    // farthest point from 1. End point of the diameter
    for(int i=2;i<=n;i++){
        if(dist[i]>dist[u])u = i;
    }
    dfs(u,0,0);
    int diameter = 0;
    for(int i=1;i<=n;i++){
        diameter = max(diameter,dist[i]);
    }
    int v = 1;
    for(int i=1;i<=n;i++){
        if(dist[i]==diameter)v=i;
    }
    int steps = diameter/2;
    for(int i=0;i<steps;i++)v = parent[v];
    int center = v;
    int ans = 0;
    if(diameter&1){ // diameter is odd
        int altcenter = parent[center];
        int cnt1 = countLeaf(altcenter,center,diameter/2);
        int cnt2 = countLeaf(center,altcenter,diameter/2);
        ans = cnt1*cnt2;
    }else{
        int root = center;
        int sum = 0;
        for(auto nbrs:g[center]){
            int cnt = countLeaf(nbrs,center,(diameter/2)-1);
            ans += cnt*sum;
            sum+=cnt;
        }
    }
    cout<<ans<<nline;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    solve();
	return 0;
}