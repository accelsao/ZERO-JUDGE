#define scanf scanf_s

#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
const int maxn = 200010;
const int maxm = 1000010;

int sd[maxn], rd[maxn], cd[maxn], dian[maxn], head[maxn], low[maxn], dfn[maxn], st[maxn], vis_st[maxn];
int bb[maxm][2], d[maxn], vis[maxn], top = 0, tot = 0, num = 0, numb = 0;
struct node{
	int to, pre, flag;
}e[maxm * 2];
void ini()
{
	mem(st, 0); mem(bb, 0); mem(d, 0); mem(vis, 0); mem(dfn, 0); mem(low, 0); mem(vis_st, 0); mem(e, 0); mem(sd, 0); mem(rd, 0); mem(cd, 0); mem(dian, 0); mem(head, -1);
	top = 0, tot = 0, num = 0, numb = 0;
}
void addedge(int h, int a, int b)
{
	e[h].to = b; e[h].pre = head[a]; e[h].flag = 1; head[a] = h;
}
void Tarjan(int u)
{
	st[++top] = u;
	dfn[u] = low[u] = ++tot;
	vis_st[u] = 1;
	for (int i = head[u]; i>-1; i = e[i].pre)
	{
		node t = e[i];
		if (!e[i].flag) continue;
		e[i].flag = e[i ^ 1].flag = 0;
		if (!dfn[t.to])
		{
			Tarjan(t.to);
			low[u] = min(low[u], low[t.to]);
			if (dfn[u]<low[t.to])
			{
				bb[numb][0] = u; bb[numb++][1] = t.to;
			}
		}
		else { if (vis_st[t.to]) low[u] = min(low[u], low[t.to]); }
	}
	if (dfn[u] == low[u])
	{
		sd[num++] = u;
		int a;
		do{
			a = st[top--];
			vis_st[a] = 0;
			dian[a] = u;
		} while (u != a);
	}
}
void dfs(int u, int h)
{
	vis[u] = 1;
	for (int i = head[u]; i>-1; i = e[i].pre)
	{
		int t = dian[e[i].to];
		if (!vis[t])
			dfs(t, h + 1);
	}
	d[u] = h;
}
int sg(int u, int p) {
	int ans = 0;
	for (int i = head[u]; ~i; i=e[i].pre){
		/*int v = g[u][i];
		if (v == p)continue;
		if (v == lw[u])continue;
		int p = (lw[v] == lw[u]) ? mk[u] : 1;
		int s = sg(v, u) + p;//壓縮點看mk 其他+1*/
		ans ^= 1;
	}
	return ans;
}
int main()
{
	int N, M, maxx = 0, k = 0;
	while (scanf("%d %d", &N, &M) != EOF&&N + M)
	{
		ini(); int h = 0;
		num = top = tot = 0, maxx = 0, k = 0;;
		for (int i = 0; i<M; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			addedge(h, a, b); h++;
			addedge(h, b, a); h++;
		}
		for (int i = 1; i <= N; i++)
			if (!dfn[i])
				Tarjan(i);
		mem(e, 0); h = 0; mem(vis, 0); mem(d, 0); mem(head, -1);
		for (int i = 0; i<numb; i++){
			addedge(h, dian[bb[i][0]], dian[bb[i][1]]); h++;
			addedge(h, dian[bb[i][1]], dian[bb[i][0]]); h++;
		}
		dfs(dian[1], 0);
		mem(vis, 0);
		int s = sg(1, -1);
		/*k = dian[1];
		for (int i = 0; i<num; i++)
			if (maxx<d[sd[i]]) { maxx = d[sd[i]]; k = sd[i]; }
		mem(vis, 0); mem(d, 0);
		dfs(k, 0); maxx = 0;
		for (int i = 0; i<num; i++)
			if (maxx<d[sd[i]]) maxx = d[sd[i]];
		printf("%d\n", num - maxx - 1);*/
	}
	return 0;
}
