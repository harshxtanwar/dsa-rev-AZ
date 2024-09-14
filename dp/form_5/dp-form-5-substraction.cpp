#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n;
vector<int> dp;

int rec(int chip_left){
    if(chip_left == 0) return 0;
    if(dp[chip_left] != -1) return dp[chip_left];
    int ans = 0;
    for(int m=0; (1<<m)<=chip_left; m++){
        if(rec(chip_left - (1<<m)) == 0){
            ans = 1;
        }
    }

    return dp[chip_left]=ans;
}
void solve(){
    cin>>n;
    if(rec(n) == 0) cout<<"Abhishek"<<endl;
    else cout<<"Vivek"<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    dp.assign(1000000, -1);
    int t; cin>>t; while(t--)
    solve();
}