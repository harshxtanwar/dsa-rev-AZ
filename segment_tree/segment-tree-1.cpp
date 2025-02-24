#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> input; // has to be of size N
vector<int> tree; // has to be of size 4N

int query(int index, int l, int r, int lq, int rq ){
    if(l>rq||lq>r){
        return 0;
    }
    if(lq<=l && r<=rq){
        return tree[index];
    }
    int mid = (l+r)/2;
    return query(index*2, l, mid, lq, rq) + query(index*2+1, mid+1, r, lq, rq);
}

void update(int index, int l, int r, int pos, int val){
    if(pos<l || pos>r) return;
    if(l==r){
        tree[index] = val;
        input[l] = val;
        return;
    }
    int mid = (l+r)/2;
    update(index*2, l, mid, pos, val);
    update(index*2 + 1, mid+1, r, pos, val);

    tree[index] = tree[2*index] + tree[2*index + 1];

}

void build(int index, int l, int r){
    // base case: reaching leaf node
    if(l==r){
        tree[index] = input[l];
        return;
    }
    int mid = (l+r)/2;
    build(index*2, l, mid);
    build(index*2 + 1, mid+1, r);
    // known as the merge logic of segment tree
    tree[index] = tree[2*index] + tree[2*index + 1];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>q;
    input.resize(n);
    tree.resize(4*n);

    for(int i=0; i<n; i++){
        cin>>input[i];
    }

    build(1, 0, n-1); // 1 is root node

    while(q--){
        int choice; cin>>choice;
        if(choice==1){
            int x,v;
            cin>>x>>v;
            x--;
            update(1, 0, n-1, x, v);
        }else{
            int l, r;
            cin>>l>>r;
            l--; r--;
            cout<<query(1, 0, n-1, l, r)<<'\n';
        }
    }
}



