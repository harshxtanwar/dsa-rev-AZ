/*

Prime Cycles

Description
Find the number of Prime Cycles with the permutation of first N positive integers. The cycle is called a Prime Cycle if all neighbouring pairs sum up to be a prime. 

The two distinct prime cycles for N = 6 are:
1) 1, 4, 3, 2, 5, 6
2) 1, 6, 5, 2, 3, 4
The permutation of 3, 2, 5, 6, 1, 4 is considered the same as the first sequence.

Input Format
The input contains only a single integer N - denoting the number of positive integers.

Output Format
Print the number of Prime Cycles that are possible to form from first N positive numbers.

Constraints
2 ≤ N ≤ 19

Sample Input 1
2
Sample Output 1
1
Sample Input 2
4
Sample Output 2
2
Sample Input 3
6
Sample Output 3
2


*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


int n;
vector<int> v;
map<int,int> mp;
int ans = 0;

map<int, int> primeMap = {
    {2, 1}, {3, 1}, {4, 0}, {5, 1}, {6, 0}, {7, 1}, {8, 0}, {9, 0}, {10, 0},
    {11, 1}, {12, 0}, {13, 1}, {14, 0}, {15, 0}, {16, 0}, {17, 1}, {18, 0}, {19, 1},
    {20, 0}, {21, 0}, {22, 0}, {23, 1}, {24, 0}, {25, 0}, {26, 0}, {27, 0}, {28, 0},
    {29, 1}, {30, 0}, {31, 1}, {32, 0}, {33, 0}, {34, 0}, {35, 0}, {36, 0}, {37, 1},
    {38, 0}, {39, 0}, {40, 0}, {41, 1}, {42, 0}, {43, 1}, {44, 0}, {45, 0}, {46, 0},
    {47, 1}, {48, 0}, {49, 0}, {50, 0}, {51, 0}, {52, 0}, {53, 1}, {54, 0}, {55, 0},
    {56, 0}, {57, 0}, {58, 0}, {59, 1}, {60, 0}, {61, 1}, {62, 0}, {63, 0}, {64, 0},
    {65, 0}, {66, 0}, {67, 1}, {68, 0}, {69, 0}, {70, 0}, {71, 1}, {72, 0}, {73, 1},
    {74, 0}, {75, 0}, {76, 0}, {77, 0}, {78, 0}, {79, 1}, {80, 0}, {81, 0}, {82, 0},
    {83, 1}, {84, 0}, {85, 0}, {86, 0}, {87, 0}, {88, 0}, {89, 1}, {90, 0}, {91, 0},
    {92, 0}, {93, 0}, {94, 0}, {95, 0}, {96, 0}, {97, 1}, {98, 0}, {99, 0}, {100, 0}
};




bool check(int x){
    
    if(primeMap[x] == 1) return true;
    return false;
    
}
// level is the indice of vector
void rec(int level){
    if(v.size()==n) ans++;

    //base case
    if(level == n){
        return;
    }

    if(v[level-1]%2 == 0){
        for(int i = 1; i<n+1; i+=2){
            if(mp[i] && check(i + v[level-1])){
                v.push_back(i);
                mp[i]--;
                rec(level+1);
                mp[i]++;
                v.pop_back();
            }
        }
    }else{
        for(int i = 2; i<n+1; i+=2){
            if(mp[i] && check(i + v[level-1])){
                v.push_back(i);
                mp[i]--;
                rec(level+1);
                mp[i]++;
                v.pop_back();
            }
        }

    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;    
    for (int i = 0; i <= n; ++i) {
        mp[i] = 1;
    }
    
    v.push_back(1);
    mp[1]--;
    rec(1);
        
    cout<<ans<<endl;
}