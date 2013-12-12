//kybconnor
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctype.h>
using namespace std;
char ini[111];
int F[512];
int main() {
	memset (F,-1,sizeof F);
	F['(']=10; F[')']=-10;
	F['[']=20; F[']']=-20;
	F['{']=30; F['}']=-30;
	while (gets (ini) !=NULL) {
		int len=strlen (ini),i,j;
		string s[50];
		string ans="";
		for (i=0; i<len;) {
			if (ini[i]=='('||ini[i]=='['||ini[i]=='{') {
				for (j=10; j<=30; j+=10) s[j].clear();
				int tot=0;
				while (tot<3) {
					while (ini[i]==' ') i++;
					for (j=i+1; F[ini[j]]!=-F[ini[i]]; j++)
						s[F[ini[i]]]+=ini[j];
					tot++;
					i=j+1;
				}
				ans+=s[30]+" "+s[10]+" "+s[20];
			} else
				ans+=ini[i++];
		}
		for (i=1; i<ans.size(); i++) if (ans[i]<='Z'&&ans[i]>='A')
				ans[i]=ans[i]-'A'+'a';
		if (ans[0]<='z'&&ans[0]>='a')
			ans[0]=ans[0]-'a'+'A';
		cout<<ans<<endl;
	}
	return 0;
}
/*
{Truly wonderful} (the mind of a child) [is]
(the mind of a child) {Truly wonderful} [is]
{Truly wonderful} [is] (the mind of a child)
*/
