#include <bits/stdc++.h>
using namespace std;

vector<int> G[1001];
int visited[1001];

void bfs(int u){
    cout<<u<<' ';
    queue<int> q;
    q.push(u);
    visited[u]=1;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(auto v : G[u]){
            if(visited[v]) continue;
            cout<<v<<' ';
            q.push(v);
            visited[v]=1;
        }
    }
}

void dfs(int u){
    cout<<u<<' ';
    stack<int> s;
    s.push(u);
    visited[u]=1;
    while(!s.empty()){
        u=s.top();
        bool flag=true;
        for(auto v : G[u]){
            if(visited[v]) continue;
            cout<<v<<' ';
            s.push(v);
            visited[v]=1;
            flag=false;
            break;
        }
        if(flag) s.pop();  
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,V;
    cin>>N>>M>>V;
    while(M--){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=N;i++) sort(G[i].begin(),G[i].end());

    dfs(V);
    cout<<'\n';
    memset(visited, 0, sizeof(visited));
    bfs(V);

    return 0;
}