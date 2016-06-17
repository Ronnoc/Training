int query(int id,int le,int re){return 0;}
void update(int id,int me,int val){;}
namespace HeavyLight{
	const int MXN = 50000+5;
	vector<int>G[MXN];
	int a[MXN];
	int size[MXN] , heavy[MXN] , tid[MXN] , Top[MXN] , ncnt , dep[MXN] , Fa[MXN];
	// size : 子树大小
	// heavy : 子树大小最大的子树（重边
	// tid : 结点由重边串起来时的编号，在数据结构中维护
	// Top : 结点所在重链的头
	// Dep : 结点深度
	// Fa  : 结点父亲
	void FindHE(int x , int fa , int Dep){ //找重边重儿子
	    heavy[x] = 0 , size[x] = 1 , dep[x] = Dep , Fa[x] = fa;
	    for (auto y:G[x])if (y != fa){
	            FindHE(y , x , Dep + 1);
	            size[x] += size[y];
	            if (!heavy[x] || size[y] > size[heavy[x]])
	                heavy[x] = y;
	        }
	}
	void ConnectHE(int x , int anc){ // 把重边串起来形成重链
	    tid[x] = ++ ncnt , Top[x] = anc;
	    ::update(1, ncnt , a[x]); //单点更新值，顺便
	    if (heavy[x])
	        ConnectHE(heavy[x] , anc);
	    for (auto y:G[x])
	        if (y != Fa[x] && y != heavy[x])
	            ConnectHE(y , y);
	}
	int query(int x , int y){ // 询问
	    int ans = -1 << 30;
	    while (Top[x] != Top[y]){ // 两个结点不在一条重链上
	        if (dep[Top[x]] < dep[Top[y]])
	            swap(x , y); // 让深度大的那条链整个遍历完，tid[Top[x]]其中包含最头那条轻边
	        ans = max(ans , ::query(1, tid[Top[x]] , tid[x]));
	        x = Fa[Top[x]];
	    }
	    if (dep[x] > dep[y]) swap(x , y);//在一条链上了
	    ans = max(ans , ::query(1, tid[x] , tid[y]));
	    return ans;
	}
};