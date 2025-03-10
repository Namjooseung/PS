#include <bits/stdc++.h>
using namespace std;
int N,f;
int board[12][12];
bool isused1[22];
bool isused2[22];
int MAX[2];

void func(int x,int y,int num){
	if(y>N){
		if(y%2==0) y=1;
		else y=2;
		x++;
	}
	if(x>N){
		if(num>MAX[f]) MAX[f]=num;
		return;
	}
	if(board[x][y]==1&&isused1[x+y]==false&&isused2[x-y+N]==false){
		isused1[x+y]=true;
		isused2[x-y+N]=true;
		func(x,y+2,num+1);
		isused1[x+y]=false;
		isused2[x-y+N]=false;	
	}
	func(x,y+2,num);
}

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) cin>>board[i][j];
	}
	f=0; func(0,0,0);
	f=1; func(0,1,0);
	cout<<MAX[0]+MAX[1];
}