#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[10];
vector <int> num;
bool isused[10000];


void func(int k){
	if(k==M){
		for(int i=0;i<M;i++) cout<<arr[i]<<' ';
		cout<<'\n';
		return;
	}
	for(auto i : num){
		//if(isused[i]) continue;
		if(k!=0 && arr[k-1]>i) continue;
		arr[k]=i;
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
		int n;
		cin>>n;
		num.push_back(n);
	}
	sort(num.begin(),num.end());
	func(0);
}