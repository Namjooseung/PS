#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    srand(static_cast<unsigned int>(std::time(0)));

    cin>>N;

    for(int i=0;i<=20000;i++){
        int randomNumber = std::rand() % N + 1;
        cout<<"? "<<randomNumber<<'\n';
        char c;
        cin>>c;
        if(c=='N') continue;
        else if(c=='Y'){
            cout<<"! "<<randomNumber<<'\n';
            break;
        }
    }


    return 0;
}