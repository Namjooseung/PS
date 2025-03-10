#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[7];
	int sum=0;
	for(int i=0;i<7;i++){
		cin>>arr[i];
		if(arr[i]%2!=0)sum+=arr[i];
		else arr[i]=100;
	}
	int min=100;
	for(int i=0;i<7;i++){
		if(min>arr[i]) min=arr[i];
	}
	if(sum!=0)cout<<sum<<"\n";
	else cout<<"-1";
	if(min!=100)cout<<min;
	
}
