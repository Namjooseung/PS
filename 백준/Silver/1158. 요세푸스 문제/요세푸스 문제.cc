#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	int N,K,n;
	n=0;
	cin>>N>>K;
	list<int> Num;
	vector<int> v(N);
	for(int i=1;i<=N;i++)
		Num.push_back(i);
	auto iter=Num.begin();
	for(int j=0;j<N;j++){
		for(int i=0;i<K-1;i++){
			if(*iter==Num.back()) iter=Num.begin();
			else iter++;
		}
		v[n]=*iter;
		if(*iter==Num.back()){
			iter=Num.erase(iter);
			iter=Num.begin();
		}
		else iter=Num.erase(iter);
		
		n++;
	}
	cout<<'<';
	for(int i=0;i<N-1;i++)
		cout<<v[i]<<", ";
	
	cout<< v[N-1]<<'>';
}
