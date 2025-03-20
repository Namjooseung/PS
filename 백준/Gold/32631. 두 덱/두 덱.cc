#include <bits/stdc++.h>
using namespace std;

int N,K;
long long bag_A_weight[5002]={0,};
long long bag_B_weight[5002]={0,};

long long min_weight=LLONG_MAX;

long long FindMinWeight(int num,char bag){
    long long min=LLONG_MAX;
    if(bag=='A'){
        for(int i=0;i+num<=N;i++){
            long long sum=bag_A_weight[num+i]-bag_A_weight[i];
            if(sum<min) min=sum;
        }
    }
    else{
        for(int i=0;i+num<=N;i++){
            long long sum=bag_B_weight[num+i]-bag_B_weight[i];
            if(sum<min) min=sum;
        }
    }
    return min;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;
    int total_items=2*N-K;

    long long tmp;
    for(int i=0;i<N;i++){
        cin>>tmp;
        bag_A_weight[i+1]=bag_A_weight[i]+tmp;
    }
    for(int i=0;i<N;i++){
        cin>>tmp;
        bag_B_weight[i+1]=bag_B_weight[i]+tmp;
    }

    for(int i=0;i<=total_items;i++){
        if(total_items-i>N || i>N) continue;
        long long sum_A=FindMinWeight(total_items-i,'A');
        long long sum_B=FindMinWeight(i,'B');
        if(sum_A>sum_B){if(min_weight>sum_A) min_weight=sum_A;}
        else{if(min_weight>sum_B) min_weight=sum_B;}
    }

    cout<<min_weight;

    return 0;
}