/*
Infected People

Description
Your city is having people infected with a virus. The city in which you live is represented
as a grid consisting of n rows and m columns. Cells containing 2 are the cells where the people 
infected with the virus are present and the cells having 1 are the cells having people not yet 
infected with the virus. There are certain empty cells which are represented by 0. The infected 
people in a unit time can infect all their adjacent cells, i.e, if they are present at cell [i, j] 
they can infect cells [i-1, j], [i+1, j], [i, j-1] and [i, j+1]. The virus cannot pass through empty cells. 
Your task is to print the minimum time in which all the people are infected with the virus. 
If the virus cannot infect everyone, print -1.

Input Format
The first line contains two integers n and m  — the number of rows and columns, respectively.
The following n lines contain m integers each, the j-th element in the i-th line is the number 
written in the j-th cell of the i-th row.

Output Format
Print the minimum time in which everyone can be infected or -1 if everyone cannot be infected.

Constraints
1 <= n <= 1000
1 <= m <= 1000

Sample Input 1
3 3
0 1 2
0 1 2
1 1 2
Sample Output 1
2
Sample Input 2
3 3
0 1 2
0 1 2
1 0 2
Sample Output 2
-1

*/

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> city;
vector<vector<int>> visited;
vector<vector<int>> dist;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool all_infect=true;
int maxi=0;

vector<pair<int,int>> neighbour(pair<int,int> node){
    vector<pair<int,int>> v;
    for(int i=0;i<4;i++){
        int x=node.first + dx[i];
        int y=node.second + dy[i];
        if(x>=0 && x<n && y>=0 && y<m){
            v.push_back({x,y});
        }
    }
    return v;
}

void bfs(vector<pair<int,int>> infected){
    queue<pair<int,int>> q;
    for(auto v:infected){
        visited[v.first][v.second]=1;
        dist[v.first][v.second]=0;
        q.push(v);
    }

    while(!q.empty()){
        pair<int,int> curr=q.front();
        q.pop();

        for(auto x:neighbour(curr)){
            if(!visited[x.first][x.second] && city[x.first][x.second]==1){
                visited[x.first][x.second]=1;
                dist[x.first][x.second]=dist[curr.first][curr.second]+1;
                q.push(x);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(city[i][j]==1 && !visited[i][j]) all_infect=false;
            if(city[i][j]==1 && visited[i][j])  maxi=max(maxi,dist[i][j]);
        }
    }
}

int main(){
    cin>>n>>m;
    city.resize(n,vector<int>(m,0));
    vector<pair<int,int>> infected;
    visited.resize(n,vector<int>(m,0));
    dist.resize(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x; cin>>x;
            city[i][j]=x;
            if(x==2){
                infected.push_back({i,j});
            }
        }
    }

    bfs(infected);

    if(all_infect) {
        cout<<maxi<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    
}