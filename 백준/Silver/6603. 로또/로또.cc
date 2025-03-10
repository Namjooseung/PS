#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int k;
	int S[14];
	while(1){
		cin>>k;
		if(k==0) break;
		for(int i=0;i<k;i++) cin>>S[i];
		vector <int> v;
		for(int i=0;i<6;i++) v.push_back(0);
		for(int i=0;i<k-6;i++) v.push_back(1);
		do{
			for(int i=0;i<k;i++) if(v[i]==0) cout<<S[i]<<' ';
			cout<<'\n';
		}while(next_permutation(v.begin(),v.end()));
		cout<<'\n';
	}
}