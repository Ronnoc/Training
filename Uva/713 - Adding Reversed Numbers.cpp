#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b 
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		char a[1000];
		char b[1000];
		scanf("%s %s",a,b);
		int la=strlen(a),lb=strlen(b);
		int len=max(la,lb),i;
		for(i=la;i<len;i++)a[i]='0';a[len]='\0';
		for(i=lb;i<len;i++)b[i]='0';b[len]='\0';
		char o[1000];
		for(i=0;i<=len;i++)
		{
			o[i]='0';
			}
		for(i=0;i<len;i++)
		{
			o[i]+=a[i]+b[i]-'0'-'0';
			if(o[i]>='0'+10)
			{
				o[i]-=10;
				o[i+1]+=1;
				}
			}	
		int head=-1,tail=-1;
	//	puts(o);
		for(i=0;i<=len;i++)
		{
			if(head==-1&&o[i]!='0')head=i;
			if(head!=-1&&o[i]!='0')tail=max(tail,i);
	//		printf("%d:%d %d\n",i,head,tail);
			}
		for(i=head;i<=tail;i++)printf("%c",o[i]);
		printf("\n");
		} 
	return 0;
	}
