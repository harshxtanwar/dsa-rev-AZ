/*
Bitonic Array

Description
Bitonic array - A bitonic sequence is a sequence with A[1]<A[2]<A[3]....A[k]>A[k+1]>A[k+2]....>A[N] for some 1<=K≤N. 

Input Format
The first line contains T, the number of test cases (1<=T<=10000).
The first line contains two space separated-integer N, Q where 1<=N<=10^5, 1<=Q<=10^6.
The second line contains N space-separated integers A1,A2....AN where -1e9<=Ai<=1e9.
Next Q lines contains an integer K, -1e9<=K<=1e9.
Sum of N, Q across all test case ≤10^6

Output Format
For each test case print the positions of K in A in sorted order in a new line.
Positions are 1-indexed.

Sample Input 1
1
6 4
1 2 5 3 2 1
1
2
5
3
Sample Output 1
1 6
2 5
3
4

*/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x; v.push_back(x);
    }
    int low = 0; int high = n-1; int peak = 0; 
    while(low <= high){
        int mid = (low + high) / 2;
        if(v[mid] > v[mid - 1]){
            peak = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    while(q--){
        int k;
        int lo, hi;
        cin >> k;

        vector<int> final;
        lo = 0;
        hi = peak - 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(v[mid] == k){
                final.push_back(mid + 1);
                break;
            } else if(v[mid] > k){
                hi = mid - 1;
            } else{
                lo = mid + 1;
            }
        }

        lo = peak;
        hi = n - 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(v[mid] == k){
                final.push_back(mid + 1);
                break;
            } else if(v[mid] > k){
                lo = mid + 1;
            } else{
                hi = mid - 1;
            }
        }

        for(auto val: final){
            cout << val << " ";
        }  
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}