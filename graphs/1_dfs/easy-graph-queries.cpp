/*
Description
You have given an undirected graph G with N nodes and M edges. You've to answer Q queries. 
Each query is either of the following two types:
1) X: Print the size of the connected components containing node X.
2) X Y: Print ‘YES’ (without quotes) if node X and Y belong to the same connected component, else print ‘NO’ (without quotes).

Input Format
The first line of input contains three space-separated integers N, M, and Q (1 ≤ N, M, Q ≤ 105).
Next M lines contain two space-separated integers u and v (1 ≤ u, v ≤ N).
Each of the next Q lines contains queries of one of the types as described in the statement.

Output Format
Print Q lines as the answer to the Q queries, each on a new line.

Sample Input 1
6 5 5
1 2
2 3
1 3
4 4
5 6
1 2
1 4
2 3 4
1 5
2 5 6
Sample Output 1
3
1
NO
2
YES

*/

#include <bits/stdc++.h>
using namespace std;

int n,m,q;
vector<vector<int>> graph;
vector<int> visited;
int component = 0;
map<int,int>mp;

void dfs(int node){
	visited[node] = component;
	mp[component]++;
	
	for(auto v:graph[node]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

signed main(){
	cin>>n>>m>>q;
	graph.resize(n+1);
	visited.assign(n+1, 0);
	
	for(int i=0; i<m; i++){
		int a,b; cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	
	for(int i=1; i<n+1; i++){
		if(!visited[i]){
			component++;
			dfs(i);
		}
	}
	
	for(int i=0; i<q; i++){
		int query; cin>>query;
		if (query == 1){
			int x; cin >> x;
			cout<<mp[visited[x]]<<endl;
		}
		else{
			int x, y; cin>>x>>y;
			if(visited[x] == visited[y]){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
}