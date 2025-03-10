#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n=0;
	while(n<3){
		int arr[4];
		int num=0;
		for(int i=0;i<4;i++){
			cin>>arr[i];
			if(arr[i]==0)num++;
		}
		if(num==1)cout<<"A"<<"\n";
		if(num==2)cout<<"B"<<"\n";
		if(num==3)cout<<"C"<<"\n";
		if(num==4)cout<<"D"<<"\n";
		if(num==0)cout<<"E"<<"\n";
		n++;
	}
}