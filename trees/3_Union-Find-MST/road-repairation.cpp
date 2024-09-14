/*
Description
There are n cities and m roads between them. Unfortunately, the condition of the roads 
is so poor that they cannot be used. Your task is to repair some of the roads so that there 
will be a decent route between any two cities.
For each road, you know its reparation cost, and you should find a solution where the 
total cost is as small as possible.

Input Format
The first input line has two integers n and m: the number of cities and roads. 
The cities are numbered 1, 2, …, n.
Then, there are m lines describing the roads. 
Each line has three integers a, b and c: there is a road between cities a and b, 
and its reparation cost is c. All roads are two-way roads.
Every road is between two different cities, and there is at most one road between two cities.

Output Format
Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n
1 ≤ c ≤ 109

Sample Input 1
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
Sample Output 1
14

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> par;
vector<int> rankk;
vector<pair<int,pair<int,int>>> weighted_edges;
int n,m;

int ufind(int x){
    if(par[x]==x) return x;
    else return par[x] = ufind(par[x]);
}

void merge(int x, int y){
    int rootx = ufind(x);
    int rooty = ufind(y);

    if(rootx != rooty){
        if(rankk[rootx] < rankk[rooty]){
            rankk[rooty] += rankk[rootx];
            rankk[rootx] = 0;
            par[rootx] = par[rooty];
        }else{
            rankk[rootx] += rankk[rooty];
            rankk[rooty] = 0;
            par[rooty] = par[rootx];
        }

    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    par.resize(n+1);
    rankk.resize(n+1);

    for(int i=0; i<n+1; i++){
        par[i] = i;
        rankk[i] = 1;
    }

    for(int i=0; i<m; i++){
        int a,b,c; cin>>a>>b>>c;
        weighted_edges.push_back({c,{a,b}});
    }

    sort(weighted_edges.begin(), weighted_edges.end());

    int cost = 0;
    int count = 0;

    for( auto v : weighted_edges ){
        int weight = v.first;
        int city1 = v.second.first;
        int city2 = v.second.second;

        if(ufind(city1) != ufind(city2)){
            merge(city1, city2);
            cost+= weight;
            count++;
        }
    }

    if(count!=n-1){
		cout<<"IMPOSSIBLE"<<endl;
	}else{
        cout<<cost<<endl;    
    }
	

}


