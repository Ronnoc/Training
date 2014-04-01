#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<char ,char > >L;
int main(){
	char s[100];
	while(scanf("%s",s)!=EOF)
	{
		if(strcmp(s,"*")==0)break;
		int len=strlen(s);
		int flag=0;
		for(int i=1;i<len;i++)
		{
			L.clear();
			for(int j=0;j+i<len;j++)L.push_back(make_pair(s[j],s[j+i]));
			sort(L.begin(),L.end());
			for(int i=1;i<L.size();i++)if(L[i]==L[i-1])flag=1;
		}
		if(flag)printf("%s is NOT surprising.\n",s);
		else printf("%s is surprising.\n",s);
	}
	return 0;
}
