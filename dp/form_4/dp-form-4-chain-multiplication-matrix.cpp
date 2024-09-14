#include<bits/stdc++.h>
using namespace std;

int n; 
vector<int> x, y; // storing the dimensions of the matrices
vector<vector<int>> dp; // LR DP 


int rec(int l, int r){
    if(l>=r) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    int ans = 1e9;
    for(int mid = l; mid<r; mid++){
        ans = min(
            ans,
            rec(l,mid) + rec(mid+1,r) + x[l]*y[mid]*y[r] 
        );
    }

    return dp[l][r] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    x.resize(n+1); 
    y.resize(n+1);
    dp.assign(n+1, vector<int>(n+1, -1));

    for(int i=1; i<=n; i++){
        cin>>x[i]>>y[i];
    }

    cout<<rec(1,n)<<endl;
}