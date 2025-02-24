/*

SOLUTION IN V*(V+E)
BETTER SOLUTION POSTED BELOW 

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> visited;

int bfs( int sourceNode ){
    queue<pair<int,int>> q;
    int diameter = 0;
    q.push({sourceNode, diameter});
    

    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        diameter = max(diameter, curr.second);
        int node = curr.first;

        for(auto x: graph[node]){
            q.push({x, curr.second + 1});
        }
    }

    return diameter;
}

signed main(){
    cin>>n>>m;
    
    graph.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
    }

    int diameter = 0;
    for(int i=1; i<=n; i++){
        diameter = max(diameter, bfs(i));        
    }

    cout<<diameter<<endl;
    
}

*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<int> inDegree;
vector<int> dp;

void topo(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(inDegree[i]==0){
            q.push(i);
            dp[i] = 0;
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto x: graph[node]){
            inDegree[x]--;
            if(inDegree[x]==0){
                q.push(x);
            }
            dp[x] = max(dp[x], dp[node] + 1);
        }
    }
}

signed main(){
    cin>>n>>m;
    graph.resize(n+1);
    inDegree.assign(n+1, 0);
    dp.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    topo();

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }

    cout<<ans<<endl;
    
}