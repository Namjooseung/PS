#include <bits/stdc++.h>
using namespace std;

int N,M,R;
int cnt=1;
stack<int> S;
vector<int> vertex[100001];
int visited[100001]={0,};

void dfs(int R){
    visited[R]=cnt++;
    for(auto i : vertex[R]){
        if(visited[i]!=0) continue;
        dfs(i);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>R;

    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        vertex[u].push_back(v);
        vertex[v].push_back(u);
    }
    for(int i=1;i<=N;i++){
        if(vertex[i].empty()) continue;
        sort(vertex[i].begin(),vertex[i].end());
    }
    dfs(R);
    for(int i=1;i<=N;i++) cout<<visited[i]<<'\n';
    

    return 0;
}