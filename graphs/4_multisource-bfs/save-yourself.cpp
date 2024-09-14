/*
Save Yourself

Description
You and some monsters are in a matrix. When taking a step to some direction in the matrix, 
each monster may simultaneously take one as well. Your goal is to reach one of the boundary 
squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print the shortest length of the path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

Input Format
The first input line has two integers n and m: the height and width of the matrix.
After this, there are n lines of m characters describing the matrix. Each character is ‘.’ (floor), ‘#’ (wall), ‘A’ (start), or ‘M’ (monster). There is exactly one ‘A’ in the input.

Output Format
First, print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print the length of the shortest path that you'll follow.

Constraints
1 ≤ n, m ≤ 1000

Sample Input 1
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
Sample Output 1
YES
5
Sample Input 2
3 3
###
#A#
#M.
Sample Output 2
NO
Sample Input 3
1 3
##A
Sample Output 3
YES
0

*/

#include<bits/stdc++.h>
#define int long long
#define lli long long int
#define lld long long double
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<vector<int>> bfs(vector<string> &grid, vector<pair<int, int>> &pos){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    queue<pair<int, int>> q;
    for(auto p: pos){
        dist[p.first][p.second] = 0;
        q.push(p);
    }
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        int i = node.first, j = node.second;
        for(int x = 0; x < 4; x++){
            int ix = i + dx[x];
            int jx = j + dy[x];
            if(ix >= 0 && ix < n && jx >= 0 && jx < m && grid[ix][jx] != '#' && dist[ix][jx] > dist[i][j] + 1){
                dist[ix][jx] = dist[i][j] + 1;
                q.push({ix, jx});
            }
        }
    }
    return dist;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);

    for(int i = 0; i < n; i++) cin >> grid[i];
    vector<pair<int, int>> player_pos;
    vector<pair<int, int>> monster_pos; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A') player_pos.push_back({i, j});
            else if(grid[i][j] == 'M') monster_pos.push_back({i, j});
        }
    }

    vector<vector<int>> player_dist = bfs(grid, player_pos);
    vector<vector<int>> monster_dist = bfs(grid, monster_pos);

    int shortest_path = 1e9;
    for(int i = 0; i < n; i++){
        if(player_dist[i][0] < monster_dist[i][0]) shortest_path = min(shortest_path, player_dist[i][0]);
        if(player_dist[i][m-1] <  monster_dist[i][m-1]) shortest_path = min(shortest_path, player_dist[i][m-1]);
    }

    for(int j = 0; j < m; j++){
        if(player_dist[0][j] < monster_dist[0][j]) shortest_path = min(shortest_path, player_dist[0][j]);
        if(player_dist[n-1][j] <  monster_dist[n-1][j]) shortest_path = min(shortest_path, player_dist[n-1][j]);
    }

    if(shortest_path >= 1e9) cout << "NO\n";
    else cout << "YES\n" << shortest_path << "\n";

}

signed main(){
    ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

    // int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}