#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	while(1){
		string c;
		getline(cin,c);
		if(c==".") break;
		stack<char> stack;
		bool check=0;
		for(auto i: c){
			if(i=='.') break;
			else if(i=='['||i=='(') stack.push(i);
			else if(i==']'||i==')'){
				if(stack.empty()){
					check=1;
					break;
				}
				if(i==']'){
					if(stack.top()=='[') stack.pop();
					else{
						check=1;
						break;
					}
				}
				if(i==')'){
					if(stack.top()=='(') stack.pop();
					else{
						check=1;
						break;
					}
				}
			}
		}
		if(check||!stack.empty()) cout<<"no"<<'\n';
		else cout<<"yes"<<'\n';
	}
}