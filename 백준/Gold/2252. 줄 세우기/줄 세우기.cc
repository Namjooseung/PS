#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> G[32001];
int In[32001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        int A,B;
        cin>>A>>B;
        G[A].push_back(B);
        In[B]++;
    }
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(In[i]==0) q.push(i);
    }

    while(!q.empty()){
        auto cur=q.front();
        cout<<cur<<' ';
        q.pop();
        for(auto i : G[cur]){
            In[i]--;
            if(In[i]==0) q.push(i);
        }
    }

    return 0;
}