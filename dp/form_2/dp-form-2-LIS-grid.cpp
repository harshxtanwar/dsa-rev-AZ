#include<bits/stdc++.h>
using namespace std;

int n,m; 
vector<vector<int>> v; 
vector<int> dp; 

int rec(int row, int column){
    // prunning
    if(row<0 || column<0) return -1e9;
    
    // base case 
    if(row==0 && column==0) return v[0][0];
    
    // cache values
    if(dp[row][column] != -1) return dp[row][column];   

    //compute
    int ans = max(
        rec(row-1, column) + v[row][column], 
        rec(row, column - 1) + v[row][column] 
    );

    return dp[row][column] = ans;


}

signed main(){
    cin>>n>>m;

    v.resize(1005, vector<int>(10005));
    dp.assign(10005, vector<int>(10005, -1));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    cout << rec(n-1, m-1) << endl;
}







