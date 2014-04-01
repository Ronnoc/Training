#include<stdio.h>
#include<string.h>
char a[1000010],b[1000010],c[1000010];
int main()
{
//	freopen("out.txt","w",stdout);
//	printf("!");
	int k,z;
	scanf("%d",&z);
//	printf("!");
	for(k=1;k<=z;k++)
	{
	//s	char a[1000010],b[1000010],c[1000010];
		int i;
	for(i=0;i<=1000000;i++){a[i]=b[i]=c[i]='\0';}
		int n;
		scanf("%d",&n);
		for(i=n-1;i>=0;i--)
		{
			int p,q;
			scanf("%d%d",&p,&q);
			a[i]=p+'0';
			b[i]=q+'0';
			}
//		puts(a);puts(b);
	//	puts(a);puts(b);
		for(i=0;i<=n;i++)c[i]='0';
		for(i=0;i<n;i++){c[i]+=a[i]-'0'+b[i]-'0';if(c[i]>=10+'0'){c[i]-=10;c[i+1]++;}}
//puts(c);
	//	strrev(c);
		if(c[strlen(c)-1]!='0'){for(i=strlen(c)-1;i>=0;i--)printf("%c",c[i]);}
		else {for(i=n-1;i>=0;i--)printf("%c",c[i]);}
		printf("\n");
		if(k!=z)printf("\n");
		}
//	return main();
	return 0;
	} 
