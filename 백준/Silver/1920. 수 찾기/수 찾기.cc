#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> num;
bool isHere(int k){
    int l=0,r=N-1;
    while(1){
        if(num[(l+r)/2]<k) l=(l+r)/2+1;
        else if(num[(l+r)/2]>k) r=(l+r)/2-1;
        else return true;
        if(l>r) break;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        num.push_back(tmp);
    }
    sort(num.begin(),num.end());

    cin>>M;
    while(M--){
        int tmp;
        cin>>tmp;
        int l=0, r=N-1;
        cout<<isHere(tmp)<<'\n';
    }

    return 0;
}