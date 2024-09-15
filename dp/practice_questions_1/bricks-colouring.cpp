/*
Bricks Colouring

Description
You are given N bricks in a line and M different coloured buckets of paint. 
You have to find the number of ways you can colour the brick wall such that 
there are exactly K positions out of the N bricks such that it has a different 
colour from the brick wall on its immediate left. (except the first brick, since 
there is no left brick). Print it modulo 10^9+7.

Input Format
The first line of the input contains one integer T - the number of test cases. 
Then T test cases follow.
The first and only line of each test case contains three space-separated integers N, M, K.

Output Format
For each test case, print the number of ways you can colour the brick wall satisfying the given condition % 10^9+7.

Constraints
1≤ T ≤ 100
1≤ N, M ≤ 2000
0≤ K ≤ N-1
It is guaranteed that the sum of N*K over all test cases does not exceed 4*108.

Sample Input 1
3
3 2 2
2 2 1
3 5 0
Sample Output 1
2
2
5
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define mod 1000000007


int n,m,k;
vector<vector<int>> dp;

int rec(int level, int left){

    if(left<0) return 0;
    
    if(level==n){
        if(left==0) return 1;
        return 0;
    }

    if(dp[level][left]!=-1) return dp[level][left];

    int ans= rec(level+1,left)%mod+ ((m-1)*(rec(level+1,left-1)))%mod;

    return dp[level][left]=ans%mod;

}


void solve(){
    cin>>n>>m>>k;
    dp.assign(2001, vector<int>(2001, -1));
    int ans= (rec(1,k)*m)%mod;

    cout<<ans<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}
