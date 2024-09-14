/*
Number & Sum of Digit

Description
You are given two integers N and S. Find the number of positive integers X 
less than equal to N, such that the difference between X and the sum of its digits 
(in decimal representation) is not less than S.

Input Format
The first line of input contains one integer T (1 ≤ T ≤ 104) — the number of test cases. 
Then T test cases follow.
The first line of each test case contains two space-separated integer N, S where 1<=N<=10^18, 0<=S<=10^18.

Output Format
For each test case print the number of positive integers X in a new line.

Sample Input 1
10
5 4
100 5
20 3
40 19
32 15
69 12
1000000000000000 0
1000000000000000000 10000000
9999999999999 9999999999882
13465751690089037 981448507916936
Sample Output 1
0
91
11
11
13
50
1000000000000000
999999999989999991
10
12484303182172038

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int sum(int mid){

    int ans = 0;

    for(int i = mid; i>0; i/=10){
        ans += i%10;
    }

    return ans;
}


void solve(){
    int n, s;
    cin>>n>>s;

    int low = 1; int high = n;
    int point = 0;

    while(low<=high){

        int mid = (low+high)/2;

        if((mid - sum(mid)) >= s){
            point = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }

    }

    if(point == 0){
        cout<<point<<endl;
    }
    else{
        cout<<n-point+1<<endl;
    }
    


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}