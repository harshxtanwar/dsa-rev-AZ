/*

Minimum Penalty

Description
Given an array of N integers and an integer D. Consider all subarray with length D, 
the penalty of the subarray is the number of distinct elements present in the subarray. 
Find a subarray of length D with minimum penalty. Print the minimum penalty.

Input Format
The first line contains T, the number of test cases (1<=T<=10000).
The first line contains two space-separated integers N, D where 1<=N<=10^6, 1<=D<=N.
Next line contains N space-separated integers (0<=Ai<=1e6).
The Sum of N across all test cases ≤ 5*10^6.

Output Format
For each test case print the minimum penalty in a newline.

Sample Input 1
5
6 3
0 1 1 2 2 2
5 3
1 0 1 2 3
5 5
1 1 2 3 4
5 1
1 2 3 4 5
7 3
1 2 1 2 3 4 2
Sample Output 1
1
2
4
1
2
*/


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long

void solve(){
    int n, d;
    cin>>n>>d;
    vector<int> v(n);
    vector<int> count(1000000, 0);

    for(int i=0; i<n; i++) cin>>v[i];

    int tail = 0;
    int head = -1;
    int min_sum = 1e6;
    int distinct = 0;

    while(tail<n){
        
        while(head + 1 < n && head-tail+2 <= d ){
            head++;
            count[v[head]]++;
            if(count[v[head]]==1) distinct++;

            if(head-tail+1 == d){
                min_sum = min(min_sum, distinct);
            }
        }

        count[v[tail]]--;
        if(count[v[tail]] == 0) distinct--;
        tail++;
    }

    cout<<min_sum<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}