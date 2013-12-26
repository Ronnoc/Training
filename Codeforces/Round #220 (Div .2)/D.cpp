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
int BIT[1000011];
int a[1000011];
const int sz=1000010;
int n;
int LB (int x) {return x& (-x);}
void add (int h,int dlt) {
	h+=3;
	for (; h<sz; h+=LB (h)) BIT[h]+=dlt;
}
int get (int h) {
	h+=3;
	int ret=0;
	while (h>0) {
		ret+=BIT[h];
		h-=LB (h);
	}
	return ret;
}
int pp[1000011];
void solve() {
	int n,m;
	while (scanf ("%d%d",&n,&m) !=EOF) {
		int i,j;
		for (i=1; i<=m; i++) scanf ("%d",&pp[i]);
		memset (BIT,0,sizeof BIT);
		int bk=0,tot=0;
		for (i=1; i<=n; i++) {
			int q;
			scanf ("%d",&q);
			if (q<0) {
				int id=upper_bound (pp+1,pp+m+1,tot)-pp;
				for (j=id-1; j>=1; j--) {
					int l=1,r=bk,ans=-1;
					while (l<=r) {
						if (r-l<=1) {
							int fm=get (l);
							if (fm==pp[j])
								ans=l;
							else {
								fm=get (r);
								if (fm==pp[j]) ans=r;
							}
							break;
						}
						int mid= (l+r) /2;
						int fm=get (mid);
						if (fm>=pp[j]) r=mid;
						else l=mid;
					}
					if (ans!=-1) {
						add (ans,-1);
						tot--;
					}
				}
			} else {
				bk++;
				tot++;
				add (bk,1);
				a[bk]=q;
			}
		}
//      for(i=1;i<=bk;i++){
//          cout<<get(i)-get(i-1)<<" ";
//      }
//      cout<<endl;
		int flag=0;
		for (i=1; i<=bk; i++) if (get (i)-get (i-1)) cout<<a[i],flag=1;
		cout<<endl;
		if (!flag) cout<<"Poor stack!\n";
	}
}
int main() {
//  while(1)
	solve();
	return 0;
}
