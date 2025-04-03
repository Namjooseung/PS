#include <bits/stdc++.h>
using namespace std;

int N;
int board[102][102];
int visited[102][102]={0,};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void bfs(int x,int y,int d){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y]=1;
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(visited[nx][ny]==1 || board[nx][ny]<=d) continue;
            q.push(make_pair(nx,ny));
            visited[nx][ny]=1;
        }
    }
}

int SafeArea(int d){
    memset(visited,0,sizeof(visited));
    int area_num=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]>d&&visited[i][j]!=1){
                bfs(i,j,d);
                area_num++;
            }
        }
    }
    
    return area_num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin>>board[i][j];
    }

    int max_area=0;
    for(int i=0;i<102;i++){
        int now_area=SafeArea(i);
        if(now_area==0) break;
        if(max_area<now_area) max_area=now_area;
    }

    cout<<max_area;

    return 0;
}