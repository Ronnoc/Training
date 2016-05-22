//kybconnor
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
char s[4111];
int main() {
//	freopen("o.txt","w",stdout);
	while (gets (s) !=NULL) {
		int len=strlen (s);
		int i,j;
//		for (i=0; i<len; i++) {
//			if (s[i]>='a'&&s[i]<='z')
//				s[i]=s[i]-'a'+'A';
//			else if (s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
//		}
//		printf ("%s\n",s);
		for (i=0; i<len; i+=16) {
			printf ("%04x: ",i);
			char t[111];
			string tp="";
			for (j=0; i+j<len&&j<16; j++) {
				sprintf (t,"%2x",s[i+j]);
				tp+=t;
				if (j&1) tp+=" ";
			}
			while (tp.size() <40) tp+=" ";
			for (j=0; j<tp.size(); j++)
				printf ("%c",tp[j]);
			for (j=0; i+j<len&&j<16; j++) {
				if (s[i+j]>='a'&&s[i+j]<='z')
					s[i+j]=s[i+j]-'a'+'A';
				else if (s[i+j]>='A'&&s[i+j]<='Z') s[i+j]=s[i+j]-'A'+'a';
				printf ("%c",s[i+j]);
			}
			printf ("\n");
		}
	}
	return 0;
}
