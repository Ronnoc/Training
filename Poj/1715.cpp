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

LL f(int len){
	LL ret=15;
	len--;
	LL mul=15;
	while(len--){
		ret*=mul;
		mul--;
	}
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,m,T;
	LL n;
	while(~scanf("%I64d",&n)){
		vector<char>L;
		for(i='F';i>='A';--i)L.PB(i);
		for(i='9';i>='1';--i)L.PB(i);
		int len=8;
		n--;
		while(len>=1&&f(len)<=n){
			n-=f(len);
			len--;
		}
		for(i=0;i<len;i++){
			LL gt=0,add=1;
			int cnt=L.SZ-1;
			if(!i)cnt++;
			int remain=len-i-1;
			while(remain--){
				add*=cnt;
				cnt--;
			}
			for(j=0;j<L.SZ;j++){
				if(gt+add>n){
					putchar(L[j]);
					L.erase(L.OP+j);
					n-=gt;
					break;
				}else gt+=add;
			}
			if(!i)L.PB('0');
		}
		if(len==0)putchar('0');
		putchar('\n');
	}
	return 0;
}
