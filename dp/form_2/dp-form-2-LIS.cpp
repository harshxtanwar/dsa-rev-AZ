#include<bits/stdc++.h>
using namespace std;

int n; 
vector<int> v; // intput array to perform LIS on
vector<int> dp; // dp to cache values

int rec(int level){
    // will return best LIS ending at level

    // prunning & base case
    if(level<0) return 0;
    
    // cache check 
    if(dp[level] != -1) return dp[level];

    // compute
    int ans = 1;
    for(int prev_taken = 0; prev_taken<level; prev_taken++){
        if(v[prev_taken]<v[level]){
            ans = max(ans, 1+rec(prev_taken));
        }
        
    }

    return dp[level] = ans;
}

signed main(){
    cin>>n;

    v.resize(10005);
    dp.assign(10005, -1);

    for(int i=0; i<n; i++) cin>>v[i];

    int best = 0;
    for(int i=0; i<n; i++){
        best = max(best,rec(i));
    }

    cout<<best<<endl;

}



