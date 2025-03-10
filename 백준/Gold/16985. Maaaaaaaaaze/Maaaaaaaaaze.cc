#include <bits/stdc++.h>
using namespace std;
int board[6][6][6];
int save_board[6][6][6];
int when[6][6][6];
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int shortest=200;

void FindShortestPath(){
	if(board[0][0][0]!=1 || board[4][4][4]!=1) return;
	queue <tuple<int,int,int>> Q;
	Q.push({0,0,0});
	when[0][0][0]=0;
	while(!Q.empty()){
		auto cur=Q.front(); Q.pop();
		for(int i=0;i<6;i++){
			int nx=get<0>(cur)+dx[i];
			int ny=get<1>(cur)+dy[i];
			int nz=get<2>(cur)+dz[i];
			if(nx<0 || nx>=5 || ny<0 || ny>=5 || nz<0 || nz>=5) continue;
			if(board[nx][ny][nz]==0 || when[nx][ny][nz]!=-1) continue;
			if(nx==4 && ny==4 && nz==4){
				int Short=when[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
				if(Short<shortest) shortest=Short;
			}
			when[nx][ny][nz]=when[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
			Q.push({nx,ny,nz});
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++) when[i][j][k]=-1;
		}
	}
}

void MovingBoard(int num,int BoardNum){
	for(int n=0;n<num;n++){
		int CopyBoard[6][6];
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				CopyBoard[i][j]=board[4-j][i][BoardNum];
			}
		}
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				board[i][j][BoardNum]=CopyBoard[i][j];
			}
		}
	}
}

void Play(int d){
	if(d==5){
		FindShortestPath();
		return;
	}
	
	for(int i=0;i<4;i++){
		MovingBoard(i,d);
		Play(d+1);
		MovingBoard(4-i,d);
	}
	return;
}

int main(void)
{
	for(int z=0;z<5;z++){
		for(int x=0;x<5;x++){
			for(int y=0;y<5;y++){
				cin>>board[x][y][z];
				save_board[x][y][z]=board[x][y][z];
				when[x][y][z]=-1;
			}
		}
	}
	
	vector <int> V={0,1,2,3,4};
	
	do{
		for(int i=0;i<5;i++){
			for(int x=0;x<5;x++){
				for(int y=0;y<5;y++) board[x][y][i]=save_board[x][y][V[i]];
			}
		}
		Play(0);
		
	}while(next_permutation(V.begin(),V.end()));
	
	if(shortest==200) shortest=-1;
	cout<<shortest;
}