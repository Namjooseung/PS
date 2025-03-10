#include <bits/stdc++.h>
using namespace std;

int N;
vector <string> Name[202];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        int age;
        string name;
        cin>>age>>name;
        Name[age].push_back(name);
    }

    for(int i=1;i<=200;i++){
        if(Name[i].empty()) continue;
        for(auto j : Name[i]) cout<<i<<' '<<j<<'\n';
    }

    return 0;
} 