#include <bits/stdc++.h>
using namespace std;

int N,M;
char board[12][12];
int min_moving=11;
stack <pair<int,int>> red_location;
stack <pair<int,int>> blue_location;
pair<int,int> hole;
int dx[5]={0,-1,0,1,0};
int dy[5]={0,0,1,0,-1};
bool check=false;

void Escape(int n);
void MovingBoard(int dir);
void MovingRed(int dir);
void MovingBlue(int dir);

void Escape(int n){
    if(blue_location.top()==hole && red_location.top()!=hole){
        board[red_location.top().first][red_location.top().second]='.';
        red_location.pop();
        blue_location.pop();
        board[red_location.top().first][red_location.top().second]='R';
        board[blue_location.top().first][blue_location.top().second]='B';
        return;
    }
    else if(blue_location.top()==hole && red_location.top()==hole){
        red_location.pop();
        blue_location.pop();
        board[red_location.top().first][red_location.top().second]='R';
        board[blue_location.top().first][blue_location.top().second]='B';
        return;
    }
    else if(red_location.top()==hole && blue_location.top()!=hole){
        if(min_moving>n) min_moving=n;
        board[blue_location.top().first][blue_location.top().second]='.';
        red_location.pop();
        blue_location.pop();
        board[red_location.top().first][red_location.top().second]='R';
        board[blue_location.top().first][blue_location.top().second]='B';
        return;
    }
    else if(n==10){
        board[red_location.top().first][red_location.top().second]='.';
        board[blue_location.top().first][blue_location.top().second]='.';
        red_location.pop();
        blue_location.pop();
        board[red_location.top().first][red_location.top().second]='R';
        board[blue_location.top().first][blue_location.top().second]='B';
        return;
    }

    for(int i=1;i<=4;i++){
        check=false;
        MovingBoard(i);
        if(check){
            red_location.pop();
            blue_location.pop();
            continue;
        }
        Escape(n+1);
    }
    board[red_location.top().first][red_location.top().second]='.';
    board[blue_location.top().first][blue_location.top().second]='.';
    red_location.pop();
    blue_location.pop();
    if(red_location.empty() && blue_location.empty()) return;
    board[red_location.top().first][red_location.top().second]='R';
    board[blue_location.top().first][blue_location.top().second]='B';
    return;
}

void MovingRed(int dir){
    int nx=red_location.top().first;
    int ny=red_location.top().second;

    while(1){
        nx+=dx[dir];
        ny+=dy[dir];
        if(board[nx][ny]=='O'){
            board[red_location.top().first][red_location.top().second]='.';
            red_location.push(make_pair(nx,ny));
            return;
        }
        else if(board[nx][ny]!='.'){
            nx-=dx[dir];
            ny-=dy[dir];
            break;
        }
    }

    board[red_location.top().first][red_location.top().second]='.';
    board[nx][ny]='R';
    red_location.push(make_pair(nx,ny));

    return;
}

void MovingBlue(int dir){
    int nx=blue_location.top().first;
    int ny=blue_location.top().second;

    while(1){
        nx+=dx[dir];
        ny+=dy[dir];
        if(board[nx][ny]=='O'){
            board[blue_location.top().first][blue_location.top().second]='.';
            blue_location.push(make_pair(nx,ny));
            return;
        }
        else if(board[nx][ny]!='.'){
            nx-=dx[dir];
            ny-=dy[dir];
            break;
        }
    }

    board[blue_location.top().first][blue_location.top().second]='.';
    board[nx][ny]='B';
    blue_location.push(make_pair(nx,ny));

    return;
}

void MovingBoard(int dir){
    if(dir>4) dir-=4;

    auto cur_red=red_location.top();
    auto cur_blue=blue_location.top();
    
    if(dir==1){
        if(cur_red.second==cur_blue.second){
            if(cur_red.first>cur_blue.first){
                MovingBlue(1);
                MovingRed(1);
            }
            else{
                MovingRed(1);
                MovingBlue(1);
            }
        }
        else{
            MovingRed(1);
            MovingBlue(1);
        }
    }
    else if(dir==2){
        if(cur_red.first==cur_blue.first){
            if(cur_red.second>cur_blue.second){
                MovingRed(2);
                MovingBlue(2);
            }
            else{
                MovingBlue(2);
                MovingRed(2);
            }
        }
        else{
            MovingRed(2);
            MovingBlue(2);
        }
    }
    else if(dir==3){
        if(cur_red.second==cur_blue.second){
            if(cur_red.first>cur_blue.first){
                MovingRed(3);
                MovingBlue(3);
            }
            else{
                MovingBlue(3);
                MovingRed(3);
            }
        }
        else{
            MovingRed(3);
            MovingBlue(3);
        }
    }
    else if(dir==4){
        if(cur_red.first==cur_blue.first){
            if(cur_red.second>cur_blue.second){
                MovingBlue(4);
                MovingRed(4);
            }
            else{
                MovingRed(4);
                MovingBlue(4);
            }
        }
        else{
            MovingRed(4);
            MovingBlue(4);
        }
    }

    if(cur_red==red_location.top()&&cur_blue==blue_location.top()) check=true;

    return;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        int n=0;
        for(auto j : str){
            board[i][n]=j;
            if(j=='R') red_location.push(make_pair(i,n));
            if(j=='B') blue_location.push(make_pair(i,n));
            if(j=='O') hole=make_pair(i,n);
            n++;
        }
    }

    Escape(0);
    if(min_moving==11) min_moving=-1;
    cout<<min_moving;

    return 0;
}