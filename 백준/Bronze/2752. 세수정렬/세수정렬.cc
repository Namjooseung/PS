#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	int arr[3]={a,b,c};
	int copy;
	for(int i=0;i<3;i++){
		for(int j=i+1;j<3;j++){
			if(arr[i]>arr[j]){
				copy=arr[i];
				arr[i]=arr[j];
				arr[j]=copy;
			}
		}
	}
	for(int i=0;i<3;i++){
		cout<<arr[i]<<" ";
	}
}