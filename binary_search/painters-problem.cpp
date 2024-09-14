/*

Famous Painter Partition Problem

Description
We have to paint n boards of length {A1, A2…An}. There are k painters available and each takes 1 unit 
time to paint 1 unit of the board. The problem is to find the minimum time to get
this job done under the constraints that any painter will only paint continuous sections of boards.

Note:
2 painters cannot share a board to paint. A board cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. If a painter paints board 1 and 3 but not 2 is invalid.

Input Format
The first line contains a single integer T (1 ≤ T ≤ 100000) - the number of test cases.
The first line of each test case contains 2 space-separated integers 
N, K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 100000) - the number of boards and the number of painters.
The second line of each test case contains N space-separated integers (0 ≤ xi ≤ 10^9) - the length of the boards.
Sum of N across all test cases ≤ 10^6.

Output Format
For each test case print the minimum time required to complete the painting in a new line.

Constraints
Sample Input 1
5
5 2
1 2 3 4 5
5 3
2 5 7 2 5
5 1
1 2 3 4 5
5 5
1 2 3 4 5
5 4
1 7 2 3 5
Sample Output 1
9
7
15
5
7
*/


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


bool check(int var_time, int k, vector<int> v){
    
    int sum = 0;
    for(int i = 0; i<v.size(); i++){
        if(sum + v[i] <= var_time){
            sum+=v[i];
        }
        else{
            k--;
            sum = v[i];
        }
    }
    if(k>0) return true;
    else return false;

}

void solve(){
    int n; int k; cin>>n>>k;
    int low = 0; int high = 0;
    vector<int> v; 

    for(int i = 0; i<n; i++){
        int x; cin>>x;
        v.push_back(x);
        low = max(low, x);
        high += x;
    }

    int ans = -1;
    while(low<=high){
        int var_time = (low+high)/2;

        if(check(var_time, k, v)){
            ans = var_time;
            high = var_time - 1;
        }
        else{
            low = var_time + 1;
        }

    }

    cout<<ans<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); std::cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}