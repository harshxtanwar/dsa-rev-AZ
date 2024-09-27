/*
Find the Number of Rooms

Description
You are given a map of a building, and your task is to count the number of its rooms. 
The size of the map is n × m squares, and each square is either floor or wall. 
You can walk left, right, up, and down through the floor squares.

Input Format
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either ‘.’ (floor) or '#' (wall).

Output Format
Print one integer: the number of rooms.

Constraints
1 ≤ n, m ≤ 1000

Sample Input 1
5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output 1
3

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n,m; 
vector<string> graph;

void dfs(int row, int col){
    
    if(row<0 || row>=n || col<0 || col>=m || graph[row][col] == '#' ) return;
    graph[row][col] = '#';

    dfs(row+1, col);
    dfs(row-1, col);
    dfs(row, col+1);
    dfs(row, col-1);

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    graph.resize(n);

    for(int i=0; i<n; i++){
        cin>>graph[i];
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j] != '#'){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt;
}
