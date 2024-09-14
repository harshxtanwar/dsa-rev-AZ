/* QUESTION LINK : https://atcoder.jp/contests/dp/tasks/dp_c */

#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> input(100005, vector<int>(3)); 
int n; int dp[100005][3];

int rec(int level, int taken_element){

    if(level == n) return 0;
    if(dp[level][taken_element] != -1) return dp[level][taken_element];

    int ans = 0;

    if(taken_element==0){
        ans = max(ans, rec(level + 1, 1) + input[level][1]);
        ans = max(ans, rec(level + 1, 2) + input[level][2]);
    }else if(taken_element==1){
        ans = max(ans, rec(level + 1, 0) + input[level][0]);
        ans = max(ans, rec(level + 1, 2) + input[level][2]);
    } else if(taken_element==2){
        ans = max(ans, rec(level + 1, 1) + input[level][1]);
        ans = max(ans, rec(level + 1, 0) + input[level][0]);
    } else{
        ans = max(ans, rec(level + 1, 0) + input[level][0]);
        ans = max(ans, rec(level + 1, 1) + input[level][1]);
        ans = max(ans, rec(level + 1, 2) + input[level][2]);
    }
    dp[level][taken_element] = ans;
    return ans;

}    
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin>>n;

    for(int i = 0; i<n; i++ ){
        for(int j=0; j<3; j++){
            cin>>input[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout<<rec(0,3)<<endl;
}