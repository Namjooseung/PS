#include <bits/stdc++.h>
using namespace std;
int num=0;

long long int func(int A,int B, int C){
	if(B==1) return A%C;
	long long int val=func(A,B/2,C);
	val=val*val%C;
	if(B%2==0) return val;
	else return val*A%C;
}

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int A,B,C;
	cin>>A>>B>>C;
	cout<<func(A,B,C);
}