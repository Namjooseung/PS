#include <bits/stdc++.h>
using namespace std;
int board[128][128];
int Num_0=0;
int Num_1=0;

bool check(int N,int x,int y){
	int copy=board[x][y];
	for(int i=x;i<x+N;i++){
		for(int j=y;j<y+N;j++){
			if(copy!=board[i][j]) return false;
			copy=board[i][j];
		}
	}
	return true;
}

void func(int N,int x,int y){
	if(N==1){
		if(board[x][y]==1) Num_1++;
		else Num_0++;
		return;
	}
	if(!check(N,x,y)){
		func(N/2,x,y);
		func(N/2,x+(N/2),y);
		func(N/2,x,y+(N/2));
		func(N/2,x+(N/2),y+(N/2));
	}
	else{
		if(board[x][y]==1) Num_1++;
		else Num_0++;
		return;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) cin>>board[i][j];
	}
	func(N,0,0);
	cout<<Num_0<<'\n'<<Num_1;
}