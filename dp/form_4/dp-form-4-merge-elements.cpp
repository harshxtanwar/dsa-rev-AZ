/*
Description
You are given N elements, in an array A. You can take any 2 consecutive elements a and b and merge them.
On merging you get a single element with value (a+b)%100 and this process costs you a*b. After merging 
you will place this element in place of those 2 elements.
 
If the sequence is [A1, A2, A3, A4] and you merge A2 and A3, you incur a cost of A2*A3 and the array becomes
[A1, (A2+A3)%100, A4].
 
Find the Minimum cost to merge all the elements into a single element.

Input Format
The first line contains a single element N. 1 <= N <= 500

The Second line contains N space separated integers, the Ai for the Array.  0 <= Ai < 100

Output Format
Output a single integer, the Minimum cost to Merge all the elements.

Sample Input 1
3
1 2 4 
Sample Output 1
14

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n;
vector<int> v;
vector<vector<int>> dp;

int rec(int l, int r){
    if(l==r) return 0;

    if(dp[l][r] != -1) return dp[l][r]; 

    int total = 0;
    for(int i=l; i<=r; i++){ 
        total += v[i];
    }

    int ans = 1e9;
    int sum = 0;
    for(int mid=l; mid<r; mid++){
        sum += v[mid];
        ans = min(
            ans, 
            rec(l,mid) + rec(mid+1, r) + ((sum)%100)*((total-sum)%100)
        );
    }

    return dp[l][r] = ans;         
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    v.resize(n);
    dp.resize(n, vector<int>(n, -1));

    for(int i=0; i<n; i++) cin>>v[i];

    cout<<rec(0, n-1);
}





