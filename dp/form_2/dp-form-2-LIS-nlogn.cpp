#include <bits/stdc++.h>
using namespace std;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }    

    vector<int> lis;
    for(int i=0; i<n; i++){
        /* 
        LIS is empty because no element has gone through iteration
        and is last element of LIS is less than the current element of 
        out iteration, then we simply pushback the current element to the 
        LIS vector as the length of LIS will also increase with the new element 
        and the index value of the LIS vector represent the length of LIS
        */ 
        if(lis.empty() || lis.back()<arr[i]){
            lis.push_back(arr[i]);
        }else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout<<lis.size()<<endl; // this will give the LIS max size
}






