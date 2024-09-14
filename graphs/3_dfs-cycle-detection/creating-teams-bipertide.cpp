/*
Creating Teams

Description
There are n students in AlgoZenith Course and m friendships between them. Your task is 
to divide the students into two teams in such a way that no two students in a team are friends. 
You can freely choose the sizes of the teams. The size of each team should be positive.

Input Format
The first input line has two integers n and m: the number of students and friendships. The students are numbered 1, 2, …, n.
Then, there are m lines describing friendships. Each line has two integers a and b: students a and b are friends.
Every friendship is between two different students. You can assume that there is at most one friendship between any two students.

Output Format
Print ‘YES’ if it's possible to divide students in two teams, otherwise print ‘NO’.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
5 3
1 2
1 3
4 5
Sample Output 1
YES
Sample Input 2
4 3
1 2
2 3
1 3
Sample Output 2
NO

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n,m;
vector<vector<int>> graph;
vector<int> visited;
bool canBeSeated = true;

void dfs(int node, int colour){
    visited[node] = colour;
    for(auto v: graph[node]){
        if(!visited[v]){
            dfs(v, 3-colour);
        }else if( visited[node] == visited[v]){
            canBeSeated = false;
            return;
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;

    graph.resize(n+1);
    visited.assign(n+1, 0);
    
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<n+1; i++){
        if(!visited[i]){
            dfs(i, 1);
        }
    }

    if(canBeSeated) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

