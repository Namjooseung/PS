#include <bits/stdc++.h>
using namespace std;

int N, L;
int board[102][102];
int RampBoard[102][102]={0,};
int PassableRoad = 0;

bool CanUseRamp(int x,int y,int dir, int ud){
    if(dir==0){
        if(ud==0){
            if(board[x][y-1]!=board[x][y]-1) return false;
            int SurHeight=board[x][y-1];
            int SurLen=0;
            for(int i=1;i<=L;i++){
                if(y-i<0) return false;
                if(RampBoard[x][y-i]==1) return false;
                if(board[x][y-i]!=SurHeight) return false;
                SurLen++;
                RampBoard[x][y-i]=1;
                if(SurLen==L) return true;
            }
        }
        if(ud==1){
            if(board[x][y-1]!=board[x][y]+1) return false;
            int SurHeight=board[x][y];
            int SurLen=0;
            for(int i=0;i<L;i++){
                if(y+i>=N) return false;
                if(RampBoard[x][y+i]==1) return false;
                if(board[x][y+i]!=SurHeight) return false;
                SurLen++;
                RampBoard[x][y+i]=1;
                if(SurLen==L) return true;
            }
        }
    }
    if(dir==1){
        if(ud==0){
            if(board[x-1][y]!=board[x][y]-1) return false;
            int SurHeight=board[x-1][y];
            int SurLen=0;
            for(int i=1;i<=L;i++){
                if(x-i<0) return false;
                if(RampBoard[x-i][y]==1) return false;
                if(board[x-i][y]!=SurHeight) return false;
                SurLen++;
                RampBoard[x-i][y]=1;
                if(SurLen==L) return true;
            }
        }
        if(ud==1){
            if(board[x-1][y]!=board[x][y]+1) return false;
            int SurHeight=board[x][y];
            int SurLen=0;
            for(int i=0;i<L;i++){
                if(x+i>=N) return false;
                if(RampBoard[x+i][y]==1) return false;
                if(board[x+i][y]!=SurHeight) return false;
                SurLen++;
                RampBoard[x+i][y]=1;
                if(SurLen==L) return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    vector<pair<int, int>> UseRamp;

    for (int i = 0; i < N; i++){
        bool check=true;
        for (int j = 0; j < N; j++){
            if(check==false) break;
            if(j!=0 && board[i][j]!=board[i][j-1]){
                if(board[i][j]>board[i][j-1]) if(!CanUseRamp(i,j,0,0)) check=false;
                if(board[i][j]<board[i][j-1]) if(!CanUseRamp(i,j,0,1)) check=false;
            }
        }
        memset(RampBoard,0,sizeof(RampBoard));
        if(check) PassableRoad++;
    }

    for (int j = 0; j < N; j++){
        bool check=true;
        for (int i = 0; i < N; i++){
            if(check==false) break;
            if(i!=0 && board[i][j]!=board[i-1][j]){
                if(board[i][j]>board[i-1][j]) if(!CanUseRamp(i,j,1,0)) check=false;
                if(board[i][j]<board[i-1][j]) if(!CanUseRamp(i,j,1,1)) check=false;
            }
        }
        memset(RampBoard,0,sizeof(RampBoard));
        if(check) PassableRoad++;
    }

    cout << PassableRoad << '\n';

    return 0;
}