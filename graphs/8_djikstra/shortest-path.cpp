/*
Shortest Path I

Description
There are n cities and m roads. The capital is located at 1. Your task is to determine 
the length of the shortest route from the capital to every city.

Input Format
The first input line has two integers n and m: the number of cities and road connections. 
The cities are numbered 1, 2, …, n, and city 1 is Capital.
After that, there are m lines describing the roads. Each line has three integers a, b and c: a road begins at city a, ends at city b, and its length is c. Each road is a one-way road.
You can assume that it is possible to travel from Capital to all other cities.

Output Format
Print n integers: the shortest route lengths from Capital to cities 1, 2, …, n.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n
1 ≤ c ≤ 109

Sample Input 1
3 4
1 2 6
1 3 2
3 2 3
1 3 4
Sample Output 1
0 5 2

*/


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n,m;
vector<vector<pair<int,int>>> graph;
vector<int> dist, visited;

void dijkstra(int sc_node){
    
    priority_queue<pair<int,int>> pq;
    pq.push({0, sc_node});
    dist[sc_node] = 0;

    while(!pq.empty()){
        pair<int,int> current = pq.top();
        pq.pop();

        if(!visited[current.second]){
            visited[current.second] = 1;

            for(auto v: graph[current.second]){
                int weight = v.second;
                int node = v.first;

                if(dist[node] > dist[current.second] + weight){
                    dist[node] = dist[current.second] + weight;
                    pq.push({-dist[node], node});
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
    dist.assign(n+1, 1e9);
    visited.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;

        graph[a].push_back({b,c});
    }

    dijkstra(1);

    for(int i=1; i<n+1; i++){
        cout<<dist[i]<<' ';
    }
}

