#include <bits/stdc++.h>
using namespace std;
int HowEqual(int arr1[], int arr2[]);
	
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string arr1,arr2;
	int ABC1[26]={};
	int ABC2[26]={};
	cin>>arr1>>arr2;
	for(int j=0;j<arr1.size();j++)
		ABC1[arr1[j]-'a']++;
	for(int j=0;j<arr2.size();j++)
		ABC2[arr2[j]-'a']++;
	cout<<HowEqual(ABC1,ABC2); 
	
	
}

int HowEqual(int arr1[], int arr2[]){
	int num=0;
	for(int i=0;i<26;i++){
		if(arr1[i]!=arr2[i]){
			if(arr1[i]>arr2[i]) num+=arr1[i]-arr2[i];
			else num+=arr2[i]-arr1[i];
		}
	}
	return num;
}