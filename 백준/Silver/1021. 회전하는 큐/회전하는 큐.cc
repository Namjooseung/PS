#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int N,M;
	cin>>N>>M;
	deque<int> D;
	for(int i=1;i<=N;i++){
		D.push_back(i);
	}
	vector<int> V(M);
	for(auto& i : V)
		cin>>i;
	int sum=0;
	for(auto i : V){
		int num=0;
		while(1){
			if(D.front()==i) break;
			D.push_back(D.front());
			D.pop_front();
			num++;
		}
		if(num>D.size()/2) num=D.size()-num;
		sum+=num;
		D.pop_front();
	}
	cout<<sum;
}