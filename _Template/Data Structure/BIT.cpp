inline int LB(int x) {return x & (-x);}
struct BIT {
	LL _[MXN+5];
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
		int ans=0,cnt=0;
		for(int i=22;i>=0;i--){
			ans+=1<<i;
			if(ans>=n||cnt+_[ans]>=k)ans-=1<<i;
			else cnt+=_[ans];
		}
		return ans - 2;
	}
} Y;