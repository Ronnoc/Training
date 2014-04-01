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
char s[1000000];
int main(){
	while(gets(s)){
		if(strcmp("ENDOFINPUT",s)==0)break;
		while(gets(s)){
			if(strcmp(s,"END")==0)break;
			int i,len=strlen(s);
			for(i=0;i<len;i++){
				if(s[i]<='Z'&&s[i]>='A'){
					s[i]-=5;
					if(s[i]<'A')s[i]+=26;
				}
			}
			puts(s);
		}
	}
	return 0;
}
