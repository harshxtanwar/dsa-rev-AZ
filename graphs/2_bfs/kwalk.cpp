/*
KWALK

Description
You are given an N × N chessboard and a knight with starting position (Sx, Sy). 
You are given a final position (Fx, Fy). You have to find the minimum number of moves required to reach the final position.

Complete the function
int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)

Input Format
The first line contains a single integer T - the number of test cases.
The first line of each test case contains five integers N Sx Sy Fx Fy - the size of the board, initial position and final position.

Output Format
For every test case print the minimum number of moves required. If it is not possible print -1.

Constraints
1 ≤ T ≤ 20
1 ≤ N ≤ 1000
1 ≤ Sx, Sy, Fx, Fy ≤ N

Sample Input 1
3
6 4 5 1 1
6 3 3 6 6
6 6 1 1 6
Sample Output 1
3
2
4


*/


#include <bits/stdc++.h>
using namespace std;
int ans = 1e9;
int N, Sx, Sy, Fx, Fy;
// vector<vector<int>> graph;
vector<vector<int>> visited;
int depth = 0;
const vector<pair<int, int>> directions = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

int bfs(int Sx, int Sy){
    visited[Sx][Sy] == depth;
    queue<pair<int,int>> q;
    queue<int> depth_queue;
    depth_queue.push(0);
    q.push({Sx,Sy});

    while(!q.empty()){
        int next_sx = q.front().first;
        int next_sy = q.front().second;
        depth = depth_queue.front();
        q.pop();
        depth_queue.pop();

        if(next_sx == Fx && next_sy == Fy){
            return depth;
        }
        for (auto dir : directions) {
            int nx = next_sx + dir.first;
            int ny = next_sy + dir.second;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny]) {
                visited[nx][ny] = depth;
                q.push(make_pair(nx, ny));
                depth_queue.push(depth + 1);
            }
        }
    }

    return -1;
}

void solve(){
	cin>>N>>Sx>>Sy>>Fx>>Fy;
    visited.assign(1+N, vector<int>(1+N, 0));
    // visited.assign(N + 1, vector<int>(N + 1, 0));
    cout<<bfs(Sx, Sy)<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin>>t;
	while (t--) solve();
}


