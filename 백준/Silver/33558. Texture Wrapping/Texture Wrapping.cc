#include <bits/stdc++.h>
using namespace std;

char plane[203][203]={0,};
char texture[203][203]={0,};
int N,M,U,V;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    cin>>U>>V;

    for(int i=1;i<=U;i++){
        string arr;
        cin>>arr;
        int j=1;
        for(auto k : arr){
            texture[i][j]=k;
            j++;
        }
    }

    string how;
    cin>>how;

    if(how=="clamp-to-edge"){
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                if(i<=U && j<=V){plane[i][j]=texture[i][j]; continue;}
                else if(i>U && j<=V){plane[i][j]=texture[U][j]; continue;}
                else if(i<=U && j>V){plane[i][j]=texture[i][V]; continue;}
                else plane[i][j]=texture[U][V];
            }
        }
    }
    else if(how=="repeat"){
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                int a,b;
                a=i%U; b=j%V;
                if(a==0) a+=U;
                if(b==0) b+=V;
                plane[i][j]=texture[a][b];
            }
        }
    }
    else if(how=="mirrored-repeat"){
        for(int i=0;i<=U;i++){
            for(int j=0;j<=V;j++) plane[i][j]=texture[i][j];
        }
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                int a,b;
                a=i%U; b=j%V;
                if(a==0) a+=U;
                if(b==0) b+=V;
                if(i<=U && j<=V) continue;
                else if(i<=U && j>V){plane[i][j]=plane[i][j-2*b+1]; continue;}
                else{plane[i][j]=plane[i-2*a+1][j]; continue;}
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) cout<<plane[i][j];
        cout<<'\n';
    }

    return 0;
}