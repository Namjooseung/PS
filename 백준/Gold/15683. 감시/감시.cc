#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[8][8];
int check[8][8];
int dx[5]={0,-1,0,1,0};
int dy[5]={0,0,1,0,-1};
int N,M;
int MIN=100;
pair<int,int> cctv[8];
int cctv_num=0;

void change_check(int x,int y,int dir,int how){
	while(1){
		x+=dx[dir];
		y+=dy[dir];
		if(x>=N || x<0 || y>=M || y<0) break;
		if(board[x][y]==6) return;
		if(check[x][y]==-1) continue;
		check[x][y]+=how;
	}
	return;
}

void func(int k){
	if(k==cctv_num){
		int invisible=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++) if(check[i][j]==0) invisible++;
		}
		if(MIN>invisible) MIN=invisible;
		/*if(invisible==12){
			cout<<'\n';
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++) cout<<check[i][j]<<' ';
				cout<<'\n';
			}
		}*/
		return;
	}
	auto cur=cctv[k];
	if(board[cur.X][cur.Y]==1){
		change_check(cur.X,cur.Y,1,1);
		func(k+1);
		change_check(cur.X,cur.Y,1,-1);
		change_check(cur.X,cur.Y,2,1);
		func(k+1);
		change_check(cur.X,cur.Y,2,-1);
		change_check(cur.X,cur.Y,3,1);
		func(k+1);
		change_check(cur.X,cur.Y,3,-1);
		change_check(cur.X,cur.Y,4,1);
		func(k+1);
		change_check(cur.X,cur.Y,4,-1);
	}
	if(board[cur.X][cur.Y]==2){
		change_check(cur.X,cur.Y,2,1);
		change_check(cur.X,cur.Y,4,1);
		func(k+1);
		change_check(cur.X,cur.Y,2,-1);
		change_check(cur.X,cur.Y,4,-1);
		change_check(cur.X,cur.Y,1,1);
		change_check(cur.X,cur.Y,3,1);
		func(k+1);
		change_check(cur.X,cur.Y,1,-1);
		change_check(cur.X,cur.Y,3,-1);
	}
	if(board[cur.X][cur.Y]==3){
		change_check(cur.X,cur.Y,1,1);
		change_check(cur.X,cur.Y,2,1);
		func(k+1);
		change_check(cur.X,cur.Y,1,-1);
		change_check(cur.X,cur.Y,2,-1);
		change_check(cur.X,cur.Y,2,1);
		change_check(cur.X,cur.Y,3,1);
		func(k+1);
		change_check(cur.X,cur.Y,2,-1);
		change_check(cur.X,cur.Y,3,-1);
		change_check(cur.X,cur.Y,3,1);
		change_check(cur.X,cur.Y,4,1);
		func(k+1);
		change_check(cur.X,cur.Y,3,-1);
		change_check(cur.X,cur.Y,4,-1);
		change_check(cur.X,cur.Y,4,1);
		change_check(cur.X,cur.Y,1,1);
		func(k+1);
		change_check(cur.X,cur.Y,4,-1);
		change_check(cur.X,cur.Y,1,-1);
	}
	if(board[cur.X][cur.Y]==4){
		change_check(cur.X,cur.Y,1,1);
		change_check(cur.X,cur.Y,2,1);
		change_check(cur.X,cur.Y,3,1);
		func(k+1);
		change_check(cur.X,cur.Y,1,-1);
		change_check(cur.X,cur.Y,2,-1);
		change_check(cur.X,cur.Y,3,-1);
		change_check(cur.X,cur.Y,2,1);
		change_check(cur.X,cur.Y,3,1);
		change_check(cur.X,cur.Y,4,1);
		func(k+1);
		change_check(cur.X,cur.Y,2,-1);
		change_check(cur.X,cur.Y,3,-1);
		change_check(cur.X,cur.Y,4,-1);
		change_check(cur.X,cur.Y,3,1);
		change_check(cur.X,cur.Y,4,1);
		change_check(cur.X,cur.Y,1,1);
		func(k+1);
		change_check(cur.X,cur.Y,3,-1);
		change_check(cur.X,cur.Y,4,-1);
		change_check(cur.X,cur.Y,1,-1);
		change_check(cur.X,cur.Y,4,1);
		change_check(cur.X,cur.Y,1,1);
		change_check(cur.X,cur.Y,2,1);
		func(k+1);
		change_check(cur.X,cur.Y,4,-1);
		change_check(cur.X,cur.Y,1,-1);
		change_check(cur.X,cur.Y,2,-1);
	}
	if(board[cur.X][cur.Y]==5){
		change_check(cur.X,cur.Y,1,1);
		change_check(cur.X,cur.Y,2,1);
		change_check(cur.X,cur.Y,3,1);
		change_check(cur.X,cur.Y,4,1);
		func(k+1);
		change_check(cur.X,cur.Y,1,-1);
		change_check(cur.X,cur.Y,2,-1);
		change_check(cur.X,cur.Y,3,-1);
		change_check(cur.X,cur.Y,4,-1);
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>board[i][j];
			if(board[i][j]!=0 && board[i][j]!=6) cctv[cctv_num++]={i,j};
			if(board[i][j]!=0) check[i][j]=-1;
		}
	}
	func(0);
	cout<<MIN;
}