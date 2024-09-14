/*

Minimise Max Diff

Description
You are given N distinct points on the number line in a sorted array A. 
You can place at most K more points on the Line (Integer coordinates only). 
You have to make the maximum separation between any two consecutive points in the 
final configuration as minimum as possible. Output this minimal value.  

Note - You can place the points anywhere you like, but you cannot place 
more than one point at the same position on the line. 

Input Format
The first line contains an integer T, the number of test cases (1<=T<=10000).
The first line of each test case contains two space-separated integers N, K, 2<=N<=10^5, 0<=K<=10^9.
Next line contains N space-separated distinct integers (0<=Ai<=1e9).
Sum of N across all test cases <= 10^6.

Output Format
For each test case output the minimum maximum separation between any two consecutive points possible in a new line.

Sample Input 1
5
5 5
1 2 3 4 5
5 0
2 5 7 8 10
3 2
100 200 230
6 5
1 3 5 7 9 11
6 4
1 4 8 13 19 26
Sample Output 1
1
3
34
1
4
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


bool check( int mid, vector<int> diff, int k){


    int required_points = 0;

    for (int i = 0; i < diff.size(); i++) {
        if (diff[i] > mid) {
            required_points += (diff[i] - 1) / mid; 
        }
    }

    if (required_points <= k) {
        return true;
    } else {
        return false;
    }

}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> v;


    for(int i=0; i<n; i++){
        int x; cin>>x;
        v.push_back(x);
    }

    vector<int> diff;
    int low = 1;
    int high = 0;
    int ans = -1;

    for(int i=0; i<(n-1); i++){
        int difference = v[i+1]-v[i];
        high = max(high, difference);
        diff.push_back(difference);
    }

    while(low<=high){

        int mid = (low+high)/2;

        if(check(mid, diff, k)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
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