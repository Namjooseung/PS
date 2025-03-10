#include <bits/stdc++.h>
using namespace std;
int board [2187][2187];
int NumZero=0;
int NumOne=0;
int NumMinusOne=0;

bool check(int N,int x,int y){
	int copy=board[x][y];
	for(int i=x;i<x+N;i++){
		for(int j=y;j<y+N;j++){
			if(copy!=board[i][j]) return 1;
			copy=board[i][j];
		}
	}
	return 0;
}

void func(int N,int x,int y){
	if(N==1){
		if(board[x][y]==0) NumZero++;
		else if(board[x][y]==1) NumOne++;
		else NumMinusOne++;
		return;
	}
	if(!check(N,x,y)){
		if(board[x][y]==0) NumZero++;
		else if(board[x][y]==1) NumOne++;
		else NumMinusOne++;
		return;
	}
	func(N/3,x,y);
	x+=N/3;
	func(N/3,x,y);
	x+=N/3;
	func(N/3,x,y);
	y+=N/3;
	func(N/3,x,y);
	x-=N/3;
	func(N/3,x,y);
	x-=N/3;
	func(N/3,x,y);
	y+=N/3;
	func(N/3,x,y);
	x+=N/3;
	func(N/3,x,y);
	x+=N/3;
	func(N/3,x,y);
	return;
}

int main(void)
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) cin>>board[i][j];
	}
	func(N,0,0);
	cout<<NumMinusOne<<'\n'<<NumZero<<'\n'<<NumOne;
}