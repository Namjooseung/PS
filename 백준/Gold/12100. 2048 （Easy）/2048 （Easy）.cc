#include <bits/stdc++.h>
using namespace std;
int board[22][22];
bool check[22][22];
int N;
int MaxBlock=0;

void MovingBlock(int x,int y,int dir){
	if(dir==1){
		for(int i=1;i<=x;i++){
			if(x-i==0 && board[x-i][y]==0){
				board[x-i][y]=board[x][y];
				board[x][y]=0;
				break;
			}
			if(board[x-i][y]==0) continue;
			if(board[x-i][y]==board[x][y] && check[x-i][y]==false){
				board[x-i][y]+=board[x][y];
				board[x][y]=0;
				check[x-i][y]=true;
				break;
			}
			else{
				board[x-i+1][y]=board[x][y];
				if(x==x-i+1) break;
				board[x][y]=0;
				break;
			}
		}
	}
	if(dir==2){
		for(int j=1;j<=N-y;j++){
			if(y+j==N-1 && board[x][y+j]==0){
				board[x][y+j]=board[x][y];
				board[x][y]=0;
				break;
			}
			if(board[x][y+j]==0) continue;
			if(board[x][y+j]==board[x][y] && check[x][y+j]==false){
				board[x][y+j]+=board[x][y];
				board[x][y]=0;
				check[x][y+j]=true;
				break;
			}
			else{
				board[x][y+j-1]=board[x][y];
				if(y==y+j-1) break;
				board[x][y]=0;
				break;
			}
		}
	}
	if(dir==3){
		for(int i=1;i<=N-x;i++){
			if(x+i==N-1 && board[x+i][y]==0){
				board[x+i][y]=board[x][y];
				board[x][y]=0;
				break;
			}
			if(board[x+i][y]==0) continue;
			if(board[x+i][y]==board[x][y] && check[x+i][y]==false){
				board[x+i][y]+=board[x][y];
				board[x][y]=0;
				check[x+i][y]=true;
				break;
			}
			else{
				board[x+i-1][y]=board[x][y];
				if(x==x-i+1) break;
				board[x][y]=0;
				break;
			}
		}
	}
	if(dir==4){
		for(int j=1;j<=y;j++){
			if(y-j==0 && board[x][y-j]==0){
				board[x][y-j]=board[x][y];
				board[x][y]=0;
				break;
			}
			if(board[x][y-j]==0) continue;
			if(board[x][y-j]==board[x][y] && check[x][y-j]==false){
				board[x][y-j]+=board[x][y];
				board[x][y]=0;
				check[x][y-j]=true;
				break;
			}
			else{
				board[x][y-j+1]=board[x][y];
				if(y==y-j+1) break;
				board[x][y]=0;
				break;
			}
		}
	}
}

void MovingBoard(int dir){
	if(dir==1){
		for(int j=0;j<N;j++){
			for(int i=0;i<N;i++){
				if(board[i][j]==0) continue;
				if(i==0) continue;
				MovingBlock(i,j,dir);
			}
		}
	}
	
	if(dir==2){
		for(int i=0;i<N;i++){
			for(int j=1;j<=N;j++){
				if(board[i][N-j]==0) continue;
				if(N-j==N-1) continue;
				MovingBlock(i,N-j,dir);
			}
		}
	}
	
	if(dir==3){
		for(int j=0;j<N;j++){
			for(int i=1;i<=N;i++){
				if(board[N-i][j]==0) continue;
				if(N-i==N-1) continue;
				MovingBlock(N-i,j,dir);
			}
		}
	}
	
	if(dir==4){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(board[i][j]==0) continue;
				if(j==0) continue;
				MovingBlock(i,j,dir);
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) check[i][j]=false;
	}
}

void Test(int d){
	if(d==5){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++) if(board[i][j]>MaxBlock) MaxBlock=board[i][j];
		}
		return;
	}
	int CopyBoard[22][22];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) CopyBoard[i][j]=board[i][j];
	}
	for(int i=1;i<=4;i++){
		MovingBoard(i);
		Test(d+1);
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++) board[i][j]=CopyBoard[i][j];
		}
	}
}

int main(void)
{
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) cin>>board[i][j];
	}
	
	Test(0);
	
	cout<<MaxBlock;
}