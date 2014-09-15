import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
	
	public void Solve() throws IOException {
		BigInteger LIM = BigInteger.valueOf(10).pow(100);
		BigInteger[] Fib = new BigInteger[500];
		Fib[1] = Fib[0] = BigInteger.valueOf(1);
		for (int i = 1; Fib[i].compareTo(LIM) < 0; i++)
			Fib[i + 1] = Fib[i].add(Fib[i - 1]);
		BigInteger a, b;
		while (hasNext()) {
			a = nextBigInteger();
			b = nextBigInteger();
			if (a.equals(BigInteger.ZERO) && b.equals(BigInteger.ZERO)) break;
			int ans = 0;
			for (int i = 1; Fib[i].compareTo(b) <= 0; i++)
				if (Fib[i].compareTo(a) >= 0) ans++;
			writer.println(ans);
		}
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
			writer = new PrintWriter(System.out);
			tokenizer = null;
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
