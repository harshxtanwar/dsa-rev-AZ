/*
Connected Component Size

Description
You have a 2-D array of size N x M. Consider connected 0s (which share a common edge) as one 
single component and 1s as walls. Replace 0s with the size of the connected component but if 
the size of the component is one, then leave it with 0.

Input Format
The first line contains a single integer t, the number of test cases.
For each test case, the first line contains two integers N and M and then there are N lines 
containing M 0s and 1s, representing a N x M binary matrix.

Output Format
For each test case, print the final matrix after replacing all the 0s accordingly.

Constraints
1 ≤ Sum of (N x M) over all test cases ≤ 2 x 105
0 ≤ Ai ≤ 1

Sample Input 1
2
2 2
0 1
1 0
6 5
1 0 0 1 0
0 1 0 0 0
0 0 1 1 0
0 1 1 0 1
1 1 1 1 1
0 1 0 0 0
Sample Output 1
0 1 
1 0 
1 7 7 1 7
4 1 7 7 7
4 4 1 1 7
4 1 1 0 1
1 1 1 1 1
0 1 3 3 3

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long

vector<vector<int>> graph;
vector<vector<int>> visited;
vector<pair<int, int>> temporary;
int component = 0;
int sizee = 0;
int n, m;

void dfs(int i, int j) { 
   if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || graph[i][j] ) return;

   visited[i][j] = 1;
   temporary.push_back({i,j});
   sizee++;

   dfs(i + 1, j);
   dfs(i, j + 1);
   dfs(i - 1, j);
   dfs(i, j - 1);
}

void solve() {
    cin>>n>>m;
    graph.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m, 0));



    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char a; cin>>a;
            if(a == '1') graph[i][j]=1;
            else graph[i][j]=0;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && (graph[i][j]==0)){
                temporary.clear();
                component++;
                dfs(i,j);

                if(sizee==1){
                    for(auto v: temporary){
                        graph[v.first][v.second] = 0;
                    }
                }
                else if (sizee>1){
                    for(auto v: temporary){
                        graph[v.first][v.second] = temporary.size();
                    }
                }
                sizee = 0;
            }
        }
    }

    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
    
    graph.clear();
    visited.clear();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
