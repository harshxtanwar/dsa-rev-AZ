/*

All Permutations

Description
Given an array of numbers, that might contain duplicates, print all 
possible unique permutations in lexicographically increasing order.

Input Format
The first line of input contains n - the size of the array.
The second line contains n space-separated integers denoting the 
elements of the array - a1, a2, …, an.

Output Format
Print all permutations in lexicographically increasing order. See 
the sample output for more clarity.

Constraints
1 ≤ n ≤ 8
0 ≤ ai ≤ 109

Sample Input 1
3
1 1 1
Sample Output 1
1 1 1
Sample Input 2
3
1 2 1
Sample Output 2
1 1 2 
1 2 1 
2 1 1 
Sample Input 3
3
2 1 3
Sample Output 3
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


map<int, int> mp;
int n;
vector<int> curr_perm;

void rec(int level){

    if(level == n){
        for(int i=0;i<n;i++){
            cout<<curr_perm[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(auto &it:mp){
        if(it.second != 0){
            curr_perm.push_back(it.first);
            it.second --;
            rec(level+1);
            it.second ++;
            curr_perm.pop_back();      
        }
    }
}

void solve(){
    cin>>n; 
    

    for(int i = 0; i<n; i++){
        int x; cin>>x; 
        mp[x]++;
    }

    rec(0);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}