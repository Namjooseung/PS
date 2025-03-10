#include <bits/stdc++.h>
using namespace std;
int num;
int num_arr[13];
int result_max=-1000000000;
int result_min=1000000000;
int opr_num[4];
vector <int> opr;

int main(){
    cin>>num;

    for(int i=0;i<num;i++){
        cin>>num_arr[i];
    }

    for(int i=0;i<4;i++){
        cin>>opr_num[i];
        for(int j=0;j<opr_num[i];j++) opr.push_back(i+1);
    }

    do{
        int result=num_arr[0];

        for(int i=0;i<opr.size();i++){
            switch(opr[i]){
                case 1:
                    result+=num_arr[i+1];
                    break;
                case 2:
                    result-=num_arr[i+1];
                    break;
                case 3:
                    result*=num_arr[i+1];
                    break;
                case 4:
                    result/=num_arr[i+1];
                    break;
                default: break;
            }
        }

        if(result_max<result) result_max=result;
        if(result_min>result) result_min=result;

    }while(next_permutation(opr.begin(),opr.end()));

    cout<<result_max<<'\n'<<result_min;

    return 0;
}