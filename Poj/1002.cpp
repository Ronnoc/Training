#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int map[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
vector<int>L;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i;
		L.clear();
		char s[1010];
		for(i=1;i<=n;i++){
			scanf("%s",s);
			int j,len=strlen(s);
			int res=0;
			for(j=0;j<len;j++){
				if(s[j]>='0'&&s[j]<='9'){
					res*=10;
					res+=s[j]-'0';
					}
				if(s[j]<'Z'&&s[j]>='A'&&s[j]!='Q'){
					res*=10;
					res+=map[s[j]-'A'];
					}
				}
			L.push_back(res);
			}
		sort(L.begin(),L.end());
		int sum=0,tp=-1;
		int flag=0;
		for(i=0;i<=L.size();i++){
			if(L[i]==tp)sum++;
			else {
				if(sum>1)flag=1,printf("%03d-%04d %d\n",tp/10000,tp%10000,sum);
				sum=1;
				tp=L[i];
				}
			}
		if(!flag)printf("No duplicates.\n"); 
	/*	for(i=0;i<L.size();i++){
			printf("%03d-%04d\n",L[i]/10000,L[i]%10000);
			}		*/
		}
	return 0;
	}
