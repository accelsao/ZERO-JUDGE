#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;



struct edge {
	int u, v, flow, cap;
};
vector<edge>E;
vector<int>g[50];
int n, m;
void add(int u,int v,int cap) {
	E.push_back(edge{ u,v,0,cap });
	E.push_back(edge{ v,u,0,0 });
	int m = E.size();
	g[u].push_back(m - 2);
	g[v].push_back(m - 1);
}
int v[50], d[50];
bool bfs(int s,int t) {
	for (int i = 0; i < 50; i++)v[i] = 0;
	queue<int>q; q.push(s);
	d[s] = 0; v[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < g[u].size(); i++) {
			edge &e = E[g[u][i]];
			if (!v[e.v] && e.cap > e.flow) {
				v[e.v] = 1;
				d[e.v] = d[e.u] + 1;
				q.push(e.v);
			}
		}
	}
	return v[t];
}
int dfs(int a, int df,int t) {
	if (a == t||!df)return df;//到終點or cap-flow==0
	for (int i = 0; i < g[a].size(); i++) {
		edge &e = E[g[a][i]];
		int f;
		if (e.cap - e.flow > 0 && d[e.v] == d[a] + 1 && (f = dfs(e.v, min(df, e.cap - e.flow), t))) {
			e.flow += f;//flow增加 cap-flow 剩餘 才會減少
			E[g[a][i]^ 1].flow -= f;//反向
			return f;
		}
	}
	return 0;
}
int mf(int s, int t) {
	int flow = 0;
	while (bfs(s, t)) {
		for (int i = 0; i < 50; i++)v[i] = 0;
		int f = dfs(s, 1e9, t);
		if (!f)break;
		flow += f;
	}
	return flow;
}
string sz[6] = { "XXL","XL","L","M","S","XS" };
int num[15];//c6取2 任選2種的個數
int main() {
	while (cin >> n >> m) {
		E.clear();
		for (int i = 0; i < n; i++)g[i].clear();
		string a, b;
		for (int i = 0; i < 15; i++)num[i] = 0;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			int c = 0;
			for (int i = 0; i < 6; i++)
				for (int j = i + 1; j < 6; j++) {
					if (a == sz[i] && b == sz[j] || a == sz[j] && b == sz[i])
						num[c]++;
					c++;
				}
		}
		int c = 0;
		for (int i = 0; i < 6; i++)
			add(21, i, n / 6);//每件最多n/6 21源點 22匯點
		for (int i = 0; i < 6; i++)
			for (int j = i + 1; j < 6; j++) {
				add(i,c + 6, 1e9);
				add(j, c + 6, 1e9);
				add(c + 6,22, num[c]);
				c++;
			}
		if (mf(21, 22) == m)puts("YES");
		else puts("NO");

	}
}
