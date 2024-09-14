/*

Longest Distinct Subarray AZ101

Description
You are given an array of N integers. Find the longest subarray with distinct characters.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array. 
The second line of each test case contains N space-separated integers.

Output Format
For each test case, print the longest subarray with distinct characters.

Constraints
1≤ T ≤ 10^5
1≤ N ≤ 10^5
1≤ Ai ≤ 10^9
It is guaranteed that the sum of N over all test cases does not exceed 105.

Sample Input 1
3
5
1 2 2 1 2
4
3 3 3 3
5
1 3 2 4 1
Sample Output 1
2
1
4
Sample Input 2
1
7                   
1 2 3 1 4 5 6
Sample Output 2
6

*/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int n; cin>>n;
    int a[n];


    for(int i=0; i<n; i++){
        int x; cin>>a[i];
    }

    int ans=0;
    int l=0;
    map<int,int>m;

    for(int i=0; i<n; i++){
        while(m[a[i]] == 1) {
            m[a[l]]--;
            l++;
        }
        m[a[i]]++;
        ans = max(ans, i-l+1);
        
    }
    cout<<ans<<endl;
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}