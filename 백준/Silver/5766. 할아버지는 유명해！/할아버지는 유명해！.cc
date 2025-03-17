#include <bits/stdc++.h>
using namespace std;



int compare(pair<int,int> a, pair<int,int> b){
    if(a.first>b.first) return true;
    else if(a.first<b.first) return false;
    else if(a.second>b.second) return false;
    else return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        int player[10002]={0,};
        
        int N,M;
        cin>>N>>M;
        if(N==0 && M==0) break;

        int min_id=10001;
        int max_id=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                int tmp;
                cin>>tmp;
                player[tmp]++;
                if(tmp<min_id) min_id=tmp;
                if(tmp>max_id) max_id=tmp;
            }
        }
        vector <pair<int,int>> Rank;
        for(int i=min_id;i<=max_id;i++) Rank.push_back(make_pair(player[i],i));
        sort(Rank.begin(),Rank.end(),compare);

        for(int i=1;i<Rank.size();i++){
            if(i==1){
                cout<<Rank[i].second<<' ';
                continue;
            }
            if(Rank[i].first==Rank[i-1].first) cout<<Rank[i].second<<' ';
            else break;
        }
        cout<<'\n';
    }
    

    return 0;
}