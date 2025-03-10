#include <bits/stdc++.h>
using namespace std;
int num=0;

int func(int n,int r,int c){
	if(n==0) return num;
	int half=pow(2,n-1);
	if(r<half&&c<half) return func(n-1,r,c);
	num+=half*half;
	if(r<half) return func(n-1,r,c-half);
	num+=half*half;
	if(c<half) return func(n-1,r-half,c);
	num+=half*half;
	return func(n-1,r-half,c-half);
}

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int n,r,c;
	cin>>n>>r>>c;
	cout<< func(n,r,c);
}