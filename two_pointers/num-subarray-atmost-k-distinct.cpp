/*

Number of Subarray with at most K distinct

Description
Given an array of N integers, find the number of subarrays with at most K distinct elements.

Input Format
The first line contains T, the number of test cases (1<=T<=10).
The first line contains two space-separated integers N, K where 1<=N<=10^5, 0<=K<=10^5.
Next line contains N space-separated integers (0<=Ai<=1e6).

Output Format
For each test case print the number of subarrays with at most K distinct elements in a newline.

Sample Input 1
5
3 2
1 2 3
3 2
3 2 2
5 0
2 1 0 4 0
7 3
1 2 1 0 1 0 2
10 5
1 0 7 1 10 2 4 10 1 3
Sample Output 1
5
6
0
28
46

*/

#include<bits/stdc++.h> 
using namespace std;
#define int long long 
#define endl '\n'

void solve(){
    int n, k; cin>>n>>k;
    vector<int> v;

    for(int i = 0; i<n; i++){
        int x; cin>>x; 
        v.push_back(x);
    }

    int tail = 0;
    int head = -1;
    int count = 0;
    int ans = 0;

    map <int, int> mp;
    while(tail < n){
        while(head+1 < n && ((mp.size()<k) || (mp.size()==k && mp.count(v[head+1])))){
            head++;
            mp[v[head]]++;
        }

        ans += head - tail + 1;

        if(head>=tail){
            mp[v[tail]]--;
            if(mp[v[tail]]==0) mp.erase(v[tail]);
            tail ++;
        }
        else{
            tail++;
            head = tail - 1;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}