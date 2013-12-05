//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#define ll long long
#define mod 1000000007LL
using namespace std;
int a[105][15];
ll dp[2][1200][25];
char s[30];
int main() {
	int n,m,c,d,i,j,k;
	while (scanf ("%d%d%d%d",&n,&m,&c,&d) !=EOF) {
		for (i = 0; i<n; i++) {
			scanf ("%s",s);
			for (j = 0; j<m; j++)
				a[i][j] = s[j]-'0';
		}
		memset (dp[1],0,sizeof (dp[1]));
		dp[1][ (1<<m)-1][0] = 1LL;
		for (i = 0; i<n*m; i++) {
			int x = (i+1) &1,y = 1-x;
			memset (dp[y],0,sizeof (dp[y]));
			for (j = 0; j< (1<<m); j++) {
				for (k = 0; k<=d; k++) {
					int xx = i/m,yy = i%m;
					int up = j& (1<<yy);
					if (a[xx][yy] == 0) {
						if (up||xx==0) {
							dp[y][j][k]+=dp[x][j][k];
							dp[y][j][k]%=mod;
						}
					} else {
						if (yy) {
							int lt = j& (1<< (yy-1));
							if ( (!lt) && (up||xx==0)) {
								dp[y][j| (1<< (yy-1)) | (1<<yy)][k]+=dp[x][j][k];
								dp[y][j| (1<< (yy-1)) | (1<<yy)][k]%=mod;
							}
						}
						if ( (!up) &&xx) {
							dp[y][j| (1<<yy)][k]+=dp[x][j][k];
							dp[y][j| (1<<yy)][k]%=mod;
						}
						if (up) {
							dp[y][j| (1<<yy)][k+1]+=dp[x][j][k];
							dp[y][j| (1<<yy)][k+1]%=mod;
						}
						if (up) {
							dp[y][j- (1<<yy)][k]+=dp[x][j][k];
							dp[y][j- (1<<yy)][k]%=mod;
						}
					}
				}
			}
		}
		ll ans = 0LL;
		int now = 1- (n*m) &1;
		for (i = c; i<=d; i++)
			ans = (ans+dp[now][ (1<<m)-1][i]) %mod;
		printf ("%I64d\n",ans);
	}
	return 0;
}
