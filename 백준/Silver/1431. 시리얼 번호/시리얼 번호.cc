#include <bits/stdc++.h>
using namespace std;

int N;
string arr[51];

bool cmp(string& a,string& b){
    if(a.length()<b.length()) return true;
    else if (a.length()>b.length()) return false;
    int sum_a=0;
    int sum_b=0;
    for(int i=0;i<a.length();i++){
        if(a[i]>=48 && a[i]<=57) sum_a+=a[i]-48;
        if(b[i]>=48 && b[i]<=57) sum_b+=b[i]-48;
    }
    //cout<<a<<' '<<sum_a<<' '<<b<<' '<<sum_b<<'\n';
    if(sum_a<sum_b) return true;
    else if(sum_a>sum_b) return false;
    for(int i=0;i<a.length();i++){
        if(a[i]<b[i]) return true;
        else if(a[i]>b[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i=0;i<N;i++) cin>>arr[i];

    sort(arr,arr+N,cmp);

    for(int i=0;i<N;i++) cout<<arr[i]<<'\n';
} 