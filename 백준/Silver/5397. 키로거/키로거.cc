#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	int N;
	cin>>N;
	while(N--){
		ios::sync_with_stdio(0);
		cin.tie(0);
		list<char> PassWord;
		auto Cursor=PassWord.begin();
		string L;
		cin>>L;
		for(auto i : L){
			if(i=='<'){
				if(Cursor==PassWord.begin());
				else Cursor--;
			}
			else if(i=='>'){
				if(Cursor==PassWord.end());
				else Cursor++;
			}
			else if(i=='-'){
				if(Cursor==PassWord.begin());
				else{
					Cursor--;
					Cursor = PassWord.erase(Cursor);
				}
			}
			else{
				PassWord.insert(Cursor,i);
			}
		}
		for(auto i : PassWord)
			cout<<i;
		cout<<'\n';
	}
	
}