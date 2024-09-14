/*
Description
Given an array having n elements, the cost to move from ith element to its adjacent element ( if exist ) 
at i+1 and i−1 is b, and the cost to move to other same valued index is a. Find min cost to reach every 
index from a given source index of the array.

Input Format
First-line contains 
n - size of the array and costs 
a and b.
Second line contains 
n elements of the array.
The third line contains a source index src.

Output Format
In a single line, print the min-cost to reach every index from a given source index src.

Constraints
1≤n≤2×10 
1≤a,b≤10^9
1≤arr[i]≤100
1≤src≤n

Sample Input 1
10 1 2                                
1 2 1 1 2 3 2 3 2 1                                  
1
Sample Output 1
0 2 1 1 3 5 3 5 3 1 
Sample Input 2
1 1 2                                
7                                  
1
Sample Output 2
0


*/

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define F first
#define S second
using ii=pair<int,int>;

int n,a,b;
int sc;
vector<int> num;
map<int,vector<int>> mp;
vector<vector<ii>> gp;
int dis[400400];
bool vis[400400];

void dks(int st){
    priority_queue<ii> pq;
    pq.push({0,st});
    dis[st]=0;
    while(!pq.empty()){
        int node=pq.top().S;
        pq.pop();
        if(vis[node])continue;
        vis[node]=1;
        for(auto v:gp[node]){
            if(dis[v.F]>dis[node]+v.S){
                dis[v.F]=dis[node]+v.S;
                pq.push({-dis[v.F],v.F});
            }

        }
        //move forward or backward
    }
}

void solve(){
    cin>>n>>a>>b;
    num.resize(n+1);
    mp.clear();
    gp.clear();
    for(int i=1;i<=n;i++){
        cin>>num[i];
        mp[num[i]].push_back(i);
    }
    cin>>sc;
    int n2=mp.size();
    for(int i=0;i<=n+n2;i++){
        dis[i]=1e18;
        vis[i]=0;
    }
    int node=1;
    gp.resize(n+n2+1);
    for(auto u:mp){
        for(auto v:u.S){
            gp[n+node].push_back({v,0});
            gp[v].push_back({n+node,a});
        }
        node++;
    }
    for(int i=1;i<n;i++){
        gp[i].push_back({i+1,b});
        gp[i+1].push_back({i,b});
    }
    dks(sc);
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    cout<<endl;

}

signed main(){
    solve();
}