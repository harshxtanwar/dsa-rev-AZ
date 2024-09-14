/*

Queens On Chessboard

Description
Your task is to place eight queens on a chessboard so that no two queens are attacking 
each other. As an additional challenge, each square is either free or reserved, and you 
can only place queens on the free squares. However, the reserved squares do not prevent 
queens from attacking each other.

How many possible ways are there to place the queens?

Input Format
The input has eight lines, and each of them has eight characters. 
Each square is either free (.) or reserved (*).

Output Format
Print one integer: the number of ways you can place the queens.

Constraints
Sample Input 1
........
........
..*.....
........
........
.....**.
...*....
........
Sample Output 1
65

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> position(8, -1);
vector<string> free_space(8);
int cnt = 0;


bool check(int row, int column){
    if(free_space[row][column]=='*') return false;

    for(int i = 0; i<row; i++){
        int prev_col = position[i];

        if(column == prev_col) return false;
        if (abs(row - i) == abs(column - prev_col)) return false;
    }

    return true;
}

void rec(int level){
    if(level == 8){
        cnt++;
        return;
    }

    for(int i = 0; i<8; i++){
        if(check(level, i)){
            position[level] = i;
            rec(level+1);
            position[level] = -1;
        }
    }
    
}

void solve(){
    for(int i = 0; i<8; i++){
        string s; cin>>s; 
        free_space[i]=s;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    rec(0);
    cout<<cnt<<endl;
}