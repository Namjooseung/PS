#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    while(n--){
        int people;
        cin>>people;

        if(people%2==0){
            cout<<(people*(people-2))/4<<'\n';
        }
        else{
            cout<<((people-1)*(people-1))/4<<'\n';
        }
    }

    return 0;
}