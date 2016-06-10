#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;

class FoxSequence {
public:
	string isValid(vector <int>);
};

string FoxSequence::isValid(vector <int> s) {
	vector<int>c,tp;
	int i,n=s.size();
	for(i=1;i<n;i++)c.push_back(s[i]-s[i-1]);
//	for(i=0;i<c.size();i++)tp.push_back(c[i]);
//	sort(tp.begin(),tp.end());
//	tp.erase(unique(tp.begin(),tp.end()),tp.end());
	string yes="YES",no="NO";
//	if(tp.size()>5||tp.size()<4)return no;
//	cout<<"<<"<<" past tp\n";
	int flag[60];
	for(i=0;i<c.size();i++)flag[i]=0;
	for(i=1;i<c.size();i++)if(c[i]==c[i-1])flag[i]=1;
	vector<int>p;
	for(i=0;i<c.size();i++)if(!flag[i])p.push_back(c[i]);
	if(p.size()>5||p.size()<4)return no;
	cout<<"<<"<<" past p\n";
	if(p.size()==4&&p[0]>0&&p[1]<0&&p[2]>0&&p[3]<0)return yes;
	if(p.size()==5&&p[0]>0&&p[1]<0&&p[2]==0&&p[3]>0&&p[4]<0)return yes;
	cout<<"<<"<<" fall p 4 or 5\n";
	return no;
	}
