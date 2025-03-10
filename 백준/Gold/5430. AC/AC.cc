#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		deque<int> DQ;
		string p;
		cin>>p;
		int n;
		cin>>n;
		string num;
		cin>>num;
		string copy="";
		for(int i=0;i<num.length();i++){
			if(num[i]=='[') continue;
			else if(num[i]==']'||num[i]==','){
				if(copy=="") continue;
				DQ.push_back(stoi(copy));
				copy="";
			}
			else copy+=num[i];
		}
		bool check=1;
		bool error=0;
		for(auto i : p){
			if(i=='R') check=!check;
			else if(i=='D'){
				if(DQ.empty()){
					cout<<"error\n";
					error=!error;
					break;
				}
				if(check) DQ.pop_front();
				else DQ.pop_back();
			}
		}
		if(DQ.empty()&&error) continue;
		int l=DQ.size();
		if(check){
			cout<<'[';
			for(int i=1;i<=l;i++){
				cout<<DQ.front();
				DQ.pop_front();
				if(i==l) break;
				cout<<',';
			}
			cout<<']';
		}
		else{
			cout<<'[';
			for(int i=1;i<=l;i++){
				cout<<DQ.back();
				DQ.pop_back();
				if(i==l) break;
				cout<<',';
			}
			cout<<']';
		}
		cout<<'\n';
	}
}