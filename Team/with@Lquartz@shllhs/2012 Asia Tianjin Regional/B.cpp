//kybconnor
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
set<int>S;
set<int>::iterator iter;
string to (int x,int m) {
	string ret="";
	while (x) {
		int ths=x%m;
		if (ths<10) ret+='0'+ths;
		else ret+='A'+ths-10;
		x/=m;
	}
	reverse (ret.begin(),ret.end());
	return ret;
}
int main() {
	int n,m;
	while (scanf ("%d%d",&n,&m) !=EOF) {
		S.clear();
		int i;
		for (i=1; i*i<=n; i++)
			if (n%i==0) S.insert (i),S.insert (n/i);
		int res=0;
		for (iter=S.begin(); iter!=S.end(); ++iter) {
			string s=to (*iter,m);
			for (i=0; i<s.size(); i++)
				if (s[i]<='9'&&s[i]>='0') res+= (s[i]-'0') * (s[i]-'0');
				else res+= (s[i]-'A'+10) * (s[i]-'A'+10);
		}
		string ans=to (res,m);
		printf ("%s\n",ans.c_str());
	}
	return 0;
}
