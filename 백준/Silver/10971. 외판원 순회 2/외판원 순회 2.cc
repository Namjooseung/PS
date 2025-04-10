#include <bits/stdc++.h>
using namespace std;

int N;
int cost[12][12];
vector<int> V[12];
int visited[12]={0,};
int cur_cost=0;
int min_cost=INT_MAX;

void Travel(int s,int d,int va){
    if(d==N){
        if(cur_cost<min_cost) min_cost=cur_cost;
        return;
    }
    for(auto i : V[va]){
        if(i==0 && d!=N-1) continue;
        if(visited[i]!=0) continue;
        cur_cost+=cost[va][i];
        visited[i]++;
        Travel(0,d+1,i);
        cur_cost-=cost[va][i];
        visited[i]--;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int c;
            cin>>c;
            if(c!=0){
                V[i].push_back(j);
            }
            cost[i][j]=c;
        }
    }
    Travel(0,0,0);
    cout<<min_cost;

    return 0;
}