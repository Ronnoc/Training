**1 JAVA I/O**
>based on Petr's template

	import java.io.BufferedReader;
	import java.io.IOException;
	import java.io.InputStreamReader;
	import java.io.PrintWriter;
	import java.math.BigInteger;
	import java.util.StringTokenizer;
	
	public class Main {
		
		public void Solve() throws IOException {
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
				// reader = new BufferedReader(new InputStreamReader(new
				// FileInputStream("journey.in")));
				// writer = new PrintWriter(new FileOutputStream("journey.out"));
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


**2 栈空间**

	#pragma comment(linker, "/STACK:1024000000,1024000000")
    int size = 256<<20;	//256MB
    char *p = (char*)malloc(size) + size;
    __asm__("movl %0, %%esp\n" :: "r"(p) );
