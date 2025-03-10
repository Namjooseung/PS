#include <bits/stdc++.h>
using namespace std;
int N,M,r,c;
int Board[51][51];
int Dir;
int CleanedSpace=0;
bool CanMove[4]={false,false,false,false};


bool CheckAround(int x,int y){
	int dx[4]={-1,0,1,0};
	int dy[4]={0,1,0,-1};
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
		if(Board[nx][ny]!=0) continue;
		CanMove[i]=true;
	}
	for(auto i : CanMove) if(i) return true;
	return false;
}

void MovingRobot(){
	switch (Dir){
		case 0:
			r-=1;
			break;
		case 1:
			c+=1;
			break;
		case 2:
			r+=1;
			break;
		case 3:
			c-=1;
			break;
		default:
			break;
	}
	return;
}
bool MovingBackRobot(){
	int dx[4]={1,0,-1,0};
	int dy[4]={0,-1,0,1};
	int nx=r+dx[Dir];
	int ny=c+dy[Dir];
	if(nx<0 || nx>=N || ny<0 || ny>=M) return false;
	switch (Dir){
		case 0:
			if(Board[r+1][c]==1) return false;
			r+=1;
			break;
		case 1:
			if(Board[r][c-1]==1) return false;
			c-=1;
			break;
		case 2:
			if(Board[r-1][c]==1) return false;
			r-=1;
			break;
		case 3:
			if(Board[r][c+1]==1) return false;
			c+=1;
			break;
		default:
			break;
	}
	return true;
}

int main(void)
{
	cin>>N>>M;
	cin>>r>>c>>Dir;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) cin>>Board[i][j];
	}
	while(1){
		for(int i=0;i<4;i++) CanMove[i]=false;
		if(Board[r][c]==0){
			Board[r][c]=2;
			CleanedSpace++;
		}
		if(CheckAround(r,c)){
			while(1){
				bool check=false;
				if(Dir==0) Dir=3;
				else Dir--;
				if(CanMove[Dir]) check=true;
				if(check) break;
			}
			MovingRobot();
			continue;
		}
		else{
			bool check;
			if(MovingBackRobot()) continue;
			else break;
		}
	}
	cout<<CleanedSpace;
}