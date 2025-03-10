#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b&&b==c)cout<<10000+a*1000;
	else if(a==b||a==c||b==c){
		int key;
		if(a==b)key=a;
		else if(a==c)key=a;
		else key=b;
		cout<<1000+key*100;
	}
	else{
		if(a>b&&a>c) cout<<a*100;
		else if(b>c) cout<<b*100;
		else cout<<c*100;
	}
}