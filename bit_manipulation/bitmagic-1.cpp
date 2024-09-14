/*

Bit Magic I

Description
A state with n flags of ON or OFF can be represented by a sequence of bits where 0,1,...,n−1 -th flag
corresponds to 1 (ON) or 0 (OFF). The state can be managed by the corresponding decimal integer because 
the sequence of bits is a binary representation where each bit is 0 or 1.

Given a sequence of bits with 60 flags that represent a state, perform the following operations. 
Note that each flag of the bits is initialized by OFF.

test(i): Print 1 if ith flag is ON, otherwise 0.
set(i): Set ith flag to ON
clear(i): Set ith flag to OFF
flip(i): Inverse ith flag
all: Print 1 if all flags are ON, otherwise 0
any: Print 1 if at least one flag is ON, otherwise 0
none: Print 1 if all flags are OFF, otherwise 0
count: Print the number of ON flags
val: Print the decimal value of the state
Input Format
The input is given in the following format.

q
query1
query2
:
queryq

Each query queryj is given in the following format: either only t  or  t  i  , where t is the query type.
The first digit t = 1, 2, 3 ,...,8, 9 represents the operation 
test(i), set(i), clear(i), flip(i), all, any, none, count or val respectively.

Output Format
Print the result in a line for each test, all, any, none, count and val operation.

Constraints
1 ≤ q ≤ 200,000
0 ≤ i < 60

Sample Input 1
14
2 0
2 1
2 2
3 1
1 0
1 1
1 2
1 3
4 3
5
6
7
8
9
Sample Output 1
1
0
1
0
0
1
0
3
13


*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bitset<60> b;

void solve(){
    int x; cin>>x;
    if(x==1){
        int i; cin>>i;
        if(b[i]) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else if(x==2){
        int i; cin>>i;
        b.set(i);
    }
    else if(x==3){
        int i; cin>>i;
        b.set(i, 0);   
    }
    else if(x==4){
        int i; cin>>i;
        b.flip(i);
    }
    else if(x==5){
        if(b.all()) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else if(x==6){
        if(b.any()) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else if(x==7){
        if(!b.any()) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else if(x==8){
        cout<<b.count()<<endl;
    }
    else{
        cout<<b.to_ullong()<<endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}