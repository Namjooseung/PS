#include <bits/stdc++.h>
using namespace std;
int N;
int possible=0;
bool isused1[15];
bool isused2[30];
bool isused3[30];


void func(int k){
	if(k>N){
		possible++;
		return;
	}
	for(int i=1;i<=N;i++){
		if(isused1[i] || isused2[k+i] || isused3[k-i+N]) continue;
		isused1[i]=true;
		isused2[k+i]=true;
		isused3[k-i+N]=true;
		func(k+1);
		isused1[i]=false;
		isused2[k+i]=false;
		isused3[k-i+N]=false;
	}
	return;
}

int main(void)
{
	cin>>N;
	func(1);
	cout<<possible;
}