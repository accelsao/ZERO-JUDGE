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
#include<fstream>
#include<stack>
#include<vector>
using namespace std;


//dp[i] = (dp[j - 1] - cost[j] + dist[j]) + cost[i] + dist[i]
int cost[10001], d[10001];
int p[10001][3];//輸入點
int dp[10001];
int g[10001][10001];//實際距離
int r[10001][10001];//障礙物
const int dw[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
struct node {
	int x, y, fs;
	bool operator<(const node a)const {
		return fs > a.fs;
	}
};
int f[10001][10001];//f估價
int v[10001][10001], n, m;//visit
int df(int j) {
	return dp[j - 1] - cost[j] + d[j];
}
int H(int sx, int sy, int tx, int ty) {
	return abs(sx - tx) + abs(sy - ty);
}
int astar(int sx, int sy, int tx, int ty) {
	int h = abs(sx - tx) + abs(sy - ty);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i][j] = 0, g[i][j] = f[i][j] = 1e9;
	g[sx][sy] = 0;
	f[sx][sy] = H(sx, sy, tx, ty);
	priority_queue<node>q;
	q.push({ sx, sy,f[sx][sy] });
	while (!q.empty()) {
		node cur = q.top(); q.pop();
		if (cur.x == tx&&cur.y == ty)
			return cur.fs;
		v[cur.x][cur.y] = 1;
		for (int k = 0; k < 4; k++) {
			int nx = cur.x + dw[k][0], ny = cur.y + dw[k][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || !r[nx][ny]||v[nx][ny])
				continue;
			q.push(node{ nx,ny,f[nx][ny] });
			int ng = g[cur.x][cur.y] + 1;
			if (ng >= g[nx][ny])continue;//this isnt a better path
			g[nx][ny] = ng;
			f[nx][ny] = g[nx][ny] + H(nx, ny, tx, ty);
		}
	}
	return -1;
}

int main() {
	int t, x, y;
	cin >> t;
	while (t--) {
		int c;
		cin >> c >> x >> y >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				r[i][j] = 1;
		int a, b,s;
		cin >> s;
		for (int i = 0; i < s; i++) {
			cin >> a >> b; r[a][b] = 0;//0為障礙物
		}
		cin >> s;
		p[0][0] = p[0][1] = p[0][2] = cost[0] = 0;
		for (int i = 1; i <= s; i++) {
			cin >> p[i][0] >> p[i][1] >> p[i][2];
			//cost[i] = cost[i - 1] + abs(p[i][0] - p[i - 1][0]) + abs(p[i][1] - p[i - 1][1]);
			cost[i] = cost[i - 1] + astar(p[i - 1][0], p[i - 1][1], p[i][0], p[i][1]);
			p[i][2] += p[i - 1][2];
			//d[i] = abs(p[i][0] - x) + abs(p[i][1] - y);
			d[i] = astar(x, y, p[i][0], p[i][1]);
		}
		deque<int>q;
		for (int i = 1; i <= s; i++) {
			while (!q.empty() && df(i) <= df(q.back()))
				q.pop_back();
			q.push_back(i);
			while (!q.empty() && p[i][2] - p[q.front() - 1][2] > c)
				q.pop_front();
			dp[i] = df(q.front())+ cost[i] + d[i];
		}
		printf("%d\n", dp[s]);
		if (t)
			puts("");
	}
}
