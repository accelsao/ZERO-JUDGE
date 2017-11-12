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
#include<ctime>
#include<vector>
#define accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;


const int M = 105;
int dfs_num, top, n, m;
vector<int>g[M];
int mat[M][M];//邊的數量 兩點間可能多邊 考慮奇偶
bool mk[M];//把壓縮過的環中點標記,true 表示已壓縮
int sta[M];//tarjan 棧
int df[M], lw[M];//tarjan 參量
void init() {
	dfs_num = top = 1;
	for (int i = 0; i <= n; i++)
		g[i].clear();
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			mat[i][j] = 0;
		mk[i] = sta[i] = df[i] = lw[i] = 0;
	}
}
void tarjan(int u, int p) {
	df[u] = lw[u] = dfs_num++;
	sta[top++] = u;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if(v == p) {
			mk[u] = (mat[u][v] == 2);
			continue;
		}
		if (!df[v]) {//first time 
			tarjan(v, u);
			lw[u] = min(lw[u], lw[v]);//tree edge
		}
		else if (df[v] < lw[u])//v is u's child && v is in stack (back edge) 
			lw[u] = df[v];
	}
	if (df[u] == lw[u]) {//存在強連通分量
		//將這整個BCC退出棧
		int c = 1;
		top--;
		while (sta[top] != u) {//等於u時退出棧
			mk[sta[top--]] = 1;
			c++;
		}
		//如果節點奇數 保留一邊 包括u點最近的v點
		//u-v的邊 復原
		mk[sta[top + 1]] = !(c & 1);
	}
}
int sg(int u, int p) {
	int ans = 0;
	for (int i = 0; i < g[u].size(); i++)
		if (!mk[g[u][i]] && g[u][i] != p)
			ans ^= (sg(g[u][i], u) + 1);
	return ans;
}
int main() {
	accel;
	int T;
	while (cin >> T) {
		int ans = 0;
		while (T--) {
			cin >> n >> m;
			init();
			int u, v;
			for (int i = 0; i < m; i++) {
				cin >> u >> v;
				g[u].push_back(v);
				g[v].push_back(u);
				mat[u][v]++, mat[v][u]++;
			}
			tarjan(1, -1);//Tarjan求連通分量
			ans ^= sg(1, -1);
		}
		//puts(ans ? "空給我當個正常人!" : "汪汪");
		puts(ans ? "Sally" : "Harry");
	}
}
