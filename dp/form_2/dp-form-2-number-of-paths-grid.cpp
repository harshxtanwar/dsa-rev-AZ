/*
Number of Paths in Grid - 2

Description
Given a grid of size n*m, you need to find the total number of different paths from (1, 1) to (n, m).
You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1). The grid may have some blocked cells, '
represented by 1, and it is not allowed to move to a blocked cell. An empty cell is represented by 0. 
You are also given an integer k and you can convert at most k blocked cells into unblocked cells.

Input Format
The first line of the input contains one integer t - the number of test cases. Then t test cases follow.
The first line of each test case contains three space-separated integers n, m, k - the size of
the grid and the number of cells you can convert.
Each of the following n lines contains m space-separated integers, aij - the number at that cell.

Output Format
For each test case, print the number of paths modulo 10^9 + 7.

Constraints
1 ≤ t ≤ 105
1 ≤ n, m ≤ 200
0 ≤ k ≤ 400
0 ≤ aij ≤ 1
It is guaranteed that the sum of n*m*k over all test cases does not exceed 108.

Sample Input 1
3
3 3 2
0 1 1
1 1 0
1 0 0
3 3 1
0 1 1
1 1 0
1 0 0
2 3 0
1 0 0
0 1 0

Sample Output 1
6
0
0
*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
const int MOD = 1e9 + 7;  

vector<vector<int>> v;
vector<vector<vector<int>>> dp;
int n, m, k;

int rec(int i, int j, int k_left) {
    if (i >= n || j >= m) {
        return 0;
    }

    if (i == n-1 && j == m-1) {
        if (v[i][j] == 0 || k_left > 0) return 1;
        else return 0;
    }

    if (dp[i][j][k_left] != -1) return dp[i][j][k_left];

    int ans = 0;
    if (v[i][j] == 0) {
        ans = (rec(i + 1, j, k_left) + rec(i, j + 1, k_left)) % MOD;
    } else {
        if (k_left > 0) {
            ans = (rec(i + 1, j, k_left - 1) + rec(i, j + 1, k_left - 1)) % MOD;
        }
    }

    return dp[i][j][k_left] = ans;
}

void solve() {
    cin >> n >> m >> k;

    v.resize(n, vector<int>(m));
    dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    cout << rec(0, 0, k) << endl;

    v.clear();
    dp.clear();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
