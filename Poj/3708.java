import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main implements Runnable {
	void play(int []a,int [][]g,int [][]v){
		int d=a.length,i,j;
		for(i=0;i<d;i++)for(j=0;j<d;j++)g[i][j]=-1;
		for(i=0;i<d;i++)for(j=0;j<d;j++)v[i][j]=-1;
		int []s=new int[d];
		for(i=0;i<d;i++)s[i]=i;
		for(i=0;i<2*d;i++){
			for(j=0;j<d;j++)
				if(g[j][s[j]]==-1)g[j][s[j]]=i;
				else if(v[j][s[j]]==-1)v[j][s[j]]=i-g[j][s[j]];
			for(j=0;j<d;j++)s[j]=a[s[j]];
		}
	}
	BigInteger[] linearMod(BigInteger []A,BigInteger[]B,BigInteger[]M){
		BigInteger[]ret=new BigInteger[2];
		int i,n=A.length;
		ret[0]=BigInteger.ZERO;
		ret[1]=BigInteger.ONE;
		for(i=0;i<n;i++){
			BigInteger a=A[i].multiply(ret[1]);
			BigInteger b=B[i].subtract(A[i].multiply(ret[0]));
			BigInteger d=M[i].gcd(a);
			if(b.mod(d).compareTo(BigInteger.ZERO)>0){
				ret[0]=BigInteger.ZERO;
				ret[1]=BigInteger.valueOf(-1);
				return ret;
			}
			BigInteger md=M[i].divide(d);
			BigInteger t=b.divide(d).multiply(a.divide(d).modInverse(md)).mod(md);
			ret[0]=ret[0].add(ret[1].multiply(t));
			ret[1]=ret[1].multiply(md);
			ret[0]=ret[0].mod(ret[1]);
		}
		return ret;
	}
	public void solve()throws IOException{
		int i,d=nextInt();
		if(d==-1)return;
		BigInteger D=BigInteger.valueOf(d);
		int []a=new int [d];
		int []b=new int [d];
		a[0]=0;
		for(i=1;i<d;i++)a[i]=nextInt();
		for(i=0;i<d;i++)b[i]=nextInt();
		int [][]ga=new int[d][d];
		int [][]gb=new int[d][d];
		int [][]va=new int[d][d];
		int [][]vb=new int[d][d];
		play(a,ga,va);
		play(b,gb,vb);
		BigInteger S,T;
		S=nextBigInteger();
		T=nextBigInteger();
		int []s=new int[1444];
		int []t=new int[1444];
		int ns=0,nt=0;
		while(S.compareTo(BigInteger.ZERO)>0){
			s[ns]=S.mod(D).intValue();
			S=S.divide(D);
			ns++;
		}
		while(T.compareTo(BigInteger.ZERO)>0){
			t[nt]=T.mod(D).intValue();
			T=T.divide(D);
			nt++;
		}
		nt--;ns--;
		boolean FLAG=ns==nt;
		for(i=0;i<ns;i++)
			if(gb[s[i]][t[i]]==-1)
				FLAG=false;
		if(ga[s[ns]][t[nt]]==-1)FLAG=false;
		if(!FLAG){
			writer.println("NO");
			return;
		}
		BigInteger []A=new BigInteger[ns+1];
		BigInteger []B=new BigInteger[ns+1];
		BigInteger []M=new BigInteger[ns+1];
		for(i=0;i<=ns;i++)A[i]=BigInteger.ONE;
		for(i=0;i<ns;i++)B[i]=BigInteger.valueOf(gb[s[i]][t[i]]);
		for(i=0;i<ns;i++)M[i]=BigInteger.valueOf(vb[s[i]][t[i]]);
		B[ns]=BigInteger.valueOf(ga[s[ns]][t[ns]]);
		M[ns]=BigInteger.valueOf(va[s[ns]][t[ns]]);
		BigInteger []ret=linearMod(A, B, M);
		if(ret[1].equals(BigInteger.valueOf(-1))){
			writer.println("NO");
			return;
		}
		writer.println(ret[0]);
	}
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
			while(hasNext()){
				solve();
			}
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
