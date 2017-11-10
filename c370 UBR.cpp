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
#define accel ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
int n, m, delta, t;
int f[maxn][maxk], dep[maxn], p[maxn], wt[maxn], w[maxn],r[maxn], me[maxn][maxk], E[maxn];
//me,max edge f,father dep,depth p,set wt,weight子樹數量 w,edge weight r,rank E,edge length 往上的邊
LL ans;
bool in[maxm];

struct Edge {
	int x, y, v;
}ed[maxm];

struct Edge1 {
	int to, w;
};
int find(int x) {//并查集 
	return p[x] == x ? x : find(p[x]);
}
vector<Edge1>ed1[maxm];
bool cmp(Edge a, Edge b) {
	return a.v < b.v;
}
void init() {
	delta = INF;
	ans = 0;
	for (int i = 0; i <= n; i++)
		in[i] = wt[i] = r[i] = 0, p[i] = i, E[i] = -1;
	memset(f, -1, sizeof(f));
	memset(me, 0, sizeof(me));
}
int rk(int x) {
	if (p[x] == x)return 0;
	if (r[x])return r[x];
	return find(p[x]) + 1;
}
int rlca(int u, int v) {//lac by rank
	while (u != v) {
		if (r[u] > r[v]) {
			t = max(t, E[u]);
			u = p[u];
		}
		else if (r[u] == r[v]) {
			t = max(t, max(E[u], E[v]));
			u = p[u], v = p[v];
		}
		else {
			t = max(t, E[v]);
			v = p[v];
		}
	}
	return t;
}
void kruskal() {
	sort(ed + 1, ed + 1 + m, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = ed[i].x, v = ed[i].y, w = ed[i].v;
		int x = find(u), y = find(v);
		if (x == y) continue;
		cnt++;
		if (wt[x] < wt[y]) {
			p[x] = y;
			E[x] = w;
			wt[y] = max(wt[x] + 1,wt[y]);
		}
		else {
			p[y] = x;
			E[y] = w;
			wt[x] = max(wt[y] + 1, wt[x]);
		}
		in[i] = 1;//记录它是否在最小生成树中 
		ed1[u].push_back({ v,w });
		ed1[v].push_back({ u,w });
		ans += w;
		if (cnt == n - 1) break;//完成 
	}
}
int main() {
	int x, y, z;
	accel;
	while (cin >> n >> m) {
		for (int i = 0; i <= n; i++)
			ed1[i].clear();
		for (int i = 1; i <= m; i++) {
			cin >> x >> y >> z;
			ed[i] = Edge{ x, y, z };
		}
		init();
		kruskal();
		for (int i = 1; i <= n; i++) 
			r[i] = rk(i);//find rank
		for (int i = 1; i <= m; i++)
			if (!in[i]) {
				t = -INF;
				delta = min(delta, ed[i].v - rlca(ed[i].x, ed[i].y));
			}
		if (!delta)
			puts("I Love you");
		else
			printf("%d\n", ans + delta);
	}
}
