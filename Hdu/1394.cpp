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
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
LL l[5010];
LL r[5010];
LL pre[5010];
int a[5010],n;
int BIT[5050];
int MXN=5010;
int LB(int x){return x&(-x);}
int bitadd(int w,int x){
	for(w+=5;w<=MXN;w+=LB(w))BIT[w]+=x;
}
int bitsum(int w){
	int ret=0;
	for(w+=5;w>0;w-=LB(w))ret+=BIT[w];
	return ret;
}
int main(){
	int i,j;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		memset(l,0,sizeof l);
		memset(r,0,sizeof r);
		memset(pre,0,sizeof pre);
		l[0]=0,memset(BIT,0,sizeof BIT);
		for(i=1;i<=n;i++){
			l[i]=l[i-1]+bitsum(n-a[i]);
			bitadd(n-a[i],1);
		}
		r[n+1]=0,memset(BIT,0,sizeof BIT);
		for(i=n;i>=1;i--){
			r[i]=r[i+1]+bitsum(a[i]);
			bitadd(a[i],1);
		}
		pre[0]=0,memset(BIT,0,sizeof BIT);
		for(i=1;i<=n;i++){
			int gs=bitsum(a[i]);
			bitadd(a[i],1);
//			cout<<gs<<" ";
			pre[i]=pre[i-1]+(n-1-a[i]-(i-1-gs))-gs;
//			cout<<"+"<<(n-1-a[i]-(i-1-gs))<<"  -"<<gs<<" =>";
//			cout<<pre[i]<<endl;
		}
		LL ret=l[n];
		for(i=1;i<n;i++)cmin(ret,l[i]+r[i+1]+pre[i]);
		printf("%I64d\n",ret);
	}
	return 0;
}
