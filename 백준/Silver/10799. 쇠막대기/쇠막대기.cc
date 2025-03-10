#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	string s;
	cin>>s;
	bool check=0;
	int count=0;
	stack <int> stack;
	for(auto i : s){
		if(i=='('){
			check=1;
			stack.push(i);
		}
		else{
			if(check){
				stack.pop();
				count+=stack.size();
			}
			else{
				stack.pop();
				count+=1;
			}
			check=0;
		}
	}
	cout<<count;
}