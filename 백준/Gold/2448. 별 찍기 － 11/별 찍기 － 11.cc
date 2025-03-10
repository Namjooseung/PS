#include <bits/stdc++.h>
using namespace std;
char board[3072][6143];

void func(int N,int x,int y){
	if(N==3){
		board[x][y]='*';
		board[x+1][y-1]='*';
		board[x+1][y+1]='*';
		board[x+2][y-2]='*';
		board[x+2][y-1]='*';
		board[x+2][y]='*';
		board[x+2][y+1]='*';
		board[x+2][y+2]='*';
		return;
	}
	func(N/2,x,y);
	func(N/2,x+N/2,y-N/2);
	func(N/2,x+N/2,y+N/2);
	return;
}

int main(void)
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<2*N-1;j++) board[i][j]=' ';
	}
	func(N,0,N-1);
	for(int i=0;i<N;i++){
		for(int j=0;j<2*N-1;j++) cout<<board[i][j];
		cout<<'\n';
	}
}