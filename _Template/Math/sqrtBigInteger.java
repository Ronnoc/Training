public static BigInteger getsqrt(BigInteger n) {
	if (n.compareTo(BigInteger.ZERO) <= 0) return n;
	BigInteger x, xx, txx;        xx = x = BigInteger.ZERO;
	for (int t = n.bitLength() / 2; t >= 0; t--) {
		txx = xx.add(x.shiftLeft(t + 1)).add(BigInteger.ONE.shiftLeft(t + t));
		if (txx.compareTo(n) <= 0) {
			x = x.add(BigInteger.ONE.shiftLeft(t));   xx = txx;
		}
	}
	return x;
}