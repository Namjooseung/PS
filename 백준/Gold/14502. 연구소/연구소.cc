#include <bits/stdc++.h>
using namespace std;
int N,M;
int board[10][10];
int visited[10][10];
int BlankArea=0;
int MaxSafeArea=0;
vector <pair<int,int>> Virus;
vector<pair<int,int>> Blank;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int BFS(){

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j]=0;
        }
    }

    queue <pair<int,int>> Q;
    for(auto i : Virus){
        Q.push(make_pair(i.first,i.second));
        visited[i.first][i.second]=1;
    }

    int VirusArea=0;

    while(!Q.empty()){
        auto cur=Q.front(); Q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(board[nx][ny]!=0 || visited[nx][ny]==1) continue;
            Q.push(make_pair(nx,ny));
            visited[nx][ny]=1;
            VirusArea++;
        }
    }

    int SafeArea=BlankArea-VirusArea;

    return SafeArea;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]==2) Virus.push_back(make_pair(i,j));
            if(board[i][j]==0){
                Blank.push_back(make_pair(i,j));
                BlankArea++;
            }
        }
    }

    vector <int> V;

    for(int i=0;i<Blank.size();i++){
        if(i<3) V.push_back(0);
        else V.push_back(1);
    }

    do{
        for(int i=0;i<V.size();i++){
            if(V[i]==0) board[Blank[i].first][Blank[i].second]=1;
        }
        
        int SafeArea=BFS();
        if(MaxSafeArea<SafeArea) MaxSafeArea=SafeArea;

        for(int i=0;i<V.size();i++){
            if(V[i]==0) board[Blank[i].first][Blank[i].second]=0;
        }       

    }while(next_permutation(V.begin(),V.end()));

    cout<<MaxSafeArea-3;
}