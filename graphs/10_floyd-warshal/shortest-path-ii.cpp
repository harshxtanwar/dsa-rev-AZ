/*
Shortest Path II

Description
There are n cities and m roads between them. Your task is to process q queries where you 
have to determine the length of the shortest route between two given cities.

Input Format
The first input line has three integers n, m and q: the number of cities, roads, and queries.
Then, there are m lines describing the roads. Each line has three integers a, b and c: 
there is a road between cities a and b whose length is c. All roads are two-way roads.
Finally, there are q lines describing the queries. Each line has two integers a and b: 
determine the length of the shortest route between cities a and b.

Output Format
Print the length of the shortest route for each query. If there is no route, print −1 instead.

Constraints
1 ≤ n ≤ 500
1 ≤ m ≤ n2
1 ≤ q ≤ 105
1 ≤ a, b ≤ n
1 ≤ c ≤ 109

Sample Input 1
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2
Sample Output 1
5
5
8
-1
3
Sample Input 2
2 2 1
1 2 1
1 2 2
1 2
Sample Output 2
1

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n,m,q;
vector<vector<int>> dist;

void solve(){
    cin>>n>>m>>q;
    dist.assign(n+1, vector<int>(n+1, 1e18));
    for(int i=1; i<n+1; i++){
        dist[i][i]=0;
    }

    for(int i=0; i<m; i++){
        int a,b,c; cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c); 
    }

    for(int k=1; k<n+1; k++){
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if (dist[i][k] < 1e18 && dist[k][j] < 1e18) {  // Check to prevent overflow
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(int i=0; i<q; i++){
        int a,b; cin>>a>>b;
        if(dist[a][b]==1e18) cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}