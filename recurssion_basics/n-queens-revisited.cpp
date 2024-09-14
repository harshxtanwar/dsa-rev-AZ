/*

N-Queens Revisited

Description
An S-Queen is a chess piece that combines the power of a knight and a queen. 
Find the number of ways to place N S-Queens on N x N chessboard.

Input Format
The input contains only single integer N denoting the side of the chessboard. 

Output Format
Print the number of ways to place N S-Queens on the N x N chessboard.

Constraints
2 ≤ N ≤ 14

Sample Input 1
3
Sample Output 1
0
Sample Input 2
10
Sample Output 2
4

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n;
vector<int> queens;

int cnt = 0;

bool check(int row, int col){
    for(int i = 0; i< row; i++){
        int q_row = i;
        int q_col = queens[i];

        if (q_col == col || abs(q_col - col) == abs(q_row - row)) {
            return false;
        }

        int dr = abs(q_row - row);
        int dc = abs(q_col - col);
        if ((dr == 1 && dc == 2) || (dr == 2 && dc == 1) ) {
            return false;
        }
    }
    return true;
}

void rec(int level){
    // base case
    if(level == n) {
        cnt++;
        return;
    }
    for(int i = 0; i<n; i++){
        if(check(level, i)){
            queens[level] = i;
            rec(level + 1);
            queens[level] = -1;
        }
    }
}


void solve(){
    cin>>n;
    queens = vector<int>(n, -1);
    rec(0);

    cout<<cnt<<endl;    

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}