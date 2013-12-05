1. 有向图，从A点恰好走k步（允许重复经过边）到达B点的方案数mod p的值

	把给定的图转为邻接矩阵，即A(i,j)=1当且仅当存在一条边i->j。令C=A*A，那么C(i,j)=ΣA(i,k)*A(k,j)，实际上就等于从点i到点j恰好经过2条边的路径数（枚举k为中转点）。类似地，C*A的第i行第j列就表示从i到j经过3条边的路径数。同理，如果要求经过k步的路径数，我们只需要求出A^k即可。
	可以根据 AC自动机 or trie树 建立图的转移关系,同上乱搞

2. 二重错排

	U_n = ∑(-1)^k * (2n)/(2n-k) * comb(2n-k,k)*(n-k)!

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

	miu[n]=0 when n包含平方因子
	miu[n]=(-1)^k n为k个素数的乘积
	g(n)=∑{d\n}f(d) <==> f(n)=∑{d\n}miu[d]*g(n/d)
	g(x)=∑{n=1,n<=x}f(x/n) <==> f(x)=∑{n=1,n<=x}miu[n]*g(x/n)
	