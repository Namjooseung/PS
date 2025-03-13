#include <bits/stdc++.h>
using namespace std;

string m;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>m;
    cin>>N;

    int m_len=m.length();
    double max_score=0;
    string gbs_word="No Jam";

    while(N--){
        string w;
        double g;
        cin>>w>>g;
        int count=0;
        for(auto i : w) if(i==m[count]) count++;
        if(count==m_len){
            double gbs_score=g/double(w.length()-m_len);
            //cout<<gbs_score<<'\n';
            if(max_score<gbs_score){
                max_score=gbs_score;
                gbs_word=w;
            }
        }
    }
    cout<<gbs_word<<'\n';

    return 0;
}