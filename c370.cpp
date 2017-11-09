#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;


const int maxn = 100010, maxm = 300010, maxk = 22;
const int INF = 1e9 + 7;
#define LL long long
int n, m, delta, idc;
int head[maxn], acc[maxn][maxk], dep[maxn], p[maxn], fst[maxn][maxk], snd[maxn][maxk];
LL ans;
bool in[maxm];

struct Edge {
	int x, y, v;
}ed[maxm];

struct Edge1 {
	int to, next, w;
}ed1[maxm];

bool cmp(Edge a, Edge b) {
	return a.v < b.v;
}

void init() {
	idc = ans = 0;
	delta = INF;
	for (int i = 0; i <= n; i++)
		in[i] = head[i] = 0;
	memset(acc, 0, sizeof(acc));
	memset(fst, 0, sizeof(fst));
	memset(snd, 0, sizeof(snd));
}
void adde(int u, int v, int w) {//记录x->y的路径 
	ed1[++idc].to = v;
	ed1[idc].next = head[u];
	head[u] = idc;
	ed1[idc].w = w;
}

int find(int x) {//并查集 
	return p[x] == x ? x : p[x] = find(p[x]);
}

void dfs(int u) {//初始化st表 
	for (int i = 1; i <= 20; i++) {
		acc[u][i] = acc[acc[u][i - 1]][i - 1];//维护到达位置 
		int no1 = fst[u][i - 1], no2 = fst[acc[u][i - 1]][i - 1];
		fst[u][i] = max(no1, no2);//維護最長邊
		snd[u][i] = max(snd[u][i - 1], snd[acc[u][i - 1]][i - 1]);
		if (no1 != no2) snd[u][i] = max(snd[u][i], min(no1, no2));//維護次長邊
	}
	for (int k = head[u]; k; k = ed1[k].next) {
		int v = ed1[k].to;
		if (v != acc[u][0]) {
			dep[v] = dep[u] + 1;
			acc[v][0] = u;
			fst[v][0] = ed1[k].w;
			dfs(v);
		}
	}
}

void kruskal() {
	sort(ed + 1, ed + 1 + m, cmp);
	int cnt = 0;
	for (int i = 1; i <= n; i++) p[i] = i;//初始化p 
	for (int i = 1; i <= m; i++) { 
		int u = ed[i].x, v = ed[i].y, w = ed[i].v;
		if (find(u) == find(v)) continue;
		cnt++;
		p[find(u)] = find(v);
		in[i] = 1;//记录它是否在最小生成树中 
		adde(u, v, w);
		adde(v, u, w);//构造最小生成树，保存两点间路径 
		ans += w;
		if (cnt == n - 1) break;//完成 
	}
}

int lca(int u, int v) {//倍增求lca 
	if (dep[u] < dep[v]) swap(u, v);
	int h = dep[u] - dep[v], d = 0;
	for (int i = 20; i >= 0 && h; i--)
		if (h & (1 << i)) u = acc[u][i];//跳到同一深度 
	if (u == v) return u;
	for (int i = 20; i >= 0; i--)
		if (acc[u][i] != acc[v][i]) {
			u = acc[u][i];
			v = acc[v][i];
		}
	return acc[u][0];
}

void query(int u, int lc, int w) {
	int max1 = 0, max2 = 0;
	for (int i = 20, h = dep[u] - dep[lc]; i >= 0; i--)
		if (h & (1 << i)) {
			if (fst[u][i] > max1) {
				max2 = max1;
				max1 = fst[u][i];
			}
			max2 = max(max2, snd[u][i]);
			h -= (1 << i);
		}
	delta = min(delta, min(w - max1, w - max2));
}

void solve(int x) {
	int u = ed[x].x, v = ed[x].y, w = ed[x].v, lc = lca(u, v);
	query(u, lc, w); query(v, lc, w);//在整条链上维护最长路与新边的差的最小值（相等的话就是次小边） 
}

int main() {
	int x, y, z;
	ios::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m) {
		for (int i = 1; i <= m; i++) {
			cin >> x >> y >> z;
			ed[i] = Edge{ x, y, z };
		}
		init();
		kruskal();
		dfs(1);
		dep[1] = 0;
		for (int i = 1; i <= m; i++)
			if (!in[i]) solve(i);
		if (!delta)
			puts("I Love you");
		else
			printf("%d\n", ans + delta);
	}
}
