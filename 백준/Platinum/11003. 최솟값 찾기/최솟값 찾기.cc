#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int N,L;
	cin>>N>>L;
	deque<pair<int,int>> compare;
	for(int i=0;i<N;i++){
		int now;
		cin>>now;
		if(i!=0){
			while(1){
				if(compare.back().first>=now) compare.pop_back();
				else break;
				if(compare.empty()) break;
			}
		}
		compare.push_back(make_pair(now,i));
		if(compare.front().second<=i-L) compare.pop_front();
		cout<<compare.front().first<<' ';
	}
}