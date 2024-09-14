/*
Description
You are given an array of colored gemstones. In one second, you can remove exactly one continuous
substring of colored gemstones that is a palindrome. You have to find the minimum number of seconds 
needed to destroy all the gemstones.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array. 
The second line of each test case contains N space-separated integers.

Output Format
For each test case, print the minimum number of seconds needed to destroy all the gemstones.

Constraints
1≤ T ≤ 200
1≤ N ≤ 100
1≤ Ai ≤ N

Sample Input 1
3
4
1 3 3 1
3
2 4 3
11
1 3 2 3 2 4 3 3 4 3 1
Sample Output 1
1
3
2

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n;
vector<int> v;
vector<vector<int>> dp2;

int rec(int l , int r){
    if(l>r)return 0;

    if(dp2[l][r]!=-1)return dp2[l][r];

    int ans = rec(l+1, r)+1;
    
    if(l<n-1 && v[l]==v[l+1])ans = min(ans, rec(l+2, r)+1);

    for(int i =l+2;i<=r;i++){
        if(v[i]==v[l])ans = min(ans, rec(l+1, i-1) + rec(i+1, r));
    }

    return dp2[l][r] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        cin>>n;
        v.clear();
        v.resize(n);
        dp2.assign(n+5, vector<int>(n+5,-1));

        for(int i =0;i<n;i++){
            cin>>v[i];
        }

        cout<<rec(0, n-1)<<endl;

    }

    return 0;
}