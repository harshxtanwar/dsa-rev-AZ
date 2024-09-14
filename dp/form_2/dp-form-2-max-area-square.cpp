/*

Maximum Area of Square


Description
Given a grid of size n*m with 0s and 1s, you need to find the area of the largest square containing only 1.

Input Format
The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers n, m - the size of the grid.

Each of the next n lines contains m space-separated integers, aij - the number at that cell.

Output Format
For each test case, print the maximum area.


Constraints
1 ≤ t ≤ 105
1 ≤ n, m ≤ 103
0 ≤ aij ≤ 1

It is guaranteed that the sum of n*m over all test cases does not exceed 107.

Sample Input
3
2 3
0 1 1
0 0 0
3 3
1 0 1
0 1 1
0 1 1
2 2
0 0
0 0
Sample Output
1
4
0

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> matrix ( n,vector<int>(m) );
    vector<vector<int>> dp ( n,vector<int>(m, 0) );    

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans * ans << endl;


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}