#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int main(){
	int a[10],i;
	for(i=1;i<=5;i++)a[i]=i;
	int tot=0;
	do{
		int flag=1;
		for(i=1;i<=5;i++)if(a[i]==i)flag=0;
		if(a[2]!=4)flag=0;
		tot+=flag;
		if(flag){for(i=1;i<=5;i++)cout<<"~"<<a[i];cout<<endl;}
	}while(next_permutation(a+1,a+6));
	cout<<tot<<endl;
return 0;
}
