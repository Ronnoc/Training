#include<stdio.h>
#include<string.h>
int a[1010],g[1010],c[1010],t[1010];
int main(){
	int z;
	scanf("%d",&z);
	while(z--){
		int m,n,i,j;
		scanf("%d%d",&m,&n);
		char map[60][1010];
		for(i=0;i<m;i++)scanf("%s",map[i]);
		for(i=0;i<n;i++){
			a[i]=0;g[i]=0;c[i]=0;t[i]=0;
			}
		char res[1010];
		int ans=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(map[j][i]=='A')a[i]++;
				if(map[j][i]=='G')g[i]++;
				if(map[j][i]=='C')c[i]++;
				if(map[j][i]=='T')t[i]++;
				}
			int max=0;
			if(a[i]>max)max=a[i];
			if(g[i]>max)max=g[i];
			if(c[i]>max)max=c[i];
			if(t[i]>max)max=t[i];
			if(a[i]==max){res[i]='A';ans+=c[i]+g[i]+t[i];continue;}
			if(c[i]==max){res[i]='C';ans+=a[i]+g[i]+t[i];continue;}
			if(g[i]==max){res[i]='G';ans+=c[i]+a[i]+t[i];continue;}
			if(t[i]==max){res[i]='T';ans+=c[i]+g[i]+a[i];continue;}
			}
		res[n]='\0'; 
		printf("%s\n",res);
		printf("%d\n",ans);
		}
	return 0;
	}
