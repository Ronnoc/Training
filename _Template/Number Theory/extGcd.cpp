//扩展欧几里得
//>ax+by==gcd(a,b)的解
//>验题: poj1061

LL extGcd (LL a, LL b, LL &x, LL &y) {
	LL ret = a;
	if (b) {
		ret = extGcd (b, a % b, y, x);
		y -= (a / b) * x;
	} else x = 1, y = 0;
	return ret;
}