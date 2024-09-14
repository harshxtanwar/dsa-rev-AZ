/*

Four Values

Description
You are given an array of n integers, and your task is to find four 
values (at distinct positions) whose sum is x.

Input Format
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a1, a2, …,an: the array values.

Output Format
Print 'YES' if such four values exist, otherwise 'NO'.

Constraints
1 ≤ n ≤ 1000
1 ≤ x, ai ≤ 109

Sample Input 1
8 15
3 2 5 8 1 3 2 3
Sample Output 1
YES

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> generate(const vector<int>& v) {
    vector<int> subVals;
    int size = v.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            subVals.push_back(v[i] + v[j]);
        }
    }
    sort(subVals.begin(), subVals.end());
    return subVals;
}


void solve(){
    int n, x; cin>>n>>x;
    vector<int> v1, v2;

    if (n<4){
        cout<<"NO"<<endl;
        return;
    }

    for(int i = 0; i<n; i++){
        int y; cin>>y;
        if(i%2==0){
            v1.push_back(y);
        }
        else{
            v2.push_back(y);
        }
    }

    vector<int> sums_v1 = generate(v1);
    vector<int> sums_v2 = generate(v2);

    
    for(int i = 0; i<sums_v1.size(); i++){
        int low = 0;
        int high = sums_v2.size()-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(sums_v2[mid]+sums_v1[i]==x){
                cout<<"YES"<<endl;
                return;
            }

            if(sums_v2[mid]+sums_v1[i]<x){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }

    cout<<"NO"<<endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}