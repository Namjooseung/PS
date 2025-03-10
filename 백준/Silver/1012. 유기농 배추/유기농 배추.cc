#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[2502][2502];
bool vis[2502][2052];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
	int M,N,K;
	cin>>M>>N>>K;
	memset(board, 0, sizeof(board));
    memset(vis, 0, sizeof(vis));
	for(int i=0;i<K;i++){
		int x,y;
		cin>>x>>y;
		board[x][y]=1;
	}
	queue <pair<int,int>> Q;
	int num=0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]==1&&!vis[i][j]){
				Q.push({i,j});
				vis[i][j]=1;
				num++;
				while(!Q.empty()){
					auto cur=Q.front(); Q.pop();
					for(int i=0;i<4;i++){
						int nx=cur.X+dx[i];
						int ny=cur.Y+dy[i];
						if(nx<0||nx>=M||ny<0||ny>=N) continue;
						if(vis[nx][ny]||board[nx][ny]!=1) continue;
						vis[nx][ny]=1;
						Q.push({nx,ny});
					}
				}
			}
		}
	}
	cout<<num<<'\n';
	}
}