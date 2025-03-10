#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[1002][1002];
int when[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int N,M;
	cin>>N>>M;
	queue<pair<int,int>> JH;
	queue<pair<int,int>> FIRE;
	for(int i=0;i<N;i++){
		string arr;
		cin>>arr;
		int n=0;
		for(auto j : arr){
			board[i][n]=j;
			if(j=='J'){
				JH.push({i,n});
				when[i][n]=1;
			}
			else if(j=='F') FIRE.push({i,n});
			n++;
		}
	}
	while(1){
		int n=FIRE.size();
		while(n--){
			auto CurFIRE=FIRE.front(); FIRE.pop();
			for(int i=0;i<4;i++){
				int nx=CurFIRE.X+dx[i];
				int ny=CurFIRE.Y+dy[i];
				if(nx<0||nx>=N||ny<0||ny>=M) continue;
				if(board[nx][ny]=='#'||board[nx][ny]=='F') continue;
				board[nx][ny]='F';
				FIRE.push({nx,ny});
			}
		}
		n=JH.size();
		while(n--){
			auto CurJH=JH.front(); JH.pop();
			for(int i=0;i<4;i++){
				int nx=CurJH.X+dx[i];
				int ny=CurJH.Y+dy[i];
				if(nx<0||nx>=N||ny<0||ny>=M){
					cout<<when[CurJH.X][CurJH.Y];
					return 0;
				}
				if(board[nx][ny]!='.') continue;
				board[nx][ny]='J';
				when[nx][ny]=when[CurJH.X][CurJH.Y]+1;
				JH.push({nx,ny});
			}
		}
		if(JH.empty()){cout<<"IMPOSSIBLE"; break;}
	}
}