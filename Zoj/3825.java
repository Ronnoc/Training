import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
	
	public class frac {
		
		BigInteger	p, q;
		
		frac () {
			p = BigInteger.ZERO;
			q = BigInteger.ONE;
		}
		
		void init(BigInteger P, BigInteger Q) {
			BigInteger g = P.gcd(Q);
			p = P.divide(g);
			q = Q.divide(g);
			if (q.compareTo(BigInteger.ONE) < 0) {
				p = p.negate();
				q = q.negate();
			}
		}
		
		frac (BigInteger P, BigInteger Q) {
			init(P, Q);
		}
		
		frac (Long P) {
			init(BigInteger.valueOf(P), BigInteger.ONE);
		}
		
		frac negate() {
			frac F = new frac(p.negate(), q);
			return F;
		}
		
		void write() {
			writer.println(p + "/" + q);
			writer.flush();
		}
	}
	
	frac add(frac e, frac f) {
		frac ret = new frac(f.q.multiply(e.p).add(f.p.multiply(e.q)), e.q.multiply(f.q));
		return ret;
	}
	
	frac sub(frac e, frac f) {
		frac F = new frac(f.p.negate(), f.q);
		return add(e, F);
	}
	
	frac mul(frac e, frac f) {
		frac ret = new frac(e.p.multiply(f.p), e.q.multiply(f.q));
		return ret;
	}
	
	frac div(frac e, frac f) {
		frac F = new frac(f.q, f.p);
		return mul(e, F);
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
	
	long	S, xo, yo, ro;
	long	RO;
	long	x1, y1, x2, y2;
	
	long __gcd(long a, long b) {
		if (b != 0)
			return __gcd(b, a % b);
		return a;
	}
	
	long gcd(long a, long b) {
		long g = __gcd(a, b);
		if (g < 0)
			return -g;
		return g;
	}
	
	BigInteger	xg, yg;
	
	BigInteger extGcd(BigInteger a, BigInteger b) {
		BigInteger ret = a;
		if (b.compareTo(BigInteger.ZERO) != 0) {
			ret = extGcd(b, a.mod(b));
			BigInteger tg = xg;
			xg = yg;
			yg = tg.subtract(yg.multiply(a.divide(b)));
		} else {
			xg = BigInteger.ONE;
			yg = BigInteger.ZERO;
		}
		return ret;
	}
	
	BigInteger SQ(BigInteger a) {
		return a.multiply(a);
	}
	
	BigInteger GGG(BigInteger X, BigInteger Y) {
		return SQ(X).add(SQ(Y));
	}
	
	long GGG(long X, long Y) {
		return X * X + Y * Y;
	}
	
	long gao(BigInteger X, BigInteger Y, long dx, long dy) {
		X = X.subtract(BigInteger.valueOf(xo));
		Y = Y.subtract(BigInteger.valueOf(yo));
		BigInteger A = X, B = Y;
		X = BigInteger.valueOf(dx);
		Y = BigInteger.valueOf(dy);
		BigInteger K = (A.multiply(X).add(B.multiply(Y))).negate().divide(GGG(X, Y));
		A = A.add(K.multiply(X));
		B = B.add(K.multiply(Y));
		BigInteger Fl = GGG(A.subtract(X), B.subtract(Y));
		BigInteger Fm = GGG(A, B);
		BigInteger Fr = GGG(A.add(X), B.add(Y));
		BigInteger dis = Fl;
		int ge = -1;
		if (dis.compareTo(Fm) > 0) {
			ge = 0;
			dis = Fm;
		}
		if (dis.compareTo(Fr) > 0) {
			ge = 1;
			dis = Fr;
		}
		A = A.add(BigInteger.valueOf(ge).multiply(X));
		B = B.add(BigInteger.valueOf(ge).multiply(Y));
		if (GGG(A, B).compareTo(BigInteger.valueOf(RO)) > 0)
			return 0L;
		long a = A.longValue();
		long b = B.longValue();
		long i;
		for (i = 1;; i <<= 1)
			if (GGG(a + i * dx, b + i * dy) > RO)
				break;
		i >>= 1;
		long p = 0L;
		while (i > 0) {
			if (GGG(a + (p + i) * dx, b + (p + i) * dy) <= RO)
				p += i;
			else
				i >>= 1;
		}
		for (i = 1;; i <<= 1)
			if (GGG(a - i * dx, b - i * dy) > RO)
				break;
		i >>= 1;
		long q = 0L;
		while (i > 0) {
			if (GGG(a - (q + i) * dx, b - (q + i) * dy) <= RO)
				q += i;
			else
				i >>= 1;
		}
		return 1L + p + q;
	}
	
	long play(frac K, frac F, long dx, long dy) {
		if (K.q.mod(F.q).compareTo(BigInteger.ZERO) != 0)
			return 0L;
		boolean flag = K.p.compareTo(BigInteger.ZERO) > 0;
		if (flag)
			extGcd(K.p, K.q);
		else
			extGcd(K.p.negate(), K.q);
		if (!flag)
			xg = xg.negate();
		BigInteger X = xg;
		X = X.multiply(K.q.negate().divide(F.q).multiply(F.p));
		frac tmp = new frac(X, BigInteger.ONE);
		tmp = add(mul(tmp, K), F);
		return gao(X, tmp.p.divide(tmp.q), dx, dy);
	}
	
	public void Solve() throws IOException {
		int _T = nextInt();
		for (int CA = 1; CA <= _T; CA++) {
			S = nextLong();
			xo = nextLong();
			yo = nextLong();
			ro = nextLong();
			RO = ro * ro;
			x1 = nextLong();
			y1 = nextLong();
			x2 = nextLong();
			y2 = nextLong();
			if (x1 == x2) {
				long tmp;
				tmp = x1;
				x1 = y1;
				y1 = tmp;
				tmp = x2;
				x2 = y2;
				y2 = tmp;
				tmp = xo;
				xo = yo;
				yo = tmp;
			}
			long dx = x2 - x1, dy = y2 - y1;
			long dg = gcd(dx, dy);
			dx /= dg;
			dy /= dg;
			long dl = dx * dx + dy * dy;
			frac pq = new frac(BigInteger.valueOf(S), BigInteger.valueOf(dl).multiply(BigInteger.valueOf(dg)));
			frac fdx = new frac(dx);
			frac fdy = new frac(dy);
			frac X3 = add(new frac(x1), mul(pq, fdy));
			frac Y3 = sub(new frac(y1), mul(pq, fdx));
			frac X4 = sub(new frac(x1), mul(pq, fdy));
			frac Y4 = add(new frac(y1), mul(pq, fdx));
			frac K = div(fdy, fdx);
			frac F1 = sub(Y3, mul(K, X3));
			frac F2 = sub(Y4, mul(K, X4));
			long ans = 0;
			ans += play(K, F1, dx, dy);
			ans += play(K, F2, dx, dy);
			writer.println(ans);
		}
		writer.flush();
	}
	
	BufferedReader	reader;
	StringTokenizer	tokenizer;
	PrintWriter			writer;
	
	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(System.out);
			// reader = new BufferedReader(new InputStreamReader(new
			// FileInputStream("journey.in")));
			// writer = new PrintWriter(new FileOutputStream("journey.out"));
			tokenizer = null;
			Solve();
			reader.close();
			writer.flush();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	boolean hasNext() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			String nextLine = reader.readLine();
			if (nextLine == null)
				return false;
			tokenizer = new StringTokenizer(nextLine);
		}
		return true;
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}
	
	String nextLine() throws IOException {
		return reader.readLine();
	}
	
	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}
