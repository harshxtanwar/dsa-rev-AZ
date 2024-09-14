/*

Bit Magic II

Description
Given an integer t - the number of test cases. For each test case, read an integer n and 
answer the following 6 queries in the given order in a new line -:

Output the 64 bit binary representation of number n.
Output the position of the most significant bit ( MSB ) or the leftmost set bit of n ( 0- indexed ). 
If n=0, output -1.
Output the position of the rightmost set bit of n ( 0- indexed ). If n=0, output -1.
Output 1 if n  is a power of 2 i.e n==2X , x > 0, else output 0.
Output the biggest power of 2, that is the divisor of n. i.e biggest 2K such that n%2K == 0, k ≥ 0. If n=0, output -1. 
Output the smallest power of 2, which is not smaller than n, i.e smallest 2K such that 2K ≥ n, k>0.
Input Format
First-line contains an integer t -  number of test cases.
Each next t lines contain an integer n.

Output Format
For each test case, answer the 6 queries in the given order in a new line.

Constraints
1 ≤ t ≤ 10^5
- 1018 ≤ n ≤ 10^18 

Sample Input 1
10
-3
-2
-1
0
1
2
3
4
5
6
Sample Output 1
1111111111111111111111111111111111111111111111111111111111111101
63
0
0
1
2
1111111111111111111111111111111111111111111111111111111111111110
63
1
0
2
2
1111111111111111111111111111111111111111111111111111111111111111
63
0
0
1
2
0000000000000000000000000000000000000000000000000000000000000000
-1
-1
0
-1
2
0000000000000000000000000000000000000000000000000000000000000001
0
0
0
1
2
0000000000000000000000000000000000000000000000000000000000000010
1
1
1
2
2
0000000000000000000000000000000000000000000000000000000000000011
1
0
0
1
4
0000000000000000000000000000000000000000000000000000000000000100
2
2
1
4
4
0000000000000000000000000000000000000000000000000000000000000101
2
0
0
1
8
0000000000000000000000000000000000000000000000000000000000000110
2
1
0
2
8

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


void solve(){
    int n; cin>>n;
    bitset<64> b(n);

    // printing bits
    cout<<b.to_string()<<endl;

    //MSB
    if (n == 0) cout<<-1<<endl;
    else if (n < 0) cout<<63<<endl;
    else cout<< (int)__lg(n)<<endl;

    //right most set bit
    if (n == 0) cout<<-1<<endl;
    else cout<< __builtin_ctzll(n)<<endl;

    // for power of 2, there can only be 1 set bit in the whole bitset
    if(b.count() == 1 && n>1) cout<<1<<endl;
    else cout<<0<<endl;


    if (n == 0) cout<<-1<<endl;
    else cout<< (1LL<<(__builtin_ctzll(n))) <<endl;

    if (n <= 1)cout<<2<<endl;
    else if (__builtin_popcountll(n)==1) cout<<n<<endl;
    else cout<<(1LL << (64 - (__builtin_clzll(n))))<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
}