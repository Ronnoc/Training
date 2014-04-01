#include<stdio.h>
int f(char s){
	if(s=='A')return 0;	
	if(s=='E')return 0;	
	if(s=='I')return 0;	
	if(s=='O')return 0;	
	if(s=='U')return 0;	
	return 1;
	}
int main(){
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		int n,i,j;
		int l,r;
		scanf("%d",&n);
		r=n/2;
		l=(n+1)/2;		//l是元音个数,r是辅音个数 
		char yuan[]="AUEOI";
		int num[26],pyu=0;
		for(i=0;i<26;i++)num[i]=0;
		for(i=0;i<l;i++){
			num[yuan[pyu]-'A']++;
			if(num[yuan[pyu]-'A']==21)pyu++;
			}
		char fu[]="JSBKTCLDMVNWFXGPYHQZR";
		int pfu=0;
		for(i=1;i<=r;i++){
			num[fu[pfu]-'A']++;
			if(num[fu[pfu]-'A']==5)pfu++;
			}
		printf("Case %d: ",k);
		for(i=1;i<=n;i++){
			int aim;
			if(i%2==1)aim=0;
			else aim=1;
			for(j=0;j<26;j++){
				if(aim==f('A'+j)){
					if(num[j]){
						printf("%c",'A'+j);
						num[j]--;
						break;
						}
					}
				}
			}printf("\n");
		}
	return 0;
	} 
