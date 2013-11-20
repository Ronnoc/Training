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
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int vis[55][500005];
int sum[500005];
int one[55];
void solve(){
	int n,d;
	while(cin>>n>>d){
		vector<int>C;
		int i,x,j;
		memset(vis,0,sizeof vis);
		memset(sum,0,sizeof sum);
		memset(one,0,sizeof one);
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			C.PB(x);
		}
		SORT(C);
		one[0]=C[0];
		for(i=1;i<C.SZ;i++)one[i]=one[i-1]+C[i];
		vis[0][0]=1;
		for(i=0;i<n;i++)
			for(j=0;j<=i*10000;j++)
				if(vis[i][j])vis[i+1][j+C[i]]=1,vis[i+1][j]=1;
		vector<int>L;
		vector<int>::iterator iter;
		for(i=0;i<=n*10000;i++)if(vis[n][i])L.PB(i);//,cout<<i<<endl;
		int now=0,tot=0;
		while(1){
			int l=0,r=L.SZ-1;
			int h;
			while(r>=l){
				if(r-l<=1){
					if(L[r]-now<=d)h=r;
					else if(L[l]-now<=d)h=l;
					else h=-1;
					break;
				}
				int mid=(l+r)>>1;
				if(L[mid]-now>d)r=mid;
				else l=mid;
			}
			if(h==-1)break;
			if(L[h]>now)now=L[h];
			else break;
			tot++;
		}
		cout<<now<<" "<<tot<<endl;
	}
}
int main(){
//	while(1)		
		solve();
	return 0;
}
/*
3 2
1 3 10
3 5
1 2 3
10 10000
10000 9999 1 10000 10000 10000 1 2 3 4
*/
