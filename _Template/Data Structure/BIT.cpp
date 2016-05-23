inline int LB(int x) {return x & (-x);}
struct BIT {
	LL _[MXN];
	int n;
	void init(int m) {
		n = m + 5;
		for (int i = 0; i <= n; i++)_[i] = 0;
	}
	LL query(int w) {
		LL ret = 0;
		for (w += 3; w > 0; w -= LB(w))ret += _[w];
		return ret;
	}
	void update(int w, LL d) {
		for (w += 3; w < n; w += LB(w))_[w] += d;
	}
	int find_Kth(int k) {		//UESTC_Dagon
		int idx = 0;
		for (int i = 20; i >= 0; i--) {
			idx |= 1 << i;
			if (idx <= n && _[idx] < k)k -= _[idx];
			else idx ^= 1 << i;
		}
		return idx - 2;
	}
} Y;