#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr; 
vector<vector<int>>dp;

int rec(int l, int r) {
    
    if(l+1 == r) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    int ans = 1e9;

    for(int p=l+1; p<r; p++){
        ans = min(ans, arr[r]-arr[l] + rec(l,p) + rec(p,r));
    }

    return dp[l][r] = ans;

}

signed main() {
    cin>>n;
    arr.resize(n);
    dp.assign(n, vector<int>(n, -1));

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    arr[0]=0;

    cout<<rec(0,n)<<endl;
}









