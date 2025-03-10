#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int K;
	cin>>K;
	stack<int> stack;
	while(K--){
		int N;
		cin>>N;
		if(N==0) stack.pop();
		else stack.push(N);
	}
	long long int Sum=0;
	while(!stack.empty()){
		Sum+=stack.top();
		stack.pop();
	}
	
	cout<<Sum;
}