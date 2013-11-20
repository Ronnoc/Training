//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#define N 50500
using namespace std;
int a[N],b[N];
char s[N];
int n;
int lowbit (int x) {
	return x&-x;
}
void update (int x,int u) {
	while (x<=n) {
		b[x]+=u;
		x+=lowbit (x);
	}
}
int query (int x) {
	int ret = 0;
	while (x) {
		ret+=b[x];
		x-=lowbit (x);
	}
	return ret;
}
int ok (int x) {
	if (x>1&&x<n) if (a[x-1] == 1&&a[x] == 0&&a[x+1] == 1) return 1;
	return 0;
}
int get (int l,int r) {
	if (r-l<2) return 0;
	int ret = query (r)-query (l-1);
	return ret-ok (l)-ok (r);
}
int main() {
	int t,m,i,j,cas = 1;
	scanf ("%d",&t);
	while (t--) {
		scanf ("%d%d",&n,&m);
		scanf ("%s",s);
		printf ("Case %d:\n",cas++);
		for (i = 1; i<=n; i++) {
			if (s[i-1] == 'w') a[i] = 1;
			else a[i] = 0;
		}
		memset (b,0,sizeof (b));
		for (i = 2; i<n; i++) {
			if (a[i-1] == 1&&a[i] == 0&&a[i+1] == 1)
				update (i,1);
		}
		for (i = 1; i<=m; i++) {
			int x,y,z;
			scanf ("%d",&x);
			if (x == 0) {
				scanf ("%d%d",&y,&z);
				printf ("%d\n",get (y+1,z+1));
			} else {
				char op[2];
				scanf ("%d%s",&y,op);
				y++;
				int x1 = ok (y);
				int x2 = ok (y+1);
				int x3 = ok (y-1);
				a[y] = op[0] == 'w'?1:0;
				
				int y1 = ok (y);
				int y2 = ok (y+1);
				int y3 = ok (y-1);
				
				update (y,y1-x1);
				if (y<n)
					update (y+1,y2-x2);
				if (y>1)
					update (y-1,y3-x3);
			}
		}
	}
	return 0;
}
