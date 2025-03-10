#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[9],sum=0;
	for(int i=0;i<9;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	int key=sum-100;
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if(arr[i]+arr[j]==key){
				arr[i]=101;
				arr[j]=101;
				key=-1;
			}
		}
		if(key==-1) break;
	}
	int copy;
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if(arr[i]>arr[j]){
				copy=arr[i];
				arr[i]=arr[j];
				arr[j]=copy;
			}
		}
	}
	for(int i=0;i<7;i++){
		cout<<arr[i]<<"\n";
	}
}