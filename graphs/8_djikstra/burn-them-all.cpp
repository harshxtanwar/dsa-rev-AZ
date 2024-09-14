/*
Burn them All

Description
You have given an undirected graph of N vertices and M edges. Edge weight d on edge 
between nodes u and v represents that u and v are connected by a thread of length d units. 
You set node A on to the fire. It takes to fire 1 unit of time to travel 1 unit of distance via threads.
Let T be the minimum time in which all the threads will be burned out. 

Your task is to find 10T. We can prove that 10T will always be an integer number.

See the sample test cases for more explanation.

Input Format
The first line of input contains N - the number of nodes in the graph.
The second line contains M - the number of edges in the graph.
Next M lines contain three integers u, v, d - there is a thread between node u and v of length d.
The last line of input contains A - the node on which we set fire.

It’s guaranteed that graph is connected.

Output Format
Print the value of 10T.

Constraints
1 ≤ N ≤ 2 x 105
1 ≤ M ≤ 2 x 105
1 ≤ u, v ≤ N
1 ≤ d ≤ 109

Sample Input 1
2
1
1 2 2
1
Sample Output 1
20
Sample Input 2
3
3
1 2 2
2 3 2
1 3 6
1
Sample Output 2
50
Sample Input 3
3
3
1 2 2
1 3 2
2 3 1
1
Sample Output 3
25

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n,m;
int st;
int ans = 0;
vector<vector<pair<int,int>>> graph;
vector<int> visited;
vector<int> dist;
vector<pair<pair<int,int>,int>>edges;


void dijkstra(){
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    dist[st] = 0;
    while(!pq.empty()){
        pair<int,int> curr = pq.top();
        pq.pop();

        if(!visited[curr.second]){
            visited[curr.second] = 1;

            for(auto v : graph[curr.second]){
                if(dist[v.first] > dist[curr.second]+ v.second ){
                    dist[v.first] = dist[curr.second]+ v.second;
                    
                    pq.push({-dist[v.first], v.first});                    
                }
                
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    graph.resize(n+1);
    visited.assign(n+1, 0);
    dist.assign(n+1, 1e18);

    for( int i=0; i<m; i++ ){
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
        edges.push_back({{a,b},c});

    }

    cin>>st;

   dijkstra();
    for(auto e:edges){
		int u=e.first.first;
		int v=e.first.second;
		int d=e.second;
		ans=max(ans,(dist[u]+dist[v]5+d)*);
	}
	cout<<ans<<"\n";
    
}




