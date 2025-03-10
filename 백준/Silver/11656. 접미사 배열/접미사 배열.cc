#include <bits/stdc++.h>
using namespace std;

string S;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>S;

    vector <string> arr;

    for(int i=0;i<S.length();i++){
        char tmp[1002]={0,};
        for(int j=i;j<S.length();j++){
            tmp[j-i]=S[j];
        }
        arr.push_back(tmp);
    }

    sort(arr.begin(),arr.end());

    for(auto i : arr) cout<<i<<'\n';

}