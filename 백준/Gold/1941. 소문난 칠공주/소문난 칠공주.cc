#include <bits/stdc++.h>
using namespace std;
char board[5][5];
vector <int> V;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	for(int i=0;i<5;i++){
		string s;
		cin>>s;
		for(int j=0;j<5;j++) board[i][j]=s[j];
	}
	for(int i=0;i<25;i++){
		if(i<18) V.push_back(0);
		else V.push_back(1);
	}
	int possible=0;
	do{
		int check_board[5][5];
		int num=0;
		queue <pair<int,int>> Q;
		bool visit[5][5]={0,};
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(V[num]==0) check_board[i][j]=0;
				else check_board[i][j]=1;
				num++;
			}
		}
		bool check=false;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(check_board[i][j]==1){
					Q.push({i,j});
					visit[i][j]=true;
					check=true;
					break;
				}
			}
			if(check) break;
		}
		int size=1;
		int DS_num=0;
		while(!Q.empty()){
			auto cur=Q.front(); Q.pop();
			if(board[cur.first][cur.second]=='S') DS_num++;
			for(int i=0;i<4;i++){
				int nx=cur.first+dx[i];
				int ny=cur.second+dy[i];
				if(nx<0||nx>=5||ny<0||ny>=5) continue;
				if(visit[nx][ny] || check_board[nx][ny]==0) continue;
				Q.push({nx,ny});
				visit[nx][ny]=true; size++;
			}
		}
		if(size==7 && DS_num>=4) possible++;
		
	}while(next_permutation(V.begin(),V.end()));
	cout<<possible;
		
}