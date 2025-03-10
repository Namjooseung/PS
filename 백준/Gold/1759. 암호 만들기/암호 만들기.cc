#include <bits/stdc++.h>
using namespace std;
int L,C;
char alphabet[15];
char arr[15];
bool isused[15];

void func(int k, int g_num, int c_num){
	if(k==L){
		if(g_num<1 || c_num<2) return;
		for(int i=0;i<L;i++) cout<<arr[i];
		cout<<'\n';
	}
	for(int i=0;i<C;i++){
		if(isused[i]) continue;
		if(k!=0 && arr[k-1]>alphabet[i]) continue;
		arr[k]=alphabet[i];
		isused[i]=true;
		if(arr[k]=='a'||arr[k]=='e'||arr[k]=='i'||arr[k]=='o'||arr[k]=='u')
			func(k+1,g_num+1,c_num);
		else func(k+1,g_num,c_num+1);
		isused[i]=false;
	}
	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	cin>>L>>C;
	for(int i=0;i<C;i++) cin>>alphabet[i];
	sort(alphabet,alphabet+C);
	func(0,0,0);
}