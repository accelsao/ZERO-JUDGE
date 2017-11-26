#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;


const int maxn = 100010, maxm = 300010, maxk = 21;
const int INF = 1e9 + 7;
#define LL long long
#define N log(n)/log(2)+1
int n, m, delta, t;
int f[maxn][maxk], dep[maxn], p[maxn], me[maxn][maxk];//me max edge
LL ans;
bool in[maxm];

struct Edge {
	int x, y, v;
}ed[maxm];

struct Edge1 {
	int to, w;
};
vector<Edge1>ed1[maxm];
bool cmp(Edge a, Edge b) {
	return a.v < b.v;
}

void init() {
	ans = 0;
	delta = INF;
	for (int i = 0; i <= n; i++)
		in[i] = 0, p[i] = i;
	memset(f, -1, sizeof(f));
	memset(me, 0, sizeof(me));
}
int find(int x) {//并查集 
	return p[x] == x ? x : p[x] = find(p[x]);
}
void st() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= n; j++)
			if (~f[j][i - 1]) {
				f[j][i] = f[f[j][i - 1]][i - 1];//维护到达位置 
				me[j][i] = max(me[j][i - 1], me[f[j][i - 1]][i - 1]);
			}
}
void dfs(int u) {//初始化st表 
	for (Edge1 k : ed1[u]) {
		int v = k.to;
		if (v == f[u][0])continue;
		dep[v] = dep[u] + 1;
		f[v][0] = u;
		me[v][0] = k.w;
		dfs(v);
	}
}

void kruskal() {
	sort(ed + 1, ed + 1 + m, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = ed[i].x, v = ed[i].y, w = ed[i].v;
		if (find(u) == find(v)) continue;
		cnt++;
		p[find(u)] = find(v);
		in[i] = 1;//记录它是否在最小生成树中 
		ed1[u].push_back({ v,w });
		ed1[v].push_back({ u,w });
		ans += w;
		if (cnt == n - 1) break;//完成 
	}
}

int lca(int u, int v) {//倍增求lca 
	if (dep[u] < dep[v]) swap(u, v);
	int h = dep[u] - dep[v], d = 0;
	while (h) {
		if (h & 1) {
			t = max(t, me[u][d]);
			u = f[u][d];
		}
		d++, h >>= 1;
	}
	if (u == v) return t;
	for (h = 1; (1 << h) <= dep[u]; h++);
	while (--h >= 0)
		if (f[u][h] != f[v][h]) {
			t = max(t, max(me[u][h], me[v][h]));
			u = f[u][h];
			v = f[v][h];
		}
	return  max(t, max(me[u][0], me[v][0]));
}
int main() {
	int x, y, z;
	ios::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m) {
		for (int i = 0; i <= n; i++)
			ed1[i].clear();
		for (int i = 1; i <= m; i++) {
			cin >> x >> y >> z;
			ed[i] = Edge{ x, y, z };
		}
		init();
		kruskal();
		dep[1] = 1;
		dfs(1);
		st();
		for (int i = 1; i <= m; i++)
			if (!in[i]) {
				t = -INF;
				delta = min(delta, ed[i].v - lca(ed[i].x, ed[i].y));
			}
		if (!delta)
			puts("I Love you");
		else
			printf("%d\n", ans + delta);
	}
}
