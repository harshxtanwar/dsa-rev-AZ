/*
LCS of 3 Strings

Description
Given 
3 strings s1, s2 and s3, the task is to find the length of the longest common sub-sequence in all three given strings.

Input Format
First-line contains 
T - the number of test cases.
Each test case contains 3 strings in a single line.

Output Format
For each test case, print the length of the longest common subsequence in all the 
3 given strings, in a new line.

Constraints
1≤T ≤ 100
1 ≤ |s1| ≤ 100
1 ≤ |s2| ≤ 100
1 ≤ |s3| ≤ 100

Sample Input 1
3
abc abc bbc
algozenith algo algorithm
algo zenith zen

Sample Output 1
2
4
0

*/

#include <bits/stdc++.h>
#include <chrono>  // For time measurement
using namespace std;
#define endl "\n"
// #define int long long

int n;
string s1, s2, s3;  
int s1_len, s2_len, s3_len;

vector<vector<vector<int>>> dp;

int rec( int l1, int l2, int l3 ){
    
    if( l1 == s1_len || l2 == s2_len || l3 == s3_len ){
        return 0;
    }

    if(dp[l1][l2][l3] != -1) return dp[l1][l2][l3] ;

    int ans = max(
        {
            rec(l1+1, l2, l3),
            rec(l1, l2+1, l3),
            rec(l1, l2, l3+1) 
        }
    );

    if(s1[l1] == s2[l2] && s2[l2] == s3[l3]){
        ans = max(ans, 1 + rec(l1 + 1, l2 + 1, l3 + 1));
    }

    return dp[l1][l2][l3] = ans;
}


void solve(){
    cin>>s1>>s2>>s3;

    s1_len = s1.length(); s2_len = s2.length(); s3_len = s3.length();

    dp.assign(s1_len, vector<vector<int>>(s2_len, vector<int>(s3_len, -1)));

    cout<<rec(0,0,0)<<endl;

    dp.clear();
}

signed main(){

    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t; while(t--) solve();
}
