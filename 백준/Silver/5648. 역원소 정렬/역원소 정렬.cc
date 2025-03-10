#include <bits/stdc++.h>
using namespace std;

int N;
vector <string> num;

bool cmp(string a,string b){
    if(a.length()<b.length()) return true;
    else if(a.length()>b.length()) return false;
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


    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        reverse(tmp.begin(),tmp.end());
        int e=0;
        for(int i=0;i<tmp.length();i++){
            if(i==0 && tmp[i]!='0') break;
            if(tmp[i]!='0'){
                e=i;
                break;
            }
        }
        tmp.erase(0,e);
        num.push_back(tmp);
    }

    sort(num.begin(),num.end(),cmp);
    
    for(auto i : num) cout<<i<<'\n';

    return 0;
}