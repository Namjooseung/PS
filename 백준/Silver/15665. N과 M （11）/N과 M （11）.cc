#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[10];
int num[10];
bool isused[10];
int before;
int s_num=0;

void func(int k){
	if(k==M){
		if(arr[M-1]==before) return;
		for(int i=0;i<M;i++) cout<<arr[i]<<' ';
		before=arr[M-1];
		cout<<'\n';
		return;
	}
	for(int i=0;i<s_num;i++){
		//if(isused[i]) continue;
		//if(k!=0 && arr[k-1]>num[i]) continue;
		arr[k]=num[i];
		//isused[i]=true;
		func(k+1);
		//isused[i]=false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		int s;
		bool check=false;
		cin>>s;
		for(int j=0;j<s_num;j++){
			if(s==num[j]) check=true;
		}
		if(check) continue;
		num[s_num]=s;
		s_num++;
	}
	sort(num,num+s_num);
	func(0);
}