#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	string s;
	cin>>s;
	int value=0;
	stack<pair<char,int>> stack;
	for(auto i : s){
		if(i=='('||i=='['){
			stack.push({i,0});
		}
		else{
			if(stack.empty()){
				value=0;
				break;
			}
			if(i==')'&&stack.top().first=='('){
				if(stack.size()==1){
					if(stack.top().second==0){
						value+=2;
						stack.pop();
					}
					else{
						value+=(stack.top().second)*2;
						stack.pop();
					}
					continue;
				}
				if(stack.top().second==0){
					stack.pop();
					stack.top().second+=2;
				}
				else{
					int num=stack.top().second*2;
					stack.pop();
					stack.top().second+=num;
				}
			}
			else if(i==']'&&stack.top().first=='['){
				if(stack.size()==1){
					if(stack.top().second==0){
						value+=3;
						stack.pop();
					}
					else{
						value+=(stack.top().second)*3;
						stack.pop();
					}
					continue;
				}
				if(stack.top().second==0){
					stack.pop();
					stack.top().second+=3;
				}
				else{
					int num=stack.top().second*3;
					stack.pop();
					stack.top().second+=num;
				}
			}
			else{
				value=0;
				break;
			}
		}
	}
	cout<<value;
}