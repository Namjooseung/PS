#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;
	int* arr=new int[N];
	int Y=0,M=0;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		Y+=((arr[i]/30)+1)*10;
		M+=((arr[i]/60)+1)*15;
		if(arr[i]==0){
			Y-=10;
			M-=15;
		}
	}
	if(Y<M) cout<<"Y "<<Y;
	else if(Y==M) cout<<"Y M "<<Y;
	else cout<<"M "<<M;
}