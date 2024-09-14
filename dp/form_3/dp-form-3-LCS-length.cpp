/* 

Description
Given two strings. The task is to find the length of the longest common substring.

Input Format
First-line contains 

T - the number of test cases. 
Each test case contains two strings s1 and s2 in a single line.

Output Format
For each test case, output the length of the longest common substring of the two strings, in a new line.

Constraints
1≤T≤100
1≤|s1∣≤1000
1≤∣s2∣≤1000

s1 and s2 contains small letters only


SAMPLE INPUT:
3
abc abc
algozenith algo
algo zenith


SAMPLE OUTPUT:
3
4
0

*/

#include<bits/stdc++.h>
using namespace std;

string a,b;
int n,m;
vector<vector<int>> dp;

int rec(int i, int j){
    if( i >= n || j>= m) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    if (a[i] == b[j]) {
        ans = max(ans, 1 + rec(i + 1, j + 1));
    }
    
    return dp[i][j] = ans;
}

void solve(){
    cin >> a >> b;
    n = a.length();
    m = b.length();

    dp.assign(n, vector<int>(m, -1));  

    int ans = 0;

    // Iterate over all starting points
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, rec(i, j));
        }
    }

    cout << ans << endl;

    dp.clear();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t; while(t--) solve();
}