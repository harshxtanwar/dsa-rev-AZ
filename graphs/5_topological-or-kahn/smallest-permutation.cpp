/*
Smallest Permutation

Description
Among the sequences P that are permutations of (1, 2,... , N) and
satisfy the condition below, find the lexicographically smallest sequence.
• For each i = 1, ..., M, Ai appears earlier than Bi in P.
If there is no such P, print -1.

Input Format
Input is given from Standard Input in the following format:
N M
A1 B1
:
Ам Вм

Output Format
Print the answer

Constraints
2 ≤ N ≤ 2 × 10^5
1 ≤ M ≤ 2 × 10^5
1≤ Ai, Bi ≤ N
Ai != Bi
All values in input are integers.

Sample Input 1
4 3
2 1
3 4
2 4
Sample Output 1
2 1 3 4
Sample Input 2
2 3
1 2
1 2
2 1
Sample Output 2
-1

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n,m;
vector<vector<int>> graph;
vector<int> topo;
vector<int> inDegree;

void kahn(){
    priority_queue<int> pq;

    for(int i=1; i<n+1; i++){
        if( inDegree[i] == 0 ){
            pq.push(-i);
        }
    }

    while(!pq.empty()){
        int node = -pq.top();
        pq.pop();
        topo.push_back(node);

        for(auto v: graph[node]){
            inDegree[v]--;
            if(inDegree[v] == 0 ) pq.push(-v);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    graph.resize(n+1);
    inDegree.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    kahn();

    if(topo.size()==n){
        for(auto x: topo) cout<<x<<" ";
    }else{
        cout<<-1<<' ';
    }
    
    
}
