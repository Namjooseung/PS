#include <bits/stdc++.h>
using namespace std;
int N,K,L;
vector <pair<int,char>> Moving;
deque <pair<int,int>> Snake;
int board[102][102]={0,};
int SnakeSize=1;
int TotalTime=0;

void SnakeGame(){
    int MovingNum=0;
    int SnakeDir=2;

    while(1){
        if(TotalTime==Moving[MovingNum].first){
            if(Moving[MovingNum].second=='D'){
                SnakeDir++;
                if(SnakeDir==5) SnakeDir=1;
            }
            else{
                SnakeDir--;
                if(SnakeDir==0) SnakeDir=4;
            }
            MovingNum++;
        }

        TotalTime++;

        int nx,ny;
        if(SnakeDir==1){
            nx=Snake.front().first;
            ny=Snake.front().second-1;
            if(nx<=0 || nx>N || ny<=0 || ny>N) break;
            bool check=false;
            for(int i=0;i<SnakeSize;i++) if(Snake[i].first==nx && Snake[i].second==ny) check=true;
            if(check) break;
            if(board[nx][ny]==1){
                K--;
                SnakeSize++;
                board[nx][ny]=0;
            }
            Snake.push_front(make_pair(nx,ny));
            if(Snake.size()>SnakeSize) Snake.pop_back();
        }
        else if(SnakeDir==2){
            nx=Snake.front().first+1;
            ny=Snake.front().second;
            if(nx<=0 || nx>N || ny<=0 || ny>N) break;
            bool check=false;
            for(int i=0;i<SnakeSize;i++) if(Snake[i].first==nx && Snake[i].second==ny) check=true;
            if(check) break;
            if(board[nx][ny]==1){
                K--;
                SnakeSize++;
                board[nx][ny]=0;
            }
            Snake.push_front(make_pair(nx,ny));
            if(Snake.size()>SnakeSize) Snake.pop_back();
        }
        else if(SnakeDir==3){
            nx=Snake.front().first;
            ny=Snake.front().second+1;
            if(nx<=0 || nx>N || ny<=0 || ny>N) break;
            bool check=false;
            for(int i=0;i<SnakeSize;i++) if(Snake[i].first==nx && Snake[i].second==ny) check=true;
            if(check) break;
            if(board[nx][ny]==1){
                K--;
                SnakeSize++;
                board[nx][ny]=0;
            }
            Snake.push_front(make_pair(nx,ny));
            if(Snake.size()>SnakeSize) Snake.pop_back();
        }
        else if(SnakeDir==4){
            nx=Snake.front().first-1;
            ny=Snake.front().second;
            if(nx<=0 || nx>N || ny<=0 || ny>N) break;
            bool check=false;
            for(int i=0;i<SnakeSize;i++) if(Snake[i].first==nx && Snake[i].second==ny) check=true;
            if(check) break;
            if(board[nx][ny]==1){
                K--;
                SnakeSize++;
                board[nx][ny]=0;
            }
            Snake.push_front(make_pair(nx,ny));
            if(Snake.size()>SnakeSize) Snake.pop_back();
        }
    }
}


int main(){
    Snake.push_front(make_pair(1,1));

    cin>>N;
    cin>>K;

    for(int i=0;i<K;i++){
        int K_x,K_y;
        cin>>K_x>>K_y;
        board[K_y][K_x]=1;
    }

    cin>>L;

    for(int i=0;i<L;i++){
        int time;
        char dir;
        cin>>time>>dir;
        Moving.push_back(make_pair(time,dir));
    }

    SnakeGame();
    
    cout<<TotalTime;

    return 0;
}