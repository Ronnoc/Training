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

typedef long long LL;
typedef pair<int, int> PII;
char s[1111111];
vector<pair<PII,int> >Time;
vector<PII>L;
stack<int>S;
int m;
int p[111111];
int q[111111];
int ans[1111111];
int BIT[1111111];
int LB(int x){return x&(-x);}
int add(int w){
	w+=5;
	for(;w<1000011;w+=LB(w))BIT[w]++;
}
int get(int w){
	w+=5;
	int ret=0;
	for(;w>=1;w-=LB(w))ret+=BIT[w];
	return ret;
}
void solve() {
  while (scanf ("%s",s) !=EOF) {
    Time.clear();
    L.clear();
    memset(BIT,0,sizeof BIT);
    while(!S.empty())S.pop();
    int len=strlen (s);
    int i;
    for (i=0; i<len; i++) {
      if (s[i]=='(') {S.push (i);}
      else {
        if (!S.empty()) {
          int u=S.top();
          S.pop();
          L.PB (MP (u+1,i+1));
          Time.PB(MP(MP(-u-1,i+1),0));
        }
      }
    }
//    for (i=0; i<L.SZ; i++) cout<<L[i].AA<<" "<<L[i].BB<<endl;
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			scanf("%d%d",&p[i],&q[i]);
			Time.PB(MP(MP(-p[i],q[i]),i));
		}
		sort(Time.OP,Time.ED);
		int tot=0;
		for(i=0;i<Time.SZ;i++){
			Time[i].AA.AA*=-1;
//			cout<<"+ "<<Time[i].AA.AA<<" "<<Time[i].AA.BB<<" @"<<Time[i].BB<<endl;
			if(Time[i].BB){
				int sum=get(Time[i].AA.BB);
//				cout<<sum<<" ans"<<endl;
				ans[Time[i].BB]=sum;
			}else {
				add(Time[i].AA.BB);
				tot++;
			}
		}
		for(i=1;i<=m;i++)printf("%d\n",ans[i]*2);
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
