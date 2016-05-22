#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
vector<pair<int,string> >S[10005];
int main(){
	int i,j,k,_T;
	int n,m;
	while(cin>>n>>m){
		for(i=1;i<=m;i++)S[i].clear();
		for(i=1;i<=n;i++){
			string s;
			cin>>s>>j>>k;
			S[j].PB(MP(-k,s));
		}
		for(i=1;i<=m;i++){
			sort(S[i].OP,S[i].ED);
			if(S[i].SZ>2&&S[i][1].AA==S[i][2].AA)
				cout<<"?\n";
			else 
				cout<<S[i][0].BB<<" "<<S[i][1].BB<<"\n";
		}
	}
	return 0;
}