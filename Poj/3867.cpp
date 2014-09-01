#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair
int cnt[1111][33];
int temp[33];
string s[1111];
int n,m;
set<char>S;
vector<string>ans;
string zero;
priority_queue<pair<int,string> >Q;
int play (string &ss) {
	int ret=0;
	int i,j;
	memset (temp,0,sizeof temp);
	for (i=0; i<ss.size(); i++) temp[ss[i]-'A']++;
	set<char>::iterator it;
	S.clear();
	for (i=0; i<ss.size(); i++) S.insert (ss[i]);
	for (i=1; i<=m; i++) {
		int able=1;
		for (it=S.begin(); it!=S.end(); ++it) {
			j= (*it)-'A';
			if (temp[j]>cnt[i][j]) able=0;
			if (!able) break;
		}
		if (able) ret++;
	}
	return ret;
}
char ppp[111];
int main() {
//	freopen ("funny.in","r",stdin);
//	freopen ("funny.out","w",stdout);
	int i,j,k;
	while (scanf ("%d %d",&n,&m) !=EOF) {
		memset (cnt,0,sizeof cnt);
		int i;
		for (i=1; i<=m; i++) {
			scanf ("%s",ppp);
			s[i]="";
			int len=strlen (ppp);
			for (j=0; j<len; j++) cnt[i][ppp[j]-'A']++,s[i]+=ppp[j];
		}
		for (i=0; i<26; i++) {
			string ss="";
			ss+=i+'A';
			int pss=play (ss);
			if (pss) Q.push (MP (pss,ss));
			else zero=ss;
		}
		while ( (ans.size() <n+m) &&!Q.empty()) {
			int xx=Q.top().first;
			string now=Q.top().second;
			Q.pop();
			ans.push_back (now);
			if (xx) for (i=0; i<26; i++) {
					string ss=now;
					ss+=i+'A';
					int pss=play (ss);
					if (pss) Q.push (MP (pss,ss));
					else zero=ss;
				}
		}
		int tot=0;
		set<string>T;
		for (i=1; i<=m; i++) T.insert (s[i]);
		for (i=0; tot<n&&i<ans.size(); i++) {
			int ok= T.find (ans[i]) ==T.end();
			if (ok) {
				tot++;
				for (j=0; j<ans[i].size(); j++) printf ("%c",ans[i][j]);
				printf ("\n");
			}
		}
		while (tot<n) {
			for (j=0; j<zero.size(); j++) printf ("%c",zero[j]);
			printf ("\n");
			zero+='A';
			tot++;
		}
	}
	return 0;
}
/*
100 1
AAAABBBB
*/
