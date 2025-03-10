#include <bits/stdc++.h>
using namespace std;
vector<int> Cogwheel[5];
bool check[5];
int K;
int Score=0;

void Rotation(int N,int dir){
	check[N]=true;
	if(N==1){
		if(Cogwheel[1][2]!=Cogwheel[2][6] && check[2]==false) Rotation(2,-dir);
	}
	if(N==2){
		if(Cogwheel[2][2]!=Cogwheel[3][6] && check[3]==false) Rotation(3,-dir);
		if(Cogwheel[2][6]!=Cogwheel[1][2] && check[1]==false) Rotation(1,-dir);
	}
	if(N==3){
		if(Cogwheel[3][2]!=Cogwheel[4][6] && check[4]==false) Rotation(4,-dir);
		if(Cogwheel[3][6]!=Cogwheel[2][2] && check[2]==false) Rotation(2,-dir);
	}
	if(N==4){
		if(Cogwheel[4][6]!=Cogwheel[3][2] && check[3]==false) Rotation(3,-dir);
	}
	if(dir==1){
		Cogwheel[N].insert(Cogwheel[N].begin(),Cogwheel[N].back());
		Cogwheel[N].pop_back();
	}
	if(dir==-1){
		Cogwheel[N].push_back(Cogwheel[N].front());
		Cogwheel[N].erase(Cogwheel[N].begin());
	}
}

int main(void)
{
	for(int i=1;i<=4;i++){
		string s;
		cin>>s;
		for(int j=0;j<8;j++){
			Cogwheel[i].push_back(s[j]-'0');
		}
	}
	cin>>K;
	while(K--){
		for(auto& i : check) i=false;
		int CogwheelNum,dir;
		cin>>CogwheelNum>>dir;
		Rotation(CogwheelNum,dir);
		if(K==0){
			for(int i=1;i<=4;i++){
				if(Cogwheel[i].front()==1) Score+=pow(2,i-1);
			}
		}
	}
	cout<<Score;
}