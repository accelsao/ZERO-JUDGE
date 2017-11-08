#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;


#define maxn 300010
typedef long long LL;
int n, m;
int pa[maxn];
int fa[maxn], dep[maxn], dist[maxn];
bool used[maxn];
struct edge
{
	int u, v, w;
};
vector<edge>E;
vector<int>g[maxn], w[maxn];

bool cmp(edge a, edge b)
{
	return a.w<b.w;
}

void initial()
{
	for (int i = 1; i <= n; i++)pa[i] = i;
}
int find(int x)
{
	return pa[x] = pa[x] == x ? x : find(pa[x]);
}
void Union(int x, int y)
{
	pa[find(x)] = find(y);
}
bool judge(int x, int y)
{
	return find(x) == find(y);
}

LL kruskal()
{
	initial();
	sort(E.begin(), E.end(), cmp);

	LL sum = 0, cnt = 0;
	for (int i = 0; i<E.size(); i++)
	{
		int a = E[i].u, b = E[i].v, c = E[i].w;
		if (judge(a, b))continue;
		Union(a, b);
		used[i] = 1;
		g[a].push_back(b);
		w[a].push_back(c);

		g[b].push_back(a);
		w[b].push_back(c);

		sum += c;
		cnt++;
		if (cnt == n - 1)break;
	}
	return sum;
}

void DFS(int i, int f, int d)
{
	fa[i] = f;
	dep[i] = d;
	int sz = g[i].size();
	for (int k = 0; k<g[i].size(); k++)
	{
		int j = g[i][k], c = w[i][k];
		if (j == f)continue;
		dist[j] = dist[i] + c;
		DFS(j, i, d + 1);
	}
}

int LCA(int x, int y)
{
	if (dep[x]<dep[y])swap(x, y);
	while (dep[x] != dep[y])x = fa[x];
	while (x != y)x = fa[x], y = fa[y];
	return x;
}

int getmax(int x, int y, int c)
{
	int z = LCA(x, y), maxans = 0;
	while (x != z)
	{
		if (dist[x] - dist[fa[x]]<c)
			maxans = max(maxans, dist[x] - dist[fa[x]]);
		x = fa[x];
	}
	while (y != z)
	{
		if (dist[y] - dist[fa[y]]<c)
			maxans = max(maxans, dist[y] - dist[fa[y]]);
		y = fa[y];
	}
	return maxans;
}
#define scanf scanf_s
int main()
{
	//freopen("my.in","r",stdin);
	//freopen("my.out","w",stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		E.push_back(edge { a, b, c });
	}

	LL sum = kruskal(), ans = (LL)100000 * 1000000000;
	DFS(1, 1, 1);
	for (int i = 0; i<m; i++)
	{
		if (used[i])continue;
		int a = E[i].u, b = E[i].v, c = E[i].w;
		int t = getmax(a, b, c);
		if (c>t)ans = min(ans, sum - t + c);
	}
	cout << sum << endl;
	cout << ans << endl;
}
