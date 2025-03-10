#include <bits/stdc++.h>
using namespace std;

int N,M;
int board[502][502];
int Max=0;

int visited[502][502];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void NonPerfectTetromino(int x,int y,int depth,int sum){
    if(depth==4){
        if(Max<sum) Max=sum;
        return;
    }
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
        if(visited[nx][ny]==1) continue;
        NonPerfectTetromino(nx,ny,depth+1,sum+board[nx][ny]);
    }
    visited[x][y]=0;
    return;
}

void LastPiece(int x,int y){
    int num=0;
    int sum=board[x][y];
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
        num++;
        sum+=board[nx][ny];
    }
    if(num<=2) return;
    if(num==3) if(Max<sum) Max=sum;
    if(num==4){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                sum-=board[nx][ny];
                if(Max<sum) Max=sum;
                sum+=board[nx][ny];
            }
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) cin>>board[i][j];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            NonPerfectTetromino(i,j,1,board[i][j]);
            LastPiece(i,j);
        }
    }

    cout<<Max;
}