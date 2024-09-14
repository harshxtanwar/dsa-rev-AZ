// refer to notes for explaination

#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin>>arr[i];

    vector<int> lis;
    for(int i=0; i<n; i++){
        if(lis.empty() || lis.back() < arr[i]){
            lis.push_back(arr[i]);
        }else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
    }

    cout<<lis.size();
}