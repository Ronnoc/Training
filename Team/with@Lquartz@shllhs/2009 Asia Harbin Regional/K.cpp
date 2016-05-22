//kybconnor
#include <cstdio>
#include <cstring>
int main() {
	char s[1111];
	while (gets (s) !=NULL) {
		int len=strlen (s);
		int i;
		int tot=0;
		for (i=0; i<len; i++) if (s[i]>='A'&&s[i]<='Z')
				tot+=s[i]-'A'+1;
		if (tot<=100) printf ("%d\n",tot);
		else printf ("INVALID\n");
	}
	return 0;
}
