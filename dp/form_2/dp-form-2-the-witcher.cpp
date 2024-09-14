/*
The Witcher II

DESCRIPTION
Gerald of Rivia also known as The Witcher wants to reach the end of the dungeon. The dungeon consists of 
n×m rooms laid out in a 2D grid. Gerald was initially positioned in the top-left room and must fight his way 
through, to the bottom-right room of the dungeon, where the exit is located.

Gerald has an initial health point represented by a positive integer. If at any point his health point 
drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so Gerald loses health upon 
entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase
Gerald's health (represented by positive integers).

To reach the exit as quickly as possible, Gerald decides to move only rightward or downward in each step.

Return Gerald's minimum initial health so that he can exit the dungeon.

Note that any room can contain threats or power-ups, even the first room Gerald enters and the bottom-right room where the exit is located.

INPUT FORMAT
First-line contains 
T - the number of test cases.
First-line of each test case contains 
2 integers n and m.
Each of the next 
n lines of each test case contains 
m integers, denoting the values of 
n×m dungeon's rooms.

Output Format
For each test case, output Gerald's minimum initial health so that he can exit the dungeon.


Sample Input 1
2
3 3
-2 -3 3
-5 -10 1
10 30 -5
1 1
1
Sample Output 1
7
1

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n,m;
vector<vector<int>> v;
vector<vector<int>> dp;


int rec(int i,int j){

    if((i>=n)||(j>=m)) return 1e9;
    if((i==n-1)&&(j==m-1)) return max(1,1-v[i][j]);

    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans = 1;
    ans=max(ans ,min(rec(i+1,j), rec(i,j+1))-v[i][j]);
    
    return dp[i][j] = ans;
}

void solve(){
    cin>>n>>m;
    v.resize(n, vector<int>(m));
    dp.resize(n, vector<int>(m, -1));


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    cout<<rec(0,0)<<endl;

    v.clear();
    dp.clear();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}