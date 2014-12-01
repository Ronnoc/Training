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

typedef long long LL;
typedef pair<int, int> PII;
int a[111111];
void solve(){
	int n,k;
//	int a[10],i;
//	int ok[111];
//	memset(ok,0,sizeof ok);
//	for(i=1;i<=5;i++)a[i]=i;
//	do{
//		int tot=0;
//		for(i=1;i<=5;i++)if(__gcd(a[i],i)>1)tot++;
//		if(!ok[tot])for(i=1;i<=5;i++)cout<<a[i]<<" ";
//		if(!ok[tot])cout<<tot<<endl;
//		ok[tot]=1;
//	}while(next_permutation(a+1,a+1+5));
	while(scanf("%d%d",&n,&k)!=EOF){
		if(k>n-1){printf("-1\n");continue;}
		if(k==0){
			for(int i=1;i<n;i++)printf("%d ",i+1);
			printf("%d\n",1);
			continue;
		}
		int i;
		for(i=1;i<=n;i++)a[i]=i;
		k=n-1-k;
		if(k&1)swap(a[1],a[2]),k--;
		int l=3;
		while(k){
			swap(a[l],a[l+1]);
			l+=2;
			k-=2;
		}
		for(i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
