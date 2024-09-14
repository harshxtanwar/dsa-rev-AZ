/*
Make Palindrome

Description
Given a string s, find the minimum number of characters that need to be inserted into the string to make it a palindrome.

Input Format
First line contains 
T - the number of test cases.
First line of each test case contains the string s.

Output Format
For each test case, output the minimum number of characters that need to be inserted into the string to make it a palindrome.

Constraints
1≤T≤100
1≤∣s∣≤1000

Sample Input 1
4
algozenith
abba
goomgle
fft
Sample Output 1
9
0
3
1


*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

string s;
int n;
vector<vector<int>>dp;

int rec(int l, int r){

    if(l==r) return 1;

    if(s[l] == s[r] && l+1==r) return 2;

    if(dp[l][r] != -1) return dp[l][r];

    if(s[l] == s[r]) return 2 + rec(l+1, r-1);

    return dp[l][r] = max(rec(l+1, r), rec(l,r-1));
}
void solve(){
    cin>>s;
    n = s.size();
    dp.assign(n, vector<int>(n, -1));
    int lps = rec(0, n-1);
    dp.clear();
    cout<< n-lps << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}