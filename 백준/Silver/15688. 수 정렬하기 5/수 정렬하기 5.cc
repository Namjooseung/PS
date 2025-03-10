#include <bits/stdc++.h>
using namespace std;

int N;
int freq[2000002]={0,};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N;

    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        freq[tmp+1000000]++;
    }

    for(int i=0;i<2000002;i++){
        for(int j=0;j<freq[i];j++) cout<<i-1000000<<'\n';
    }
}