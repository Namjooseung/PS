#include <bits/stdc++.h>
using namespace std;
int N,M;
int board[52][52];
int CopyBoard[52][52];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ChickenNum=0;
int Min=1000000;
vector <pair<int,int>> WhereChicken;
vector <int> v;

int FindNearChicken(int x,int y){
	int Near=1000000;
	int ex;
	int idx=-1;
	for(auto i : WhereChicken){
		idx++;
		if(v[idx]==1) continue;
		ex=abs(x-i.first)+abs(y-i.second);
		if(Near>ex) Near=ex;
	}
	return Near;
}

int main(void)
{
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>board[i][j];
			CopyBoard[i][j]=board[i][j];
			if(board[i][j]==2){
				ChickenNum++;
				WhereChicken.push_back({i,j});
			}
		}
	}
	
	for(int i=0;i<ChickenNum;i++){
		if(i<M) v.push_back(0);
		else v.push_back(1);
	}
	
	do{
		int ChickenDistance=0;
		int num=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(board[i][j]==1) ChickenDistance+=FindNearChicken(i,j);
			}
		}
		if(Min>ChickenDistance) Min=ChickenDistance;
	}while(next_permutation(v.begin(),v.end()));
	
	cout<<Min;
}