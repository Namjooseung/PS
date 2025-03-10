#include <bits/stdc++.h>
using namespace std;

int T;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;

    while(T--){
        vector <int> A;
        vector <int> B;
        int num_A,num_B;
        cin>>num_A>>num_B;
        for(int i=0;i<num_A;i++){
            int tmp;
            cin>>tmp;
            A.push_back(tmp);
        }
        for(int i=0;i<num_B;i++){
            int tmp;
            cin>>tmp;
            B.push_back(tmp);
        }
        int count=0;
        for(auto i : A){
            for(auto j : B){
                if(i>j) count++;
            }
        }
        cout<<count<<'\n';
    }
}