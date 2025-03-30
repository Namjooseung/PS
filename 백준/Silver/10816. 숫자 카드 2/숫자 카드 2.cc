#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> Have;

int LowerBound(int n){
    int left=0,right=Have.size()-1;
    while(left<right){
        int mid=(left+right)/2;
        if(Have[mid]<n) left=mid+1;
        else right=mid;
    }
    return left;
}

int UpperBound(int n){
    int left=0,right=Have.size()-1;
    while(left<right){
        int mid=(left+right)/2;
        if(Have[mid]<=n) left=mid+1;
        else right=mid;
    }
    return left;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        Have.push_back(tmp);
    }
    Have.push_back(10000002);
    sort(Have.begin(),Have.end());

    cin>>M;

    for(int i=0;i<M;i++){
        int tmp; cin>>tmp;
        cout<<UpperBound(tmp)-LowerBound(tmp)<<' ';
    }


    return 0;
}