/*
看了discuss才明白哪里错了
果然是浪了
自己以为循环节在x=1处恰好出现
但是事实并不是这样
并不是直接取个mod len就能ac的说
2013-10-28
*/
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

LL to[1111];
LL x[3333];
int vis[1111];
int main(){
	LL A,al,be,ga,m,k;
	while(cin>>A>>al>>be>>ga>>m>>k){
		if(k==0){cout<<A<<endl;continue;}
		memset(vis,-1,sizeof vis);
		LL i;
		for(i=0;i<m;i++)to[i]=(al*i*i+be*i+ga)%m;
		x[0]=A;
		for(i=1;i<3000;i++)x[i]=to[x[i-1]%m];
		if(k<3*m){cout<<x[k]<<endl;continue;}
		int len,x0;
		for(i=1;i<3000;i++){
			if(vis[x[i]]==-1)vis[x[i]]=i;
			else {len=i-vis[x[i]],x0=vis[x[i]];break;}
		}
//		cout<<len<<" "<<x0<<endl;
		k=(k-x0)%len+x0;
		cout<<x[k]<<endl;
	}
	return 0;
}
