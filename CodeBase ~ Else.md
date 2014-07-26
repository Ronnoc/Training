**1 JAVA I/O**
>based on Petr's template

	public class Main implements Runnable {
		public static void main( String[] args ) {
			new Main().run();
		}
		BufferedReader reader;
		StringTokenizer tokenizer;
		PrintWriter writer;
		public void run() {
			try {
				reader = new BufferedReader( new InputStreamReader( System.in ) );
				tokenizer = null;
				writer = new PrintWriter( System.out );
				solve();
				reader.close();
				writer.flush();
				writer.close();
			} catch ( Exception e ) {
				e.printStackTrace();
				System.exit( 1 );
			}
		}
		
		boolean hasNext() throws IOException {
			while ( tokenizer == null || !tokenizer.hasMoreTokens() ) {
				String nextLine = reader.readLine();
				if ( nextLine == null )
					return false;
				tokenizer = new StringTokenizer( nextLine );
			}
			return true;
		}
		
		int nextInt() throws IOException {
			return Integer.parseInt( nextToken() );
		}
		
		long nextLong() throws IOException {
			return Long.parseLong( nextToken() );
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble( nextToken() );
		}
		
		String nextLine() throws IOException {
			return reader.readLine();
		}
		
		String nextToken() throws IOException {
			while ( tokenizer == null || !tokenizer.hasMoreTokens() ) {
				tokenizer = new StringTokenizer( reader.readLine() );
			}
			return tokenizer.nextToken();
		}
		
		BigInteger nextBigInteger() throws IOException {
			while ( tokenizer == null || !tokenizer.hasMoreTokens() ) {
				tokenizer = new StringTokenizer( reader.readLine() );
			}
			return new BigInteger( tokenizer.nextToken() );
		}
	}

**2 栈空间**

    int size = 256<<20;	//256MB
    char *p = (char*)malloc(size) + size;
    __asm__("movl %0, %%esp\n" :: "r"(p) );
