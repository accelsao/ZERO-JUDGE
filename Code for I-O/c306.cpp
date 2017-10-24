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
#include<stack>
using namespace std;


char g[55][55];
int gv[55][55], n, m, s;
int h[16][16], h2[16];
int dp[1 << 16][16];
int idx;
//int dw[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };
int ds[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }};
void bfs(int x, int y) {
	int nd = gv[x][y], i, j;
	int used[55][55] = {};
	int tx, ty;
	queue<int> X, Y;
	X.push(x), Y.push(y);
	used[x][y] = 1;
	h[nd][nd] = 0;
	h2[nd] = 1e9;
	while (!X.empty()) {
		x = X.front(), X.pop();
		y = Y.front(), Y.pop();
		for (i = 0; i < 4; i++) {
			tx = x + ds[i][0], ty = y + ds[i][1];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || used[tx][ty])
				continue;
			if (g[tx][ty] == '#')
				h2[nd] = min(h2[nd], used[x][y]);
			else {
				used[tx][ty] = used[x][y] + 1;
				if (g[tx][ty] == 'X')
					h[nd][gv[tx][ty]] = used[x][y];
				X.push(tx), Y.push(ty);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	FILE*s;
	/*freopen_s(&s, "c306_03.in.txt", "w", stdout);
	int T = 10;
	printf("%d\n", T);
	while (T--){
		srand(T + 201);
		n = 50;
		m = 50;
		printf("%d %d\n", n, m);
		int A = n*m;
		int d = A /20, D = 0;
		int C = 2;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				g[i][j] = '2';
				if (i<2 || j<2 || i > n - 3 || j > m - 3)
					g[i][j]='#';
				else if (D <= 15 && (C + 7) % d == 0){
					g[i][j]='X';
					D++;
				}
				else{
					for (int k = 0; k < 8; k++) {
						int tx = i + dw[k][0], ty = j + dw[k][1];
						if (tx < 0 || ty < 0 || tx >= n || ty >= m)
							continue;
						if (g[tx][ty] == '#'){
							int ss = rand()*6823 % 3;
							if (ss==1)g[i][j] = '#';
							else
								g[i][j] = '~';
							break;
						}
					}
					if (g[i][j] == '2')
						g[i][j] = '~';
				}
				C++;				
				cout << g[i][j];
			}
			cout << endl;
		}
	}
	*/
	//freopen_s(&s, "c306_03.out.txt", "w", stdout);

	int T, i, j;
	cin >> T;
	while (T--) {
		cin >> n >> m;//10~50
		idx = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) {
				cin >> g[i][j];
				if (g[i][j] == 'X')//1~15
					gv[i][j] = idx++;
			}
		for (int i = 0; i < (1 << idx); i++)
			for (int j = 0; j < idx; j++)
				dp[i][j] = 1e9;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (g[i][j] == 'X')
					bfs(i, j);
		dp[0][0] = 0;
		for (int i = 0; i < idx; i++)
			dp[1 << i][i] = h2[i];
		int dw[1 << 16], f[1 << 16];
		for (int i = 0; i < (1 << idx); i++)
			dw[i] = f[i] = 1e9;
		for (int s = 1; s < (1 << idx); s++)
			for (int j = 0; j < idx; j++) {
				if (s&(1 << j)) {
					for (int z = 0; z < idx; z++)
						if ((s&(1 << z)) && z != j)
							dp[s][j] = min(dp[s][j], dp[s ^ (1 << j)][z] + h[j][z]);
				}
				dw[s] = min(dw[s], dp[s][j]);
			}
		f[0] = 0;
		for (int i = 1; i < (1 << idx); i++)
			for (int j = 1; j <= i; j++)
				if ((i & j) == j)
					f[i] = min(f[i], f[i ^ j] + dw[j]);
		printf("%d\n", f[(1 << idx) - 1]);
	}
}
