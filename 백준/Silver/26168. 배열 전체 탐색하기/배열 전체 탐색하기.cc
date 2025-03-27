#include <bits/stdc++.h>
using namespace std;

long long int n,m;
vector<long long int> num;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(long long int i=0;i<n;i++){
        long long int tmp; cin>>tmp;
        num.push_back(tmp);
    }
    sort(num.begin(),num.end());

    while(m--){
        long long int p,k;
        cin>>p>>k;
        long long int left=0,right=n-1;
        if(p==1){
            while(left<=right){
                long long int mid=(left+right)/2;
                if(num[mid]<k) left=mid+1;
                else right=mid-1;
            }
            cout<<n-left<<'\n';
        }
        else if(p==2){
            while(left<=right){
                long long int mid=(left+right)/2;
                if(num[mid]<=k)left=mid+1;
                else right=mid-1;
            }
            cout<<n-left<<'\n';
        }
        else{
            long long int k2; cin>>k2;
            long long int result=0;
            while(left<=right){
                long long int mid=(left+right)/2;
                if(num[mid]<=k2) left=mid+1;
                else right=mid-1;
            }
            result+=right;
            left=0; right=n-1;
            while(left<=right){
                long long int mid=(left+right)/2;
                if(num[mid]<k) left=mid+1;
                else right=mid-1;
            }
            result=result-left+1;
            cout<<result<<'\n';
        }
    }

    return 0;
}