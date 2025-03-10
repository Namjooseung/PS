#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int when[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int N,M;
	cin>>M>>N;
	queue <pair<int,int>> Q;
	bool check=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>board[i][j];
			when[i][j]=0;
			if(board[i][j]==1) Q.push({i,j});
			else if(board[i][j]==0) check=1;
		}
	}
	if(!check){
		cout<<'0';
		return 0;
	}
	int max=0;
	int check_num;
	while(!Q.empty()){
		auto cur=Q.front(); Q.pop();
		for(int i=0;i<4;i++){
			int nx=cur.X+dx[i];
			int ny=cur.Y+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			if(board[nx][ny]!=0) continue;
			board[nx][ny]=1;
			when[nx][ny]=when[cur.X][cur.Y]+1;
			if(when[nx][ny]>max) max=when[nx][ny];
			Q.push({nx,ny});
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(board[i][j]==0){
				cout<<"-1";
				return 0;
			}
		}
	}
	cout<<max;
}