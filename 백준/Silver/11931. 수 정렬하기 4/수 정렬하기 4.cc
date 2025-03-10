#include <bits/stdc++.h>
using namespace std;

int N;
long long int Arr[1000005];

bool cmp(int a,int b){
    if(a>=b) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        cin>>Arr[i];
    }

    sort(Arr,Arr+N,cmp);

    for(int i=0;i<N;i++) cout<<Arr[i]<<'\n';

    return 0;
} 