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


const int M = 10001;
long long cost[M], d[M];
int p[M][3];//輸入點
long long dp[M];
int g[M][M];//實際距離
int r[M][M];//障礙物
int tx, ty;
const int dw[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int H(int sx, int sy) {
	return abs(sx - tx) + abs(sy - ty);
}
struct node {
	int x, y, fs;
	bool operator<(const node &a)const {
		if (fs == a.fs)
			return H(x, y) > H(a.x, a.y);
		return fs > a.fs;
	}
};
int v[M][M], n, m;//visit
int df(int j) {
	return dp[j - 1] - cost[j] + d[j];
}
int astar(int sx, int sy) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i][j] = 0, g[i][j] = 1e9;
	g[sx][sy] = 0;
	priority_queue<node>q;
	q.push({ sx, sy,H(sx,sy) });
	while (!q.empty()) {
		node cur = q.top(); q.pop();
		if (cur.x == tx&&cur.y == ty)
			return cur.fs;
		v[cur.x][cur.y] = 1;
		for (int k = 0; k < 4; k++) {
			int nx = cur.x + dw[k][0], ny = cur.y + dw[k][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || !r[nx][ny] || v[nx][ny])
				continue;
			int ng = g[cur.x][cur.y] + 1;
			if (ng >= g[nx][ny]) //this isnt a better path
				continue;
			g[nx][ny] = ng;
			q.push(node{ nx,ny,g[nx][ny] + H(nx, ny) });
		}
	}
	return -1;
}
bool rp[M][M];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	FILE *f;
	/*
	freopen_s(&f, "c340_00.in.txt", "w", stdout);
	int T = 3;
	printf("%d\n", T);
	while (T--) {
	srand(T + 235);
	int C = rand()*13 % 100000 + 1;
	printf("%d\n", C);
	int r, c, x, y;
	r = rand()*19 % 9998 + 3;
	c = rand()*29 % 9998 + 3;
	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++)
	rp[i][j] = 0;
	x = rand() * 59 % r;
	y = rand() * 97 % c;
	rp[x][y] = 1;
	printf("%d %d\n%d %d\n", x, y, r, c);
	int m = min(rand() * 113 % 10, r*c - 1), n = min(rand() * 129 % 15, r*c - m - 1);
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
	x = rand() * 13 % r;
	y = rand() * 71 % c;
	while (rp[x][y]) { y++; if (y == c)x++, y = 0; if (x == r)x = 0; }
	rp[x][y] = 1;
	printf("%d %d\n", x, y);
	}
	printf("%d\n", m);
	for (int i = 0; i < m; i++) {
	x = rand() * 37 % r;
	y = rand() * 197 % c;
	int w = rand() * 337 % 1000 + 1;
	while (rp[x][y]) { y++; if (y == c)x++, y = 0; if (x == r)x = 0; }
	rp[x][y] = 1;
	printf("%d %d %d\n", x, y,w);
	}
	}
	*/
	///*
	freopen_s(&f, "c340_00.out.txt", "w", stdout);
	int t, x, y;
	cin >> t;
	while (t--) {
		int c;
		cin >> c >> x >> y;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				r[i][j] = 1;
		int a, b, s;
		cin >> s;
		for (int i = 0; i < s; i++) {
			cin >> a >> b; r[a][b] = 0;//0為障礙物
		}
		cin >> s;
		p[0][0] = x, p[0][1] = y;
		p[0][2] = cost[0] = 0;
		bool fail = 0;
		for (int i = 1; i <= s; i++) {
			cin >> p[i][0] >> p[i][1] >> p[i][2];
			if (fail)continue;
			tx = p[i][0], ty = p[i][1];
			int dis = astar(p[i - 1][0], p[i - 1][1]);
			if (dis < 0)fail = 1;
			cost[i] = cost[i - 1] + dis;//將點與點之間要走的距離(含S) 前綴和
			p[i][2] += p[i - 1][2];//攜帶重量
			d[i] = astar(x, y);
			if (d[i] < 0)fail = 1;
		}
		if (fail) {
			puts("Mission Fail:(");
			continue;
		}
		deque<int>q;
		for (int i = 1; i <= s; i++) {
			while (!q.empty() && df(i) <= df(q.back()))
				q.pop_back();
			q.push_back(i);
			while (!q.empty() && p[i][2] - p[q.front() - 1][2] > c)
				q.pop_front();
			dp[i] = df(q.front()) + cost[i] + d[i];
		}
		printf("%lld\n", dp[s]);
	}
	//*/
}
