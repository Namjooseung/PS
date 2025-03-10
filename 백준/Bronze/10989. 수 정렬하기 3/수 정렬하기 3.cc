#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[10005]={0,};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        Arr[tmp]++;
    }

    for(int i=0;i<10005;i++){
        for(int j=0;j<Arr[i];j++) cout<<i<<'\n';
    }

    return 0;
}