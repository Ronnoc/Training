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
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

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
const double eps=1e-8;
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int main(){
	int i,j,x;
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		int mask[11];
		memset(mask,0,sizeof mask);
		for(i=0;i<5;i++){
			mask[i]=0;
			for(j=0;j<6;j++){
				scanf("%d",&x);
				mask[i]<<=1;
				mask[i]|=x;
			}
		}
		printf("PUZZLE #%d\n",CASE);
		for(i=0;i<1<<6;i++){
			int now[11],pl[11];
			for(j=0;j<5;j++)now[j]=mask[j];
			now[0]^=i;now[0]^=(i<<1)%(1<<6);now[0]^=i>>1;
			now[1]^=i;
			pl[0]=i;
			for(j=1;j<5;j++){
				int t=now[j-1];
				pl[j]=t;
				now[j-1]^=t;
				now[j]^=t;
				now[j]^=(t<<1)%(1<<6);
				now[j]^=t>>1;
				now[j+1]^=t;
			}
//			cout<<i<<" "<<now[4]<<endl;
			if(now[4]==0){
				for(j=0;j<5;j++){
					for(int k=5;k>=0;k--){
						if(pl[j]>>k&1)printf("1");
						else printf("0");
						if(k)printf(" ");
						else printf("\n");
					}
				}
				break;
			}
		}
	}
	return 0;
}
