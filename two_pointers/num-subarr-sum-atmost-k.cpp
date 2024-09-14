/*

Number of Subarray with sum at most K

Description
Given an array of N integers, find the number of subarrays with a sum less than equal to K.

Input Format
The first line contains T, the number of test cases (1<=T<=10).
The first line of each test case contains two space-separated integers N, K where 1<=N<=10^5, 0<=K<=10^9.
Next line contains N space-separated integers (0<=Ai<=1e4).

Output Format
For each test case print the number of subarrays with a sum less than K in a newline.

Sample Input 1
5
3 5
1 2 3
3 6
3 2 1
5 0
2 1 0 4 5
7 6
1 2 3 0 1 5 2
10 10
1 0 1 1 10 2 3 7 5 9
Sample Output 1
5
6
1
18
18

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);

    for(int i=0; i<n; i++) cin>>v[i];

    int count = 0;
    int sum = 0;
    int tail = 0;
    int head = -1;

    while(tail<n){

        while(head+1 < n && (sum + v[head+1]) <= k){
            head++;
            sum += v[head];
        }

        count += head - tail + 1;

        if(head<tail){
            tail++;
            head = tail-1;
        }else{
            sum-=v[tail];
            tail++;
        }
    }

    cout<<count<<endl;



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}