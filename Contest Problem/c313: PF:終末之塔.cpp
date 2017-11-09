#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int p[100001];
struct edge {
	int to, w;
};
vector<edge>g[100001];
int dep[100001], f[100001][30], m[100001][30], v[100001];
int n;
#define N log(n)/log(2)+1
void st() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= n; j++)
			if (~f[j][i - 1]) {//f[][]!=-1 代表祖先存在
				f[j][i] = f[f[j][i - 1]][i - 1];
				m[j][i] = max(m[j][i - 1], m[f[j][i - 1]][i - 1]);
			}
}

void dfs(int u, int d) {
	dep[u] = d;
	for (int i = 0; i < g[u].size(); i++) {
		int t = g[u][i].to;
		if (dep[t])continue;
		dfs(t, d + 1);
		f[t][0] = u;
		m[t][0] = g[u][i].w;
	}
}
int lca(int x, int y) {
	int r = -1;
	if (dep[x] < dep[y])
		swap(x, y);
	int h = dep[x] - dep[y], g = 0;
	while(h){
		if (h & 1)
			r = max(r, m[x][g]), x = f[x][g];
		h >>= 1;
		g++;
	}
	if (x == y)return r;
	for (h = 1; (1 << h) <= dep[x]; h++);
	while (--h>=0) {
		if (f[x][h] != f[y][h]) {
			r = max(r, max(m[x][h], m[y][h]));
			x = f[x][h], y = f[y][h];
		}
	}
	return max(r, max(m[x][0], m[y][0]));
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int q, x, y, w, lc;
	while (cin >> n) {
		memset(f, -1, sizeof(f));
		memset(m, 0, sizeof(m));
		for (int i = 0; i <= n; i++)
			p[i] = i, g[i].clear();
		for (int i = 1; i < n; i++) {
			cin >> x >> y >> w;
			g[x].push_back(edge{ y,w });
			g[y].push_back(edge{ x,w });
		}
		dfs(1, 1);
		st();
		cin >> q;
		while (q--) {
			cin >> x >> y;
			printf("%d\n", lca(x, y));
		}
	}
}
