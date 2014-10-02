**1 JAVA I/O**

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
		
		BufferedReader		reader;
		StringTokenizer		tokenizer;
		PrintWriter			writer;
		
		public void run() {
			try {
				reader = new BufferedReader(new InputStreamReader(System.in));
				writer = new PrintWriter(System.out);
				// reader = new BufferedReader(new InputStreamReader(new FileInputStream(".in")));
				// writer = new PrintWriter(new FileOutputStream(".out"));
				tokenizer = null;
				while (hasNext()) Solve();
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
			while (tokenizer == null || !tokenizer.hasMoreTokens())
				tokenizer = new StringTokenizer(reader.readLine());
			return tokenizer.nextToken();
		}
	}


**2 栈空间**

	#pragma comment(linker, "/STACK:1024000000,1024000000")		//C++
    int size = 256<<20;						//256MB Linix G++
    char *p = (char*)malloc(size) + size;
    __asm__("movl %0, %%esp\n" :: "r"(p) );

**3 ext/?**
>rope::块状链表

	#include <ext/rope>
	using namespace __gnu_cxx;
	rope<int>L;
	L.insert(start,what);
	L.erase(start,len);
	L.copy(start,len,int *);

>hash_map::

	#include <ext/hash_map>
	using namespace __gnu_cxx;
	struct hashLL{
		inline unsigned operator()(long long a)const{return a*4423;}
	};
	hash_map<long long,int,hashLL>M;
	
**4 C艹整数I/O**

	template <class T>inline bool scan_d(T &ret) {
		char c; 
		int sgn;
		if((c=getchar())==EOF) return 0; //EOF
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		sgn=(c=='-')?-1:1;
		ret=(c=='-')?0:(c-'0');
		while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
		ret*=sgn;
		return 1;
	}
	inline void out(int x) {
		if(x>9) out(x/10);
		putchar(x%10+'0');
	}

**5 stl相关**

	cstdio::fflush(stdout);
	ctime::printf("%f\n",clock()*1./CLOCKS_PER_SEC);
	cctype::
		islower('a'~'z');isupper('A'~'Z');isalpha(islower||isupper);
		toupper();tolower();
		isdigit('0'~'9');isalnum(isaplha||isdigit);isxdigit(isdigit||'a'~'f'||'A'~'F');
		isspace(' ','\t','\n','\v','\f','\r');
	string::substr(start,len);
	bitset:://bitset<55>G[55];
		operator[],&,^,|,<<,>>,~;
		all()//all is 1?
		any()//any is 1?
		count()//how many 1?
		reset()//all 0
		set()//all 1
		set(int id,bool tmp=true)//set id is tmp
		flip()//all flip(id)
		tostring()
	algorithm::
		fill(OP,ED,val);
		rotate(first,middle,last)
		/*{1,2,3,4,5,6,7,8,9}  rotate(a,a+3,a+9)  {4,5,6,7,8,9,1,2,3}*/
		merge(op1,ed1,op2,ed2,ret)
		min_element(op,ed)//max
