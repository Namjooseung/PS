#include <bits/stdc++.h>
using namespace std;
int func(int arr[],int len);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> arr(n);
	for(auto& i : arr){
		cin>>i;
	}
	int x;
	cin>>x;
	int num=0;
	int p1=0,p2=n-1;
	/*for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(arr[i]>arr[j]) swap(arr[i],arr[j]);
		}
	}*/
	sort(arr.begin(),arr.end());
	while(p1<p2){
		if(arr[p1]+arr[p2]==x){
			num++;
			p1++;
			p2--;
		}
		else if(arr[p1]+arr[p2]<x) p1++;
		else p2--;
	}
	cout<<num;
}