#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int N,M,K;
int NoteBook[40][40];
int Sticker[102][12][12];
int CopySticker[12][12];
vector <pair<int,int>> stk_size;

void StickSticker(int x,int y,int stk_num){
	for(int i=0;i<stk_size[stk_num].X;i++){
		for(int j=0;j<stk_size[stk_num].Y;j++){
			NoteBook[x+i][y+j]+=Sticker[stk_num][i][j];
		}
	}
	return;
}

bool can_stick(int x,int y,int stk_num){
	for(int i=0;i<stk_size[stk_num].X;i++){
		for(int j=0;j<stk_size[stk_num].Y;j++){
			if(x+i<0 || x+i>=N || y+j<0 || y+j>=M) return false;
			if(Sticker[stk_num][i][j]==1 && NoteBook[x+i][y+j]==1)
				return false;
		}
	}
	return true;
}

void RotateSticker(int stk_num){
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++) CopySticker[i][j]=0;
	}
	int NewX=0;
	int NewY=0;
	for(int i=0;i<stk_size[stk_num].Y;i++){
		NewY=0;
		for(int j=stk_size[stk_num].X-1;j>=0;j--){
			CopySticker[NewX][NewY]=Sticker[stk_num][j][i];
			NewY++;
		}
		NewX++;
	}
	stk_size[stk_num]={NewX,NewY};
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++) Sticker[stk_num][i][j]=0;
	}
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++) Sticker[stk_num][i][j]=CopySticker[i][j];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	cin>>N>>M>>K;
	for(int stk=0;stk<K;stk++){
		int R,C;
		cin>>R>>C;
		stk_size.push_back({R,C});
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++) cin>>Sticker[stk][i][j];
		}
	}
	for(int stk_num=0;stk_num<K;stk_num++){
		bool check=false;
		for(int r=0;r<4;r++){
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					if(can_stick(i,j,stk_num)){
						StickSticker(i,j,stk_num);
						check=true;
						break;
					}
				}
				if(check) break;
			}
			if(check) break;
			else RotateSticker(stk_num);
		}
	}
	int num=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) if(NoteBook[i][j]==1) num++;
	}
	cout<<num;
}