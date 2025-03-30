#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> Have;

int FindCard(int n){
    int left=0,right=Have.size()-1;
    while(left<right){
        int mid=(left+right)/2;
        if(Have[mid]<n) left=mid+1;
        else right=mid;
    }
    if(Have[left]==n) return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        Have.push_back(tmp);
    }
    sort(Have.begin(),Have.end());

    cin>>M;

    for(int i=0;i<M;i++){
        int tmp; cin>>tmp;
        cout<<FindCard(tmp)<<' ';
    }


    return 0;
}