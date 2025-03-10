#include <bits/stdc++.h>
using namespace std;
int func(int arr[],int len);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin>>N>>K;
	int arr[7][2]={};
	int S,Y;
	for(int i=0;i<N;i++){
		cin>>S>>Y;
		arr[Y][S]++;
	}
	int RoomNum=0;
	for(int i=1;i<=6;i++){
		for(int j=0;j<=1;j++){
			if(arr[i][j]==0) continue;
			if(arr[i][j]%K==0) RoomNum+=arr[i][j]/K;
			else RoomNum+=arr[i][j]/K+1;
		}
	}
	cout<<RoomNum;
}
