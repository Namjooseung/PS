#include <bits/stdc++.h>
using namespace std;

int N;
int board[102][102];
int visited[102][102];
int min_height=101;
int max_height=0;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int CheckSafeArea(int height){
    int safe_area_num=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]>height && visited[i][j]==0){
                safe_area_num++;
                queue <pair<int,int>> Q;
                Q.push(make_pair(i,j));
                visited[i][j]=1;
                while(!Q.empty()){
                    auto cur=Q.front(); Q.pop();
                    for(int i=0;i<4;i++){
                        int nx=cur.first+dx[i];
                        int ny=cur.second+dy[i];
                        if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                        if(board[nx][ny]<=height || visited[nx][ny]==1) continue;
                        visited[nx][ny]=1;
                        Q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) visited[i][j]=0;
    }

    return safe_area_num;
}

int main(){
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]>max_height) max_height=board[i][j];
            if(board[i][j]<min_height) min_height=board[i][j];
            visited[i][j]=0;
        }
    }

    int max_num=0;

    for(int i=min_height-1;i<=max_height;i++){
        int num=CheckSafeArea(i);
        if(max_num<num) max_num=num;
    }

    cout<<max_num;

    return 0;
}