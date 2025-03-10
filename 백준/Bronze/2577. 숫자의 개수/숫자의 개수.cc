#include <bits/stdc++.h>
using namespace std;
int func(int arr[],int len);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A,B,C;
	cin>>A>>B>>C;
	int n=A*B*C;
	int Number[11];
	fill(Number,Number+11,0);
	while(n!=0){
		Number[n%10]++;
		n=n/10;
	}
	for(int i=0;i<=9;i++){
		cout<<Number[i]<<'\n';
	}
}