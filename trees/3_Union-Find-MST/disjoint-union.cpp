/*
Description
Write a program that manipulates a disjoint set S = S1, S2, ..., Sk.

First of all, the program should read an integer n, then make a disjoint set 
where each element consists of 0, 1, ..., n-1 respectively.

Next, the program should read an integer q and manipulate the set of q queries. 
There are two kinds of queries for different operations:

unite(x, y): unite sets that contain x and y, say Sx and Sy, into a new set.
same(x, y): determine whether x and y are in the same set.

Input Format
The first line contains two space-separated integers n and q, (1 ≤ n ≤ 104, 1 ≤ q ≤ 105).
Then, q queries are given in the form com x y, where com represents the type of queries. '0' denotes 
unite and '1' denotes same operation (x != y).

Output Format
For each same operation, print 1 if x and y are in the same set, otherwise 0, in a line.

Constraints
Sample Input 1
5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
Sample Output 1
0
0
1
1
1
0
1
1

*/

#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'

int n, q;
vector<int> parent;
vector<int> rankk;

int ufind(int x){
    if(parent[x] == x) return x;
    else return parent[x] = ufind(parent[x]);
}

void merge(int x, int y){
    int parx = ufind(x); int pary = ufind(y);

    if(parx!=pary){
        if(rankk[parx] < rankk[pary]){
            rankk[pary] += rankk[parx];
            parent[parx] = pary;
        }else{
            rankk[parx] += rankk[pary];
            parent[pary] = parx;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    parent.resize(n+1);
    rankk.resize(n+1);
    
    for(int i = 0; i<=n; i++){
        parent[i] = i;
        rankk[i] = 1;
    }
    
    for(int i=0; i<q; i++){
        int ch, x, y;
        cin >> ch >> x >> y;
        if(ch == 0){
            merge(x, y);
        }else{
            int parxx = ufind(x), paryy = ufind(y);
            if(parxx == paryy) cout << "1" << endl;
            else cout << "0" << endl;
        }
    }

}
