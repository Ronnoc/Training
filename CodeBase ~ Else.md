#Other#
### 1 日期###
>验题:未验

	//日期函数
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	struct date {
		int year, month, day;
	};
	//判闰年
	int leap (int year) {
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
	//判合法性
	int legal (date a) {
		if (a.month < 0 || a.month > 12)
			return 0;
		if (a.month == 2)
			return a.day > 0 && a.day <= 28 + leap (a.year);
		return a.day > 0 && a.day <= days[a.month - 1];
	}
	//比较日期大小
	int datecmp (date a, date b) {
		if (a.year != b.year)
			return a.year - b.year;
		if (a.month != b.month)
			return a.month - b.month;
		return a.day - b.day;
	}
	//返回指定日期是星期几
	int weekday (date a) {
		int tm = a.month >= 3 ? (a.month - 2) : (a.month + 10);
		int ty = a.month >= 3 ? a.year : (a.year - 1);
		return (ty + ty / 4 - ty / 100 + ty / 400 + (int) (2.6 * tm - 0.2) + a.day) % 7;
	}
	//日期转天数偏移
	int date2int (date a) {
		int ret = a.year * 365 + (a.year - 1) / 4 - (a.year - 1) / 100 + (a.year - 1) / 400, i;
		days[1] += leap (a.year);
		for (i = 0; i < a.month - 1; ret += days[i++]);
		days[1] = 28;
		return ret + a.day;
	}
	//天数偏移转日期
	date int2date (int a) {
		date ret;
		ret.year = a / 146097 * 400;
		for (a %= 146097; a >= 365 + leap (ret.year); a -= 365 + leap (ret.year), ret.year++);
		days[1] += leap (ret.year);
		for (ret.month = 1; a >= days[ret.month - 1]; a -= days[ret.month - 1], ret.month++);
		days[1] = 28;
		ret.day = a + 1;
		return ret;
	}

### 2 字符串最小表示 ###
>验题:未验 poj1509

	//返回：循环同构字符串最小表示的首字母位置(0...size-1)
	int MinString (vector <char> &str) {
		int i, j, k;
		vector <char> ss (str.size() << 1);
		for (i = 0; i < str.size(); i ++) ss[i] = ss[i + str.size()] = str[i];
		for (i = k = 0, j = 1; k < str.size() && i < str.size() && j < str.size();) {
			for (k = 0; k < str.size() && ss[i + k] == ss[j + k]; k ++);
			if (k < str.size()) {
				if (ss[i + k] > ss[j + k])
					i += k + 1;
				else j += k + 1;
				if (i == j) j ++;
			}
		}
		return i < j ? i : j;
	}

### 3 cupid ###
>给定一个有完备匹配的二分图G，问哪些边一定会出现在完备匹配中，哪些边一定不会出现在完备匹配中。N<=200000，M<=600000

	#include <iostream>
	using namespace std;

	const int maxn = 600005;

	int tp[maxn], l[maxn], f[maxn];
	int d[maxn], g[maxn], q[maxn];
	int n, m, p, ps;

	struct edge {
		int s, t, ne;
		bool ok;
		inline void read() {
			scanf ("%d%d", &s, &t);
			t += n;
		}
		inline void add (int i) {
			ne = tp[s];
			tp[s] = i;
		}
		inline void change() {
			if (ok = g[t] == s) swap (s, t);
		}
		inline char ck() {
	return f[s] != f[t] ? ok ? '1' : '2' : '0';
		}
	} e[maxn];

	bool bfs() {
		memset (&d[1], 0, n << 3);
		int ff = 0, rr = 0, ret = 0;
		for (int i = 1; i <= n; ++i)
			if (!g[i]) q[++rr] = i;
		while (ff < rr) {
			int i = q[++ff];
			if (i > n) d[q[++rr] = g[i]] = d[i] + 1;
			else
				for (int j = tp[i]; j; j = e[j].ne) {
					int k = e[j].t;
					if (d[k]) continue;
					d[k] = d[i] + 1;
					if (g[k]) q[++rr] = k;
					else ret = 1;
				}
		}
		return ret;
	}

	bool find (int i) {
		for (int j = tp[i]; j; j = e[j].ne) {
			int k = e[j].t;
			if (d[i] + 1 != d[k]) continue;
			d[k] = -1;
			if (!g[k] || find (g[k])) {
				g[i] = k; g[k] = i; return true;
			}
		}
		return false;
	}

	void dfs (int i) {
		int pp = l[i] = ++p;
		q[p] = i;
		for (int j = tp[i]; j; j = e[j].ne) {
			int k = e[j].t;
			if (!l[k]) dfs (k);
			if (!f[k]) l[i] <? = l[k];
		}
		if (l[i] == pp) {
			++ps;
			while (p >= pp) f[q[p--]] = ps;
		}
	}

	int main() {
		cin >> n >> m;
		for (int i = 1; i <= m; ++i)
			e[i].read(), e[i].add (i);
		while (bfs())
			for (int i = 1; i <= n; ++i)
				if (!g[i]) find (i);
		memset (&tp[1], 0, n << 2);
		for (int i = 1; i <= m; ++i)
			e[i].change(), e[i].add (i);
		for (int i = 1; i <= 2 * n; ++i)
			if (!l[i]) dfs (i);
		for (int i = 1; i <= m; ++i)
			printf ("%c", e[i].ck());
		return 0;
	}
