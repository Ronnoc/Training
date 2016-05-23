//线性递推取模最小值
//>验题 : hdu5022
LL getmin(LL start, LL slope, LL cnt, LL mod) {	//min{ (start+k*slope)%mod | 0<=k<=cnt }
	start %= mod;
	if (start + slope * cnt < mod)return start;
	if (start >= slope) {
		int use = (mod - 1 - start) / slope + 1;
		return min(start, getmin(start + use * slope, slope, cnt - use, mod));
	}
	LL res = start;
	LL ns = slope - mod % slope;
	LL ncnt = (start + slope * cnt) / mod;
	return min(res, getmin(start, ns, ncnt, slope));
}