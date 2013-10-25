#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second

typedef long long LL;
typedef pair<int, int> PII;

int main(){
	int T;
	scanf("%d%*c",&T);
	while(T--){
		char s[11111];
		gets(s);
		int i,j,len=strlen(s);
		vector <int>L;
		for(i=0;i<len;i++)if(s[i]!=' ')L.PB(s[i]-'0');
		sort(L.begin(),L.end());
		int x[111];
		for(i=0;i<L.size();i++)x[i]=i;
		if(L.size()==10){
			printf("247\n");
			continue;
		}
		if(L.size()==2){
			printf("%d\n",L[1]-L[0]);
			continue;
		}
		int res=999999999;
		do{
			int p[11],k;
			for(i=0;i<L.size();i++)p[i]=L[x[i]];
			int tp=L.size()/2;
			for(j=max(1,tp-1);j<L.size()&&j<=tp+1;j++){
				if(!p[j-1]||!p[L.size()-1])continue;
				int left=0,right=0;
				for(k=j-1;k>=0;k--)left=left*10+p[k];
				for(k=L.size()-1;k>=j;k--)right=right*10+p[k];
//				cout<<left<<" "<<right<<endl;
				res=min(res,left>right?left-right:right-left);
			}
		}while(next_permutation(x,x+L.size()));
		printf("%d\n",res);
	}
	return 0;
}
