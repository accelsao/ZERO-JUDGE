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


int p[30][30], used[30], back[30], joint[30], chose[30];
int n, f, Ans;
#define scanf scanf_s
int DFS(int now, int last, int depth) {
	int a, back_depth = depth - 1, t;
	back[now] = depth, f++;
	for (a = 1; a <= n; a++)
		if (p[now][a])
			if (used[a])
				back_depth = min(back_depth, back[a]);
			else {
				used[a] = 1;
				t = DFS(a, now, depth + 1);
				back_depth = min(back_depth, t);
			}
			if (back_depth == depth - 1) {
				for (a = 1; a <= n; a++)
					if (p[now][a] && chose[a])
						break;
				if (a == n + 1) {
					Ans++;
					chose[now] = 1;
				}
			}
			return back_depth;
}
int main() {
	int x, y;
	while (scanf("%d", &n) == 1) {
		memset(p, 0, sizeof(p));
		memset(used, 0, sizeof(used));
		memset(chose, 0, sizeof(chose));
		while (scanf("%d", &x) == 1 && x) {
			scanf("%d", &y);
			p[x][y] = 1, p[y][x] = 1;
		}
		Ans = 0, f = 0, used[1] = 1, DFS(1, 0, 0);
		printf("%d\n", Ans + (n - f));
	}
}

-------------------------------------------------------------------------------------
int p[31][31];
int v[31];
int b[31];
int n, t, ans, m, f, c;
int d[31],w[31];
void dfs(int u, int pre) {
	v[u] = b[u] = ++t;
	int child = 0;
	bool iscomponent = 0;
	for (int j = 1; j <= n; j++) {
		if (p[u][j] && j != pre) {
			if (v[j])//back edge	
				b[u] = min(b[u], v[j]);
			else {
				child++;
				dfs(j, u);
				b[u] = min(b[u], b[j]);
				if (b[j] >= v[u])
					iscomponent = 1;
			}
		}
	}
	if ((u == pre&&child > 1) || (u != pre&&iscomponent))
		d[u] = 0, c++;
}
int find(int x) { return x == d[x] ? x : d[x] = find(d[x]); }
int main() {
	while (cin >> n){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				p[i][j] = p[j][i] = 0;
		int x, y;
		while (cin >> x, x) {
			cin >> y;
			p[x][y] = p[y][x] = 1;
		}
		t = ans = f = c = 0;
		for (int i = 1; i <= n; i++)
			v[i] = b[i] = 0, d[i] = i, w[i] = 1;
		for (int i = 1; i <= n; i++)
			if (!v[i])
				dfs(i, i);

		for (int i = 1; i <= n; i++)
			for (int j = i+1; j <= n; j++)
				if (p[i][j] && d[i] && d[j]){

					int x = find(d[i]), y = d[j];
					if (x != y){
						if (w[x] >= w[y])
							w[x]++, d[y] = x;
						else
							w[y]++, d[x] = y;
					}
				}
		for (int i = 1; i <= n; i++)
			if (find(i) == i)
				ans++;
		//3+((n-ans+1)/2)
		d[1];
		w[1];
		int h = 0;
		for (int i = 1; i <= n; i++)
			if (!d[i])
				for (int j = 1; j <= n; j++)
					if (d[j] && p[i][j] && w[j] == 1){
						h++;
						break;
					}
		w[1];
		ans += c - h;
		//ans += c > ans ? (c - ans + 1) / 2 : 0;
		printf("%d\n", ans);
	}
}
