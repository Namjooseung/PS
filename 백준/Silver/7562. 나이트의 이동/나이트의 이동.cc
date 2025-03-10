#include <bits/stdc++.h>
using namespace std;
int board[300][300];
int when[300][300];
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int N;
	cin>>N;
	while(N--){
		memset(board,0,sizeof(board));
		memset(when,-1,sizeof(when));
		bool check=false;
		queue <pair<int,int>> Q;
		int size;
		cin>>size;
		int starting_x,starting_y;
		cin>>starting_x>>starting_y;
		Q.push({starting_x,starting_y});
		when[starting_x][starting_y]=0;
		int finish_x,finish_y;
		cin>>finish_x>>finish_y;
		if(starting_x==finish_x&&starting_y==finish_y){
			cout<<"0\n";
			continue;
		}
		board[finish_x][finish_y]=1;
		while(!Q.empty()){
			auto cur=Q.front(); Q.pop();
			for(int i=0;i<8;i++){
				int nx=cur.first+dx[i];
				int ny=cur.second+dy[i];
				if(nx<0||nx>=size||ny<0||ny>=size) continue;
				if(board[nx][ny]==1){
					cout<<when[cur.first][cur.second]+1<<'\n';
					check=true;
				}
				if(when[nx][ny]!=-1) continue;
				when[nx][ny]=when[cur.first][cur.second]+1;
				Q.push({nx,ny});
			}
			if(check) break;
		}
	}
}