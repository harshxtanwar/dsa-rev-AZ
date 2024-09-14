#include<bits/stdc++.h>
using namespace std;
#define endl '\n'


void solve(){
    int n; string s;
    cin>>s;
    n = s.length();

    // DP of n+1 because we need extra 
    // blank string value ' ' in the starting 
    vector<int> dp( n+1, -1 );
    vector<int> prefix_sum(n+1);
    vector<int> last(26, -1);

    dp[0] = 1;
    prefix_sum[0] = 1;

    for( int i=1; i<=n; i++ ){
        dp[i] = prefix_sum[i-1];
        if( last[s[i-1] - 'a'] != -1 ){
            int index = last[s[i-1] - 'a'];
            dp[i] -= prefix_sum[index];
        }
        last[s[i-1] - 'a'] = i-1;
        prefix_sum[i] = prefix_sum[i-1] + dp[i];
    }

    // -1 below to remove empty string ' '
    cout<<prefix_sum[n] - 1 <<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t; 
    while(t--) solve();
}







