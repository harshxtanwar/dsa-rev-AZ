#include<bits/stdc++.h>
using namespace std;
int n; 
vector<int> x, y; // storing the dimensions of the matrices
vector<vector<int>> dp; // LR DP 
vector<vector<int>> backtrack;

int rec(int l, int r){
    if(l>=r) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    int ans = 1e9;
    for(int mid = l; mid<r; mid++){
        if(rec(l,mid) + rec(mid+1,r) + x[l]*y[mid]*y[r]  < ans){
            ans = rec(l,mid) + rec(mid+1,r) + x[l]*y[mid]*y[r];
            backtrack[l][r] = mid;
        }
    }

    return dp[l][r] = ans;
}

int open_bracket[105]; int close_bracket[105];

void generate( int l, int r){
    if(l==r) return;

    open_bracket[l]++; close_bracket[r]++;

    int mid = backtrack[l][r];
    generate(l, mid);
    generate(mid+1, r);
}


signed main(){
    cin>>n;
    x.resize(n+1); 
    y.resize(n+1);
    dp.assign(n+1, vector<int>(n+1, -1));
    backtrack.resize(n+1, vector<int>(n+1));

    for(int i=1; i<=n; i++){
        cin>>x[i]>>y[i];
    }
    cout<<rec(1,n)<<endl;

    generate(1, n);
    for(int i=1; i<n+1; i++){
        for(int x=0; x<open_bracket[i]; x++){
            cout<<"(";
        }
        for(int x=0; x<close_bracket[i]; x++){
            cout<<")";
        }
    }
}