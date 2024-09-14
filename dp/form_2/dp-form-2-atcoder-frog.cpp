// https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int n,k;
vector<int> stones;
vector<int> dp;


int rec(int level){
    // base case: no cost to be on 1st stone ! 
    if(level ==0 ) return 0;
  
    if(dp[level] != -1) return dp[level];
  
    int ans = 1e9;

    // Consider jumps to `level` from the last `K` stones only
    for (int jump_distance = 1; jump_distance <= k; jump_distance++) {
        if (level - jump_distance >= 0) {
            ans = min(ans, rec(level - jump_distance) + abs(stones[level] - stones[level - jump_distance]));
        }
    }

    return dp[level] = ans;
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin>>n>>k;
  stones.resize(n);
  dp.assign(n, -1);

  for(int i=0; i<n; i++) cin>>stones[i];
  
  cout<<rec(n-1)<<endl;
}