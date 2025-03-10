#include <bits/stdc++.h>
using namespace std;
int func(int arr[],int len);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;
	vector <int> arr(N);
	int Number[201]={};
	for(auto& i : arr){
		cin>>i;
		if(i>100||i<-100) continue;
		Number[i+100]++;
	}
	int v;
	cin>>v;
	cout<<Number[v+100];
}