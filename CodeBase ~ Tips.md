 1. 有向图，从A点恰好走k步（允许重复经过边）到达B点的方案数mod p的值

	把给定的图转为邻接矩阵，即A(i,j)=1当且仅当存在一条边i->j。令C=A*A，那么C(i,j)=ΣA(i,k)*A(k,j)，实际上就等于从点i到点j恰好经过2条边的路径数（枚举k为中转点）。类似地，C*A的第i行第j列就表示从i到j经过3条边的路径数。同理，如果要求经过k步的路径数，我们只需要求出A^k即可。
	可以根据 AC自动机 or trie树 建立图的转移关系,同上乱搞

 2. 错排

	一重错排: D[1]=0;D[2]=1;D[n]=(n-1)*(D[n-1]+D[n-2])<br>
	二重错排: U[n] = ∑(-1)^k * (2n)/(2n-k) * comb(2n-k,k)*(n-k)!

 3. 二项式反演

		     n     k                       n     k
		a_n= ∑ (-1) comb(n,k)b_k <==> b_n= ∑ (-1) comb(n,k)a_k   
		    k=0                           k=0                    
		     n                        n     n-k
		a_n= ∑ comb(n,k)b_k <==> b_n= ∑ (-1)   comb(n,k)a_k   
		    k=0                      k=0                    

 4. 多项式求和
	
		   p^c-1	         phi(p^c)
			 ∑ i^d mod p^c =    ∑ g^(d*i) mod p^c
			i=0				   i=0

	p是非2质数,或1,2,4,g是p的原根(g^(p-1)==1 mod p,g^i构成p的一个模剩余系)<br>
	对于2^c (c>3) 有结论 if(d&1)return 0;else return llpow(2,c-1,2^c);
 5. 格点简单多边形面积S,边上格点数B,内部格点数I满足S=B/2+I-1
 6. 四面体O-ABC体积公式a = AB, b = BC, c = CA, d = OC, e = OA, f = OB<br>
	(12V)^2 = a^2^d2(b^2 + c^2 + e^2 + f^2 − a^2 − d^2) + b^2e^2(c^2 + a^2 + f^2 + d^2 − b^2 − e^2) + c^2f^2(a^2 + b^2 + d^2 + e^2 −c^2 − f^2) − a^2b^2c^2 − a^2e^2f^2 − d^2b^2f^2 − d^2e^2c^2
 7. 卡特兰数:Cat(n)=Comb(2n,n)/(n+1) 
<br>7.1. n节点二叉树个数Cat(n)
<br>7.2. 正n边形划分为n-2个三角形的种数Cat(n-2)
<br>7.3. n个矩阵连乘括号化种数Cat(n-1)
<br>7.4. n个元素入栈的出栈顺序种数Cat(n)
<br>7.5. 从n * n 方格的左上角移动到右下角不升路径数
 8. Bell数:n元素的集合划分数
<br>8.1 Bell[n+1]=∑comb(n,k)Bell[k]
<br>8.2 Bell[p+n]=B[n]+B[n+1] (mod p) {p是质数}
<br>8.3 Bell[n]=∑Stirling2[n,k]
 9. 第一类Stirling数:将n个物体排成k个非空循环排列的方法数
<br>Stirling1[n,k]=(n-1)*Stirling1[n-1,k]+Stirling1[n-1,k-1]
 10. 第一类Stirling数:将n个物体划分成k个非空的不可辨别的集合的方法数
<br>Stirling2[n,k]=k*Stirling2[n-1,k]+Stirling2[n-1,k-1]
 11. 容斥反演:

	g(A)=∑{S⊆A}f(S) <==> f(A)=∑{S⊆A}(-1)^(|A|-|S|)g(S)
 12. 莫比乌斯反演

	miu[n]=0 when n包含平方因子<br>
	miu[n]=(-1)^k n为k个素数的乘积<br>
	g(n)=∑{d\n}f(d) <==> f(n)=∑{d\n}miu[d]g(n/d)<br>
	g(x)=∑{n=1,n<=x}f(x/n) <==> f(x)=∑{n=1,n<=x}miu[n]g(x/n)
 13. 平方剩余定理: 奇素数p,x^2==a mod p 有解 <==> a^((p-1)/2)==1 mod p
 14. 阶乘近似 n! 约等于 sqrt(2PIn)(n/e)^n
 15. 数值积分:
	∫_a^b f(x)dx = h/3( f(x[0]) + 2∑{j=1~n/2-1}f(x[2j]) + 4∑{j=1~n/2}f(x[2j-1]) + f(x[n]))
 16.	集合位运算

		S = 0;					//empty
		S = 1 << i;			//{i}
		S = (1 << n) - 1;	//{0,1,..,n-1}
		if (S >> i & 1);	//check whether i belong to S
		S | 1 << i;			//add i to S
		S & ~ (1 << i);		//delete i from S
	
		for (int i = 0; i < 1 << n ; i++);		//枚举子集
	
		{
			//降序枚举任意集合子集
			int sub = S;
			do {
			
				sub = (sub - 1) &S;
			} while (sub != S);							//0之后 有(-1)&S=S;
		}
	
		{
			//枚举大小为k的子集
			int sub = (1 << k) - 1;
			while (sub < 1 << n) {
				
				int x = sub & -sub, y = sub + x;
				sub = (sub & -y) / x >> 1 | y;
			}
		}
 17. 求和公式
	
		1. sum( k ) = n(n+1)/2
		2. sum( 2k-1 ) = n^2
		3. sum( k^2 ) = n(n+1)(2n+1)/6
		4. sum( (2k-1)^2 ) = n(4n^2-1)/3
		5. sum( k^3 ) = (n(n+1)/2)^2
		6. sum( (2k-1)^3 ) = n^2(2n^2-1)
		7. sum( k^4 ) = n(n+1)(2n+1)(3n^2+3n-1)/30
		8. sum( k^5 ) = n^2(n+1)^2(2n^2+2n-1)/12
		9. sum( k(k+1) ) = n(n+1)(n+2)/3
		10. sum( k(k+1)(k+2) ) = n(n+1)(n+2)(n+3)/4
		12. sum( k(k+1)(k+2)(k+3) ) = n(n+1)(n+2)(n+3)(n+4)/5

 18. Young矩阵:Y[1]=1;Y[2]=2;Y[n]=Y[n-1]+(n-1)*Y[n-2];
 19. 矩阵乘法通用优越姿势`for(i)for(j)if(a.x[i][j])for(k)ret.x[i][k]+=a.x[i][j]*b.x[j][k]`