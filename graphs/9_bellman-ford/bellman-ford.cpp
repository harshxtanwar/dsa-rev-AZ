/*
Description
You have given a graph G with n nodes and m edges. Each edge has an integer weight associated with. 
The weight of an edge may negative, positive or zero. If the graph contains a cycle with 
total weight > 0, print -1. Otherwise, find the weight of the highest weighted path from node 1 to n.

Input Format
The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
Then, there are m lines describing the edges. Each line has three integers a, b and x: the edge starts at node 
a, ends at node b, and weight of the edge is x. All edges are unidirectional edges.
You can assume that it is possible to get from node 1 to node n.

Output Format
Print the answer on a new line.

Constraints
1 ≤ 2500 ≤ n
1 ≤ 5000 ≤ m
1 ≤ a, b ≤ n
−109 ≤ x ≤ 109

Sample Input 1
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4
Sample Output 1
5
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, m;
vector<vector<int>> edges;
vector<int> distt;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        int a,b,c; cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    distt.assign(n+1, 1e18);
    distt[1] = 0;
    for(int i=0; i<n-1; i++){
        for(auto x: edges){
            int node = x[0];
            int nextNode = x[1];
            int weight = x[2];
            if(distt[nextNode] > distt[node] - weight){
                distt[nextNode] = distt[node] - weight;
            }
        }
    }

    bool negativeCycle = false;
    for(auto x: edges){
        int node = x[0];
        int nextNode = x[1];
        int weight = x[2];
        if(distt[nextNode] > distt[node] - weight){
            negativeCycle = true;
        }
    }

    if(negativeCycle) cout<<-1;
    else{
        cout<<-distt[n];
    }    

}
