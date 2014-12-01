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
#define SORT(x) sort(x.OP,x.ED)
#define UNIQUE(x) x.erase(unique(x.OP,X.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int a[5010];
int mns[12500010];
short l[5010];
short r[5010];
short sl[5010][5010];
short sr[5010][5010];
int n;
int LB(int x){return x&(-x);}
int add(short *a,int h){
	h+=5;
	for(int i=h;i<5010;i+=LB(i))a[i]++;
}
int getSum(short *a,int h){
	h+=5;
	int ret=0;
	for(int i=h;i>=1;i-=LB(i))ret+=a[i];
	return ret;
}
void solve(){
	while(~scanf("%d",&n)){
		int i,j,ii,jj;
		memset(sl,0,sizeof l);
		memset(sr,0,sizeof r);
		memset(mns,0,sizeof mns);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		for(i=0;i<n;i++){
			memset(l,0,sizeof l);
			memset(r,0,sizeof r);
			for(j=i+1;j<n;j++)add(r,a[j]);
			for(j=0;j<i;j++)add(l,a[j]);
			for(j=0;j<n;j++)sl[i][j]=getSum(l,j);
			for(j=0;j<n;j++)sr[i][j]=getSum(r,j);
		}
		int tot=0;
		for(i=0;i<n;i++)for(j=i+1;j<n;j++)if(a[i]>a[j])tot++;
		int ans=tot,cnt=0;
		for(i=0;i<n;i++)for(j=i+1;j<n;j++){
			int now=tot;
			int lbi=i-sl[i][a[i]];
			int rsi=sr[i][a[i]];
			int lbj=j-sl[j][a[j]];
			int rsj=sr[j][a[j]];
//			cout<<i<<" "<<j<<" :";
//			cout<<lbi<<" "<<rsi<<" ";
//			cout<<lbj<<" "<<rsj<<" ~";
			now=now-lbi-rsi-lbj-rsj;
			if(a[i]>a[j])now++;
//			cout<<"("<<now<<")"<<" ";
			now=now+(i-sl[i][a[j]])+sr[i][a[j]-1]+(j-sl[j][a[i]])+sr[j][a[i]-1];
//			cout<<(i-getSum(l[i],a[j]))<<" "<<getSum(r[i],a[j]-1)<<" ";
//			cout<<(j-getSum(l[j],a[i]))<<" "<<getSum(r[j],a[i]-1)<<" ~";
			if(a[j]>a[i])now++;
//			cout<<"("<<sum<<")";
//			cout<<now<<endl;
//			if(sum!=now)cout<<"!";
//			system("pause");
				if(now<ans)ans=now,cnt=1;
				else if(now==ans)cnt++;
		}
		printf ("%d %d\n",ans,cnt);
//		cout<<"~"<<endl;
	}
}
// 5 1 3 4 0 2
int main(){
//	while(1)
		solve();
	return 0;
}
