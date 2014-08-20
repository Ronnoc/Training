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
#include <cassert>
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
const double PI=acos( -1. );
const LL MOD = 1000000007;

int N,C,F;
PII A[100005];
priority_queue<int>PQ;
LL sum;
LL sv[100005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while(~scanf("%d%d%d",&N,&C,&F)){
		int M=N/2;
		for(i=0;i<C;i++)scanf("%d%d",&A[i].AA,&A[i].BB);
		sort(A,A+C);
		for(sum=i=0;i<M;i++)
			PQ.push(A[i].BB),sum+=A[i].BB;
		for(i=M;i<C;i++){
			sv[i]=sum;
			PQ.push(A[i].BB),sum+=A[i].BB;
			sum-=PQ.top();
			PQ.pop();
		}
		while(!PQ.empty())PQ.pop();
		for(sum=0,i=C-1;i>=C-M;i--)
			PQ.push(A[i].BB),sum+=A[i].BB;
		int ans=-1;
		while(i>=M){
			if(sum+sv[i]+A[i].BB<=F){
				ans=A[i].AA;
				break;
			}
			PQ.push(A[i].BB),sum+=A[i].BB;
			sum-=PQ.top();
			PQ.pop();
			i--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
