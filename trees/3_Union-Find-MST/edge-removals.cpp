/*
Description
You have given an undirected graph G with N nodes, indexed from 1 to N and M edges, indexed from 1 to M.
There are two types of operations:
1 X: Remove the edge numbered X.
2: Print the number of connected components in the graph.

Input Format
The first line of contains three space-separated numbers N, M, Q (1 ≤ N, M, Q ≤ 100000).
The next M lines contain 2 space-separated integers u and v which depicts an edge between 
nodes u and v (1 ≤ u, v ≤ N). ith line denotes the ith edge.

This is followed by Q lines, each describing an operation in the following format:
1 X: Remove the edge numbered X.
2: Print the number of connected components in the graph.

There are no self-loops or multiple edges in the graph.
Note: If there are multiple queries for removal of the same edge, then the last such query 
should be considered. Also, the index of the edges does not change after the removal of any of the edges between the nodes.

Output Format
The output should consist of the answer to each of the operations of the 2nd type printed on a new line.

Constraints
Sample Input 1
3 3 5
1 2
2 3
3 1
2
1 2
2
1 1
2
Sample Output 1
1
1
2

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

int n, m, q;
vector<int> rankk, parent;
int cc;

int findd(int x){
    if(parent[x] == x) return x;
    return parent[x] = findd(parent[x]);
}

void merge(int a, int b){
    int para = findd(a), parb = findd(b);
    if(para != parb){
        if(rankk[para] > rankk[parb]){
            rankk[para] += rankk[parb];
            rankk[parb] = 0;
            parent[parb] = para;
        }else{
            rankk[parb] += rankk[para];
            rankk[para] = 0;
            parent[para] = parb;
        }
        cc--;
    }
}

void solve(){
    cin >> n >> m >> q;
    cc = n;
    vector<pair<int, int>> ed;
    ed.push_back({-1, -1});
    for(int i = 1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        ed.push_back({a, b});
    }
    rankk.resize(n+1);
    parent.resize(n+1);
    for(int i = 0; i <= n; i++){
        rankk[i] = 1;
        parent[i] = i;
    }
    vector<pair<int, int>> qq;
    vector<int> marked(m+1, 0);
    for(int i = 1; i<=q; i++){
        int ch;
        cin >> ch;
        if(ch == 1){
            int x;
            cin >> x;
            qq.push_back({ch, x});
            marked[x] = 1;
        }else{
            qq.push_back({ch, -1});
        }
    }
    reverse(qq.begin(), qq.end());
    for(int i = 1; i<=m; i++){
        if(!marked[i]){
            merge(ed[i].first, ed[i].second);
        }
    }
    vector<int> ans;
    for(int i = 0; i<q; i++){
        if(qq[i].first == 1){
            int x = qq[i].second;
            int a = ed[x].first, b = ed[x].second;
            merge(a, b);
        }else{
            ans.push_back(cc);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto it: ans) cout << it << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}