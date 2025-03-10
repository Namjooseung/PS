#include <bits/stdc++.h>
using namespace std;

int N;
vector <string> word;

bool cmp(const string& a,const string& b){
    if(a.length()<b.length()) return true;
    else if(a.length()>b.length()) return false;
    for(int i=0;i<a.length();i++){
        if(a[i]<b[i]) return true;
        else if(a[i]>b[i]) return false;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        word.push_back(tmp);
    }

    sort(word.begin(),word.end(),cmp);
    
    for(int i=0;i<N;i++){
        if(i!=0 && word[i]==word[i-1]) continue;
        cout<<word[i]<<'\n';
    }

    return 0;
}