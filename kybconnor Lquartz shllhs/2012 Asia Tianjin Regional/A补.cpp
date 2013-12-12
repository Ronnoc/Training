//kybconnor
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define AA first
#define BB second
int all[5][10];
char e[5];
int E[512];
int UB[5]= {7,9,9,9,9};
bool spj1() {
	int i,j;
	int tot=0;
		for (i=1; i<=3; i++) if (all[i][1]==0) return 0; else tot+=all[i][1];
		for (i=1; i<=3; i++) if (all[i][9]==0) return 0; else tot+=all[i][9];
		for (j=1; j<=7; j++) if (all[0][j]==0) return 0; else tot+=all[0][j];
	return tot==14;
}
bool spj2() {
	int i,j;
	for (j=1; j<=7; j++) if (all[0][j]!=2&&all[0][j]) return 0;
	for (i=1; i<=3; i++) for (j=1; j<=9; j++) if (all[i][j]!=2&&all[i][j]) return 0;
	return 1;
}
bool can (int *a) {
	int b[11],i;
	for (i=1; i<=9; i++)
		b[i]=a[i];
	for (i=1; i<=7; i++) {
		if (b[i]==3) continue;
		if (b[i]==0) continue;
		while (b[i]&&b[i+1]&&b[i+2]&&b[i]!=3)
			b[i]--,b[i+1]--,b[i+2]--;
	}
	for (i=1; i<=9; i++)
		if (b[i]!=0&&b[i]!=3) return 0;
	return 1;
}
bool check() {
	if (spj1()) return 1;
	if (spj2()) return 1;
	int tot[5],i,j;
	vector<int>P[4];
	for (i=0; i<4; i++) {
		tot[i]=0;
		for (j=1; j<=UB[i]; j++) tot[i]+=all[i][j];
		P[tot[i]%3].push_back (i);
	}
	if (P[2].size() !=1) return 0;
	if (P[1].size() !=0) return 0;
	int id=P[2][0],p;
	if (id) {
		int flag=0;
		for (i=1; i<=9; i++)
			if (all[id][i]>=2) {
				all[id][i]-=2;
				if (can (all[id])) flag=1;
				all[id][i]+=2;
			}
		if (!flag) return 0;
	} else {
		int has2=0;
		for (j=1; j<=7; j++) if (all[0][j]==2) has2++;
		for (j=1; j<=7; j++) if (all[0][j]==1||all[0][j]==4) return 0;
		if (has2!=1) return 0;
	}
	for (p=0; p<P[0].size(); p++) {
		id=P[0][p];
		if (id) {
			if (!can (all[id])) return 0;
		} else
			for (j=1; j<=7; j++) if (all[0][j]!=3&&all[0][j]!=0) return 0;
	}
	return 1;
}
int main() {
	int T,i,j;
	scanf ("%d",&T);
	E['m']=1; e[1]='m';
	E['s']=2; e[2]='s';
	E['p']=3; e[3]='p';
	E['c']=0; e[0]='c';
	while (T--) {
		memset (all,0,sizeof all);
		for (i=1; i<=13; i++) {
			char s[11];
			scanf ("%s",s);
			all[ E[s[1]] ][ s[0]-'0' ]++;
		}
		vector<pair<int,int> >ANS;
		for (i=1; i<=3; i++) for (j=1; j<=9; j++) if (all[i][j]<4) {
					all[i][j]++;
					if (check()) ANS.push_back (make_pair (i,j));
					all[i][j]--;
				}
		for (j=1; j<=7; j++) if (all[0][j]<4) {
				all[0][j]++;
				if (check()) ANS.push_back (make_pair (0,j));
				all[0][j]--;
			}
		if (ANS.size() >0) {
			printf ("%d",ANS.size());
			for (i=0; i<ANS.size(); i++)
				printf (" %d%c",ANS[i].BB,e[ ANS[i].AA ]);
			printf ("\n");
		} else printf ("Nooten\n");
	}
	return 0;
}
/*
1
1s 1s 1s 1s 2s 2s 2s 2s 3s 3s 4s 4s 5s
*/
