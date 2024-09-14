/*
Tree Diameter - I

Description
You are given a tree consisting of n nodes. The diameter of a tree is the maximum 
distance between two nodes. Your task is to determine the diameter of the tree.

Input Format
The first input line contains an integer n: the number of nodes. 
The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. 
Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format
Print the diameter of the tree.

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
3

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n;
vector<vector<int>> graph;
vector<int> dist;

void dfs(int node, int dis){
    dist[node] = dis;
    for(auto v: graph[node]){   
        if(dist[v] == -1){
            dfs(v, dis+1);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    graph.resize(n+1);
    dist.assign(n+1, -1);

    for(int i=1; i<n; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    int max1 = 1;
    for(int i=2; i<n+1; i++){
        if(dist[max1] < dist[i]){
            max1 = i;
        }
    }

    dist.assign(n+1, -1);
    dfs(max1, 0);

    int max2 = 1;
    for(int i=2; i<n+1; i++){
        if(dist[max2] < dist[i]){
            max2 = i;
        }
    }

    cout<<dist[max2]<<endl;

    
}
