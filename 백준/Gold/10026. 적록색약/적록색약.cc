#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[102][102];
bool vis[102][102];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		int n=0;
		for(auto j : s){
			board[i][n]=j;
			n++;
		}
	}
	stack <pair<int,int>> stack;
	int NormalNum=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(vis[i][j]) continue;
			else{
				stack.push({i,j});
				while(!stack.empty()){
					auto cur = stack.top(); stack.pop();
					for(int i=0;i<4;i++){
						int nx=cur.X+dx[i];
						int ny=cur.Y+dy[i];
						if(nx<0||nx>N||ny<0||ny>=N) continue;
						if(vis[nx][ny]||board[cur.X][cur.Y]!=board[nx][ny]) continue;
						vis[nx][ny]=1;
						stack.push({nx,ny});
					}
				}
				NormalNum++;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) if(board[i][j]=='G') board[i][j]='R';
	}
	memset(vis,0,sizeof(vis));
	int SpecialNum=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(vis[i][j]) continue;
			else{
				stack.push({i,j});
				while(!stack.empty()){
					auto cur = stack.top(); stack.pop();
					for(int i=0;i<4;i++){
						int nx=cur.X+dx[i];
						int ny=cur.Y+dy[i];
						if(nx<0||nx>N||ny<0||ny>=N) continue;
						if(vis[nx][ny]||board[cur.X][cur.Y]!=board[nx][ny]) continue;
						vis[nx][ny]=1;
						stack.push({nx,ny});
					}
				}
				SpecialNum++;
			}
		}
	}
	cout<<NormalNum<<' '<<SpecialNum;
}