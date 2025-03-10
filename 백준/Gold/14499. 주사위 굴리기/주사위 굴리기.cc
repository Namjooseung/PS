#include <bits/stdc++.h>
using namespace std;
int board[22][22];
vector <int> Dice={0,0,0,0,0,0};
int N,M,x,y,K;

void MovingDice(int dir){
	if(dir==1){
		if(y+1<0 || y+1>=M) return;
		vector <int> CopyDice(Dice);
		Dice[0]=CopyDice[1];
		Dice[2]=CopyDice[0];
		Dice[1]=CopyDice[5];
		Dice[5]=CopyDice[2];
		y+=1;
		if(board[x][y]!=0){
			Dice[0]=board[x][y];
			board[x][y]=0;
		}
		else board[x][y]=Dice[0];
	}
	if(dir==2){
		if(y-1<0 || y-1>=M) return;
		vector <int> CopyDice(Dice);
		Dice[0]=CopyDice[2];
		Dice[2]=CopyDice[5];
		Dice[1]=CopyDice[0];
		Dice[5]=CopyDice[1];
		y-=1;
		if(board[x][y]!=0){
			Dice[0]=board[x][y];
			board[x][y]=0;
		}
		else board[x][y]=Dice[0];
	}
	if(dir==3){
		if(x-1<0 || x-1>=N) return;
		vector <int> CopyDice(Dice);
		Dice[0]=CopyDice[4];
		Dice[4]=CopyDice[5];
		Dice[3]=CopyDice[0];
		Dice[5]=CopyDice[3];
		x-=1;
		if(board[x][y]!=0){
			Dice[0]=board[x][y];
			board[x][y]=0;
		}
		else board[x][y]=Dice[0];
	}
	if(dir==4){
		if(x+1<0 || x+1>=N) return;
		vector <int> CopyDice(Dice);
		Dice[0]=CopyDice[3];
		Dice[4]=CopyDice[0];
		Dice[3]=CopyDice[5];
		Dice[5]=CopyDice[4];
		x+=1;
		if(board[x][y]!=0){
			Dice[0]=board[x][y];
			board[x][y]=0;
		}
		else board[x][y]=Dice[0];
	}
	
	cout<<Dice[5]<<'\n';
}

int main(void)
{
	cin>>N>>M>>x>>y>>K;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) cin>>board[i][j];
	}
	while(K--){
		int dir;
		cin>>dir;
		MovingDice(dir);
	}
}