#include <bits/stdc++.h>
using namespace std;
char board[6561][6561];

void func(int N,int x,int y){
	if(N==1){
		board[x][y]='*';
		return;
	}
	func(N/3,x,y);
	func(N/3,x+N/3,y);
	func(N/3,x+(2*N)/3,y);
	func(N/3,x+(2*N)/3,y+N/3);
	func(N/3,x+(2*N)/3,y+(2*N)/3);
	func(N/3,x+N/3,y+(2*N)/3);
	func(N/3,x,y+(2*N)/3);
	func(N/3,x,y+N/3);
	return;
}

int main(void)
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) board[i][j]=' ';
	}
	func(N,0,0);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}
}