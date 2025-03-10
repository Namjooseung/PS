#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        cin>>Arr[i];
    }

    sort(Arr,Arr+N);

    for(int i=0;i<N;i++) cout<<Arr[i]<<'\n';

    return 0;
} 