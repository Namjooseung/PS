#include <bits/stdc++.h>
using namespace std;
char board[12][6];
bool check=false;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector <pair<int,int>> V;
void FallingPuyo();

void IsItExplosion(int x,int y){
	bool visit[12][6];
	for(int i=0;i<12;i++)
		for(int j=0;j<6;j++) visit[i][j]=false;
	int size=1;
	queue <pair<int,int>> Q;
	Q.push({x,y});
	V.push_back({x,y});
	visit[x][y]=true;
	while(!Q.empty()){
		auto cur=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int nx=cur.first+dx[i];
			int ny=cur.second+dy[i];
			if(nx<0 || nx>=12 || ny<0 || ny>=6) continue;
			if(board[nx][ny]!=board[x][y]) continue;
			if(visit[nx][ny]) continue;
			Q.push({nx,ny});
			V.push_back({nx,ny});
			visit[nx][ny]=true;
			size++;
		}
	}
	if(size>=4){
		check=true;
	}
	else for(int i=0;i<size;i++) V.pop_back();
}

void FallingPuyo(){
	for(int j=0;j<6;j++){
		for(int i=1;i<=12;i++){
			if(board[12-i][j]=='.') continue;
			for(int k=12-i+1;k<12;k++){
				if(board[k][j]=='.' && k==11){
					board[k][j]=board[12-i][j];
					if(k==12-i) break;
					board[12-i][j]='.';
					break;
				}
				if(board[k][j]=='.') continue;
				if(board[k][j]!='.'){
					board[k-1][j]=board[12-i][j];
					if(k-1==12-i) break;
					board[12-i][j]='.';
					break;
				}
			}
		}
	}
}

int main(void)
{
	for(int i=0;i<12;i++){
		string s;
		cin>>s;
		for(int j=0;j<6;j++) board[i][j]=s[j];
	}
	int chain=0;
	while(1){
		for(int j=0;j<6;j++){
			for(int i=1;i<=12;i++){
				if(board[12-i][j]!='.') IsItExplosion(12-i,j);
				else break;
			}
		}
		for(auto i : V) board[i.first][i.second]='.';
		V.clear();
		FallingPuyo();
		if(check){
			chain++;
			check=false;
		}
		else break;
	}
	cout<<chain;
}