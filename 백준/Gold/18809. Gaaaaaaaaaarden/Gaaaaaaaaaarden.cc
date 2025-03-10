#include <bits/stdc++.h>
using namespace std;
int board[52][52];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int when[52][52];
int N,M,G,R;
int MAX=0;

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	cin>>N>>M>>G>>R;
	int available_board=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>board[i][j];
			if(board[i][j]==2) available_board++;
		}
	}
	vector <int> V;
	for(int i=0;i<available_board;i++){
		if(i<G) V.push_back(0);
		else if(i<G+R) V.push_back(1);
		else V.push_back(2);
	}
	do{
		char RealBoard[52][52];
		int num=0;
		queue <pair<int,int>> Q;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				when[i][j]=-1;
				if(board[i][j]==0) RealBoard[i][j]='*';
				if(board[i][j]==1) RealBoard[i][j]='0';
				if(board[i][j]==2){
					if(V[num]==0){
						RealBoard[i][j]='G';
						when[i][j]=0;
						Q.push({i,j});
					}
					if(V[num]==1){
						RealBoard[i][j]='R';
						when[i][j]=0;
						Q.push({i,j});
					}
					if(V[num]==2) RealBoard[i][j]='0';
					num++;
				}
			}
		}
		int flower_num=0;
		while(!Q.empty()){
			auto cur=Q.front(); Q.pop();
			if(RealBoard[cur.first][cur.second]=='F') continue;
			for(int i=0;i<4;i++){
				int nx=cur.first+dx[i];
				int ny=cur.second+dy[i];
				if(nx<0||nx>=N||ny<0||ny>=M) continue;
				if(RealBoard[nx][ny]=='R'&&RealBoard[cur.first][cur.second]=='G'||
				  RealBoard[nx][ny]=='G'&&RealBoard[cur.first][cur.second]=='R'){
					if(when[nx][ny]==when[cur.first][cur.second]+1){
						RealBoard[nx][ny]='F';
						flower_num++;
						continue;
					}
				}
				if(RealBoard[nx][ny]!='0') continue;
				if(when[nx][ny]!=-1) continue;
				Q.push({nx,ny});
				when[nx][ny]=when[cur.first][cur.second]+1;
				RealBoard[nx][ny]=RealBoard[cur.first][cur.second];
			}
		}
		if(flower_num>MAX) MAX=flower_num;
	}while(next_permutation(V.begin(),V.end()));
	cout<<MAX;
}