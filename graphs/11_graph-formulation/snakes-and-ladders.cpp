/*
Snakes and Ladders

Description
Abhishek loves Snakes and Ladders game, he can always roll the die to whatever number he want between 
1 to 6. Help him to find the least number of dice rolls to reach the destination i.e the 
100th cell from the 1st cell.

Rules :-

The game is played with a cubic die of 6 faces numbered 1 to 6.
Starting from square 1, land on square 100 with the exact roll of the die. 
If moving the number rolled would place the player beyond square 100, no move is made.
If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.
If a player lands at the mouth of a snake, the player must go down the snake and come out through 
the tail. Snakes go down only.

Input Format
The first line contains the number of tests, t.
For each test case:
The first line contains n, the number of ladders.
Each of the next 
n lines contains two space-separated integers, the start, and end of a ladder.
The next line contains the integer m, the number of snakes.

Each of the next 
m lines contains two space-separated integers, the start, and end of a snake.

Output Format
For each of the t test cases, print the least number of rolls to move from start to finish on a separate line. 
If there is no solution, print −1.

Constraints

1≤t≤10
1≤n,m≤15
The board is always 10×10 with squares numbered 1 to 100.
Neither square 1 nor square 100 will be the starting point of a ladder or snake.
A square will have at most one endpoint from either a snake or a ladder.

Sample Input 1
2
3
32 62
42 68
12 98
7
95 13
97 25
93 37
79 27
75 19
49 47
67 17
4
8 52
6 80
26 42
2 72
9
51 19
39 11
37 29
81 3
59 5
79 23
53 7
43 33
77 21 
Sample Output 1
3
5

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ppi = pair<int,int>;

vector<vector<ppi>> graph;
vector<int> dist;
vector<int> visited;

void bfs(int st){
    deque<int> dq;
    dist[st] = 0;
    dq.push_front(st);

    while(!dq.empty()){
        int node = dq.front();
        dq.pop_front();

        for(auto v: graph[node]){
            int neigh = v.first;
            int weight = v.second;

            if(visited[neigh]) continue;
            visited[neigh] = 1;

            if(dist[neigh] > dist[node] + weight){
                dist[neigh] = dist[node] + weight;
                if(weight == 0){
                    dq.push_front(neigh);
                } else {
                    dq.push_back(neigh);
                }
            }
        }
    }
}

void solve(){
    graph.resize(101);
    dist.assign(101, 1e9);
    visited.assign(101, 0);

    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 6; j++){
            if(i + j <= 100) graph[i].push_back({i + j, 1});
        }
    }

    int l; cin >> l;
    for(int i = 0; i < l; i++){
        int a, b; cin >> a >> b;
        graph[a].clear();
        graph[a].push_back({b, 0});
    }

    int s; cin >> s;
    for(int i = 0; i < s; i++){
        int a, b; cin >> a >> b;
        graph[a].clear();
        graph[a].push_back({b, 0});
    }

    bfs(1);
    graph.clear();

    cout << (dist[100] == 1e9 ? -1 : dist[100]) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();
}
