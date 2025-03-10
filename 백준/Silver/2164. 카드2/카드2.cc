#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	queue<int> Q;
	int N,num=1;
	cin>>N;
	while(N--){
		Q.push(num);
		num++;
	}
	while(Q.size()!=1){
		Q.pop();
		if(Q.size()==1) break;
		Q.push(Q.front());
		Q.pop();
	}
	cout<<Q.front();
}