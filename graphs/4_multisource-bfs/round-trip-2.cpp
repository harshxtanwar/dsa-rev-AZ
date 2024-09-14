/*
Description
Zenithland has n cities and m flight connections. Your task is to design a round trip that 
begins in a city, goes through one or more other cities, and finally returns to the starting city. 
Every intermediate city on the route has to be distinct.

Input Format
First line contains 
T - Number of test cases.
First input line of each test case has two integers 
n and m: the number of cities and flights. The cities are numbered 
1,2,…,n.
Then, for each test case, there are 
m lines describing the flights. Each line has two integers 
a and b.
there is a flight connection from city 
a to city b.
All connections are one-way flights from a city to another city.

Output Format
For each test case, Print "Yes" if such round trip exists, otherwise print "No" in a new line.

Constraints
1≤T≤10
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n

Sample Input 1
1
4 5
1 3
2 1
2 4
3 2
3 4
Sample Output 1
Yes
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n,m;
vector<vector<int>>graph;
vector<int> visited;
bool is_cycle = 0;

void dfs(int node){
    visited[node]=1;
    for(auto v: graph[node]){
        if(!visited[v]){
            dfs(v);
            if(is_cycle) return;
        }
        else if(visited[v]==1){
            is_cycle = 1; return;
        }
    }
    visited[node] = 2;
}

void solve(){
    cin>>n>>m;
    graph.resize(n+1);
    visited.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
    }

    for(int i=1; i<n+1; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    if(is_cycle) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    visited.clear();
    graph.clear();
    is_cycle=0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--){
        solve();
    }
}