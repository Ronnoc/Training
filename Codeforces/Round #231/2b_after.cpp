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

int main(){
	int i,j;
	int p,x;
	while(~scanf("%d%d",&p,&x)){
		if(p<=5){
			int ans=0;
			for(i=pow(10,p-1);i<pow(10,p);i++){
				int b=i%10;
				if(!b)continue;
				int a=i/10;
				int t=b*pow(10,p-1)+a;
				if(t==i*x){
					ans=i;
					break;
				}
			}
			if(ans)cout<<ans<<endl;
			else cout<<"Impossible\n";
			continue;
		}
		if(x==1){
			while(p--)printf("1");
			printf("\n");
			continue;
		}
		int mod=10*x-1;
		int u=1%mod;
		for(i=1;i<=p-1;i++)u=u*10%mod;
		u=(u+mod-x)%mod;
		int b;
		for(b=x;b<=9;b++){
			if(b*u%mod==0)break;
		}
		if(b==10){
			printf("Impossible\n");
			continue;
		}
		int last=p-1;
		int now=b;
		int z=10*x-1;
		while(now<z)now*=10,last--;
		while(last){
			cout<<now/z;
			now=(now%z)*10;
			last--;
		}
		cout<<(now/z)<<b<<endl;
	}
	return 0;
}
