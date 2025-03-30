#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<long long int> tree_height;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int low=1000000002;
    long long int high=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        long long int tmp; cin>>tmp;
        if(tmp<low) low=tmp;
        if(tmp>high) high=tmp;
        tree_height.push_back(tmp);
    }

    long long int left=0;
    long long int right=high;
    long long int mid;
    while(left<=right){
        mid=(left+right)/2;
        long long int sum=0;
        for(int i=0;i<N;i++){
            if(tree_height[i]<=mid) continue;
            sum+=(tree_height[i]-mid);
        }
        if(sum>=M) left=mid+1;
        else right=mid-1;
    }

    cout<<right;

    return 0;
}