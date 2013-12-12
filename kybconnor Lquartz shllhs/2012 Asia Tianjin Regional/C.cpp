//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#define inf 0x7f7f7f7f
using namespace std;
char a[1055],b[1055];
int dp[1055][12][12];
int main() {
	while (scanf ("%s %s",a,b) !=EOF) {
		int i,j,k,p,q;
		int l = strlen (a);
		a[l] = '0';
		a[l+1] = '0';
		a[l+2] = '\0';
		b[l] = '0';
		b[l+1] = '0';
		b[l+2] = '\0';
		memset (dp,0x7f,sizeof (dp));
		dp[0][a[0]-'0'][a[1]-'0'] = 0;
		for (i = 0; i<l; i++) {
			int i0 = i, i1 = i + 1, i2 = i + 2;
			for (j = 0; j<=9; j++) {
				for (k = 0; k<=9; k++) {
					if (dp[i0][j][k] == inf) continue;
					int up = ( (b[i0]-'0')-j+10) %10;
					int down = (j- (b[i0]-'0') +10) %10;
					for (p = 0; p<=up; p++) {
						for (q = 0; q<=p; q++) {
							int jj = (k+p) %10;
							int kk = (a[i2]-'0'+q) %10;
							dp[i1][jj][kk] = min (dp[i1][jj][kk],dp[i0][j][k]+up);
						}
					}
					for (p = 0; p<=down; p++) {
						for (q = 0; q<=p; q++) {
							int jj = (k-p+10) %10;
							int kk = (a[i2]-'0'-q+10) %10;
							dp[i1][jj][kk] = min (dp[i1][jj][kk],dp[i0][j][k]+down);
						}
					}
				}
			}
		}
		int ans = inf;
		for (i = 0; i<10; i++)
			for (j = 0; j<10; j++)
				ans = min (ans,dp[l][i][j]);
		printf ("%d\n",ans);
	}
	return 0;
}
