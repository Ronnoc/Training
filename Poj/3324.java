import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
	
	BigInteger play(BigInteger a, BigInteger mod, int n) {
		if (a.compareTo(mod) < 0) return a;
		if (a.compareTo(mod) == 0) return BigInteger.ZERO;
		BigInteger now = a.and(mod);
		BigInteger dir = play(a.shiftRight(n), mod, n);
		return play(now.add(dir), mod, n);
	}
	
	public void Solve() throws IOException {
		int n = nextInt();
		BigInteger MOD = BigInteger.ONE.shiftLeft(n).subtract(BigInteger.ONE);
		BigInteger now = BigInteger.valueOf(4).mod(MOD);
		for (int i = 1; i <= n - 2; i++)
			now = play(now.multiply(now).subtract(BigInteger.valueOf(2)), MOD, n);
		int[] a = new int[8192];
		int na = 0;
		while (now.compareTo(BigInteger.ZERO) > 0) {
			a[na++] = now.and(BigInteger.valueOf(15)).intValue();
			now = now.shiftRight(4);
		}
		if (na == 0) a[na++] = 0;
		for (int i = na - 1; i >= 0; i--) {
			int tp = a[i];
			if (tp < 10) writer.printf("%c", tp + '0');
			else writer.printf("%c", tp - 10 + 'a');
		}
		writer.println();
	}
	
	BigInteger[] linearMod(BigInteger[] A, BigInteger[] B, BigInteger[] M) {
		BigInteger[] ret = new BigInteger[2];
		int i, n = A.length;
		ret[0] = BigInteger.ZERO;
		ret[1] = BigInteger.ONE;
		for (i = 0; i < n; i++) {
			BigInteger a = A[i].multiply(ret[1]);
			BigInteger b = B[i].subtract(A[i].multiply(ret[0]));
			BigInteger d = M[i].gcd(a);
			if (b.mod(d).compareTo(BigInteger.ZERO) > 0) {
				ret[0] = BigInteger.ZERO;
				ret[1] = BigInteger.valueOf(-1);
				return ret;
			}
			BigInteger md = M[i].divide(d);
			BigInteger t = b.divide(d).multiply(a.divide(d).modInverse(md)).mod(md);
			ret[0] = ret[0].add(ret[1].multiply(t));
			ret[1] = ret[1].multiply(md);
			ret[0] = ret[0].mod(ret[1]);
		}
		return ret;
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
	
	BufferedReader	reader;
	StringTokenizer	tokenizer;
	PrintWriter			writer;
	
	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			while (hasNext())
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
			if (nextLine == null) return false;
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
	
	String nextLine() throws IOException {
		return reader.readLine();
	}
	
	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
	
	BigInteger nextBigInteger() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return new BigInteger(tokenizer.nextToken());
	}
}
