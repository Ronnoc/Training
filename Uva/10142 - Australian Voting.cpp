#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)

typedef long long LL;
typedef pair<int, int> PII;
void solve(){
	int T;
	char s[1111];
	char name[88][88];
	vector<vector<int> >L;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		if(t>1)cout<<endl;
		L.clear();
		int n;
		scanf("%d",&n);
		gets(s);
		int i,j;
		for(i=1;i<=n;i++)gets(name[i]);
		while(gets(s)!=NULL){
//			cout<<"~"<<s<<endl;
			if(strlen(s)==0)break;
			string tp="";
			int len=strlen(s);
			for(i=0;i<len;i++)tp+=s[i];
			istringstream sin(tp);
			vector<int>T;
			int x;
			while(sin>>x)T.PB(x);
			L.PB(T);
//			cout<<tp<<endl;
		}
		if(L.empty()){
			for(i=1;i<=n;i++)cout<<name[i]<<endl;
			continue;
		}
//		for(i=0;i<L.SZ;i++){
//			for(j=0;j<L[i].SZ;j++)cout<<L[i][j]<<" ";
//			cout<<endl;
//		}
		bool out[88];
		memset(out,0,sizeof out);
		int ans=-1;
		int flag=0;
		while(1){
			int tot[88];
			memset(tot,0,sizeof tot);
			int i;
			for(i=0;i<L.SZ;i++){
				for(j=0;j<L[i].SZ;j++)if(!out[L[i][j]])break;
				tot[L[i][j]]++;
				vector<int>TT;
				for(j=0;j<L[i].SZ;j++)if(!out[L[i][j]])TT.PB(L[i][j]);
				L[i]=TT;
			}
			for(i=1;i<=n;i++)if(tot[i]*2>L.SZ){ans=i;break;}
			if(ans!=-1)break;
			vector<PII>S;
			for(i=1;i<=n;i++)if(!out[i])S.PB(MP(tot[i],i));
			sort(S.OP,S.ED);
			for(i=0;i<S.SZ;i++)if(S[i].AA==S[0].AA)out[S[i].BB]=1;
			if(S[S.SZ-1].AA==S[0].AA){for(i=0;i<S.SZ;i++)cout<<name[S[i].BB]<<endl;flag=1;}
			if(flag)break;
		}
		if(!flag)cout<<name[ans]<<endl;
	}
}
int main(){
//	freopen("in.txt","r",stdin);
//	while(1)
		solve();
	return 0;
}
