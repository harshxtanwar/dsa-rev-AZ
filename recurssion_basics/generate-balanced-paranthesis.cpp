/*

Generate Balanced Parenthesis - easy version

Description
You have given a positive even integer n. Your task is to print all 
balanced parenthesis of length n in lexicographic order (https://en.wikipedia.org/wiki/Lexicographic_order). 

Balanced parentheses mean that each opening symbol has a corresponding closing
symbol and the pairs of parentheses are properly nested.

Input Format
The only line of input contains a number n.

Output Format
Print all balanced parenthesis of length n in lexicographic order.

Constraints
2 ≤ n ≤ 24
It is guaranteed that n is even.

Sample Input 1
2
Sample Output 1
()
Sample Input 2
4
Sample Output 2
(())
()()
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<string> v;
int n; 
void rec(string s,int len,int p){
    //base
    if(len==n){
        if(p==0){
            v.push_back(s);
            return;
        }
        return;
    }
    //compute
    if(p<=n/2){
        rec(s+'(',len+1,p+1);
    }
    if(p>0){
        rec(s+')',len+1,p-1);
    }

    return;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    string s="";
    rec(s,0,0);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

}