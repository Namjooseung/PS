#include <bits/stdc++.h>
using namespace std;
int N;
int Max=0;
int durability[8];
int weight[8];

void func(int k,int h){
	while(1){
		if(k==N) break;
		if(durability[k]<=0) k+=1;
		else break;
	}
	if(k==N){
		if(h>Max) Max=h;
		return;
	}
	bool check=true;
	for(int i=0;i<N;i++){
		if(k==i) continue;
		if(durability[i]<=0) continue;
		check=false;
		int num=0;
		durability[k]-=weight[i];
		if(durability[k]<=0) num++;
		durability[i]-=weight[k];
		if(durability[i]<=0) num++;
		func(k+1,h+num);
		durability[k]+=weight[i];
		durability[i]+=weight[k];
	}
	if(check) func(N,h);
}


int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) cin>>durability[i]>>weight[i];
	func(0,0);
	cout<<Max;
}