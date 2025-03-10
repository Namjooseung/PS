#include <bits/stdc++.h>
using namespace std;
int board[1000][1000];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int M,N,K;
	cin>>M>>N>>K;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++) board[j][i]=0;
	}
	while(K--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=b;i<d;i++){
			for(int j=a;j<c;j++) board[j][i]=1;
		}
	}
	/*for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout<<board[j][i];
		}
		cout<<'\n';
	}*/
	int num=0;
	vector <int> v;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(board[j][i]==0){
				num++;
				queue <pair<int,int>> Q;
				int size=0;
				Q.push({j,i}); size++;
				board[j][i]=1;
				while(!Q.empty()){
					auto cur=Q.front(); Q.pop();
					for(int i=0;i<4;i++){
						int nx=cur.first+dx[i];
						int ny=cur.second+dy[i];
						if(nx<0||nx>=N||ny<0||ny>=M) continue;
						if(board[nx][ny]==1) continue;
						board[nx][ny]=1;
						Q.push({nx,ny});
						size++;
					}
				}
				v.push_back(size);
			}
		}
	}
	cout<<num<<'\n';
	sort(v.begin(),v.end());
	for(auto i : v) cout<<i<<' ';
}