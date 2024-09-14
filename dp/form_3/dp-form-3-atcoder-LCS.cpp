/* https://atcoder.jp/contests/dp/tasks/dp_f */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
string a, b; int n, m;

int rec(int i, int j) {
    if (i >= n || j >= m) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    ans = max(ans, rec(i + 1, j));
    ans = max(ans, rec(i, j + 1));

    if (a[i] == b[j]) {
        ans = max(ans, 1 + rec(i + 1, j + 1));
    }

    return dp[i][j] = ans;
}

void constructLCS(int i, int j, string &lcs) {
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            lcs += a[i];
            i++;
            j++;
        }else if (i + 1 < n && dp[i][j] == dp[i + 1][j]){
            i++;
        }else {
            j++;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    n = a.length(); 
    m = b.length();

    dp.assign(n, vector<int>(m, -1));

    rec(0, 0);

    string lcs = "";
    constructLCS(0, 0, lcs);
    cout << lcs << endl;

    return 0;
}



