#include <bits/stdc++.h>
using namespace std;

int N;
vector <pair<int,int>> cor;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second<b.second) return true;
    else if(a.second>b.second) return false;
    if(a.first<b.first) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        cor.push_back(make_pair(x,y));
    }

    sort(cor.begin(),cor.end(),cmp);

    for(int i=0;i<N;i++) cout<<cor[i].first<<' '<<cor[i].second<<'\n';

    return 0;
} 