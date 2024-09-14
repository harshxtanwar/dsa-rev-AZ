/* QUESTION LINK : https://atcoder.jp/contests/dp/tasks/dp_d */

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int n, knapsack;
vector<int> weights(105);
vector<int> value(105);
int dp[105][100005];


int rec(int level, int Wleft){
    // base case
    if(level == n) return 0;
    // cache check
    if(dp[level][Wleft] != -1){
        return dp[level][Wleft];
    }
    // transition
    int ans = rec(level + 1, Wleft);

    if(weights[level] <= Wleft){
        int ans2 = rec(level+1, Wleft - weights[level]);
        ans = max(ans , ans2 + value[level]);
    }

    dp[level][Wleft] = ans;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin>>n>>knapsack;

    for(int i=0; i<n ; i++){
        cin>>weights[i];
        cin>>value[i];
    }

    memset(dp, -1, sizeof(dp));
    cout<<rec(0, knapsack)<<endl;
    
}