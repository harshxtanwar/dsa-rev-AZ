/*

Shortest Subarray

Description
Given an array of N integers, find the length of the smallest sub-array that 
contains all the distinct elements of the array.

Input Format
The first line contains T, the number of test cases (1<=T<=10).
The first line contains an integer N, 1<=N<=10^5.
Next line contains N space-separated integers (0<=Ai<=1e5).


Output Format
For each test case print length of the smallest sub-array that contains 
all the distinct elements of array in a newline.


Sample Input 1
6
5
1 1 3 2 3
5
1 2 3 4 5
6
1 2 2 3 3 4
6
1 2 1 3 2 4
5
1 1 1 1 1
1
1
Sample Output 1
3
5
6
4
1
1
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n; cin>>n;
    vector<int>v;
    set<int>st;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        v.push_back(x);
        st.insert(x);
    }
    map<int,int>freq;
    int k = st.size();
    int tail = 0; int head = -1; 
    int count = 0;
    int ans = 1e9;
    while(tail<n){
        while(head+1<n && count<k){
            head++;
            freq[v[head]]++;
            if(freq[v[head]]==1){
                count++;
            }
        }
        if(count==k){
            ans = min(ans, head - tail + 1);
        }
        if(head>=tail){
            if(freq[v[tail]]==1){
                count--;
            }
            freq[v[tail]]--;
            tail++;
        }
        else{
            tail++;
            head = tail -1;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}