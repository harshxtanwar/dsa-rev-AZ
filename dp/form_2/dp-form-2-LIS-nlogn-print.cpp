#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<int> arr(n);
    vector<int> insertedAt(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }    

    vector<int> lis;
    for(int i=0; i<n; i++){
        if(lis.empty() || lis.back()<arr[i]){
            lis.push_back(arr[i]);
            insertedAt[i] = lis.size() - 1;

        }else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
            insertedAt[i] = it-lis.begin();
        }
    }
    cout<<"lis size: "<<lis.size()<<endl; // this will give the LIS max size

    cout<<"insertedAt: ";
    for(auto v: insertedAt) cout<<v<<' '; // just to print the index number in LIS matching the array elements
    cout<<endl;

    vector<int> final_lis;
    int curlen = lis.size() - 1;
    for(int i = n-1; i>=0; i--){
        if(insertedAt[i] == curlen){
            final_lis.push_back(arr[i]);
            curlen--;
        }
    }
    reverse(final_lis.begin(), final_lis.end());
    cout<<"Final LIS: ";
    for(auto v: final_lis) cout<<v<<' '; 
}









