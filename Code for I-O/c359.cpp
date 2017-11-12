//input
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

const int N = 20005;
int f[N][N];//記錄要連接的邊
vector<pair<int, int>>v;//存邊
vector<int>g[N];
int vis[100001];//有建邊  0沒邊 1有邊 2已建環點
void bfs(int n){
	queue<int>q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 1; i <= n;i++)
			if (f[u][i] && !vis[i] && u != i){
				v.push_back({ u, i });
				vis[i] = 1;
				q.push(i);
			}
	}
}
int main() {
	accel;
	FILE*s;
	freopen_s(&s, "c359_00.in.txt", "w", stdout);
	int TT = 3;//3筆測資
	int seed = 0;
	while (TT--){
		int T;
		srand(time(NULL)+(seed+=3));
		T = rand() % 3 + 1;//10張圖
		printf("%d\n", T);
		const int N = 5 + rand() % 5;//N點
		int n = rand() % (N-1) + 2;// 先建樹 樹的點
		while (T--){
			//初始
			v.clear();
			//srand(time(NULL) + T);
			for (int i = 1; i <= N; i++){
				g[i].clear();
				vis[i] = 0;
			}
			//先產生一堆邊讓每個點至少有一邊
			for (int i = 1; i <= n; i++){
				int c = 0;
				for (int j = 1; j <= n; j++)
					c+=(f[i][j] = rand() % 20);//1代表要連
				if (!c){
					int c = rand() % n + 1;
					while (c == i) c = rand() % n + 1;
					f[i][c] = 1;
				}
			}
				bfs(n);
			//加環
			int left = N - n;
			while (left){
				int u = rand() % n + 1;
				while (vis[u] == 2){ u = rand() % n + 1; }
				//n+1~2*N
				int now = u;
				while (1){
					int nxt = n + 1 + rand() % N;
					while (vis[nxt] && nxt <= N){ nxt++; }
					if (nxt > N){
						if (now != u)
							v.push_back({ now, u });
						break;
					}
					else{
						vis[nxt] = 2;
						v.push_back({ now, nxt });
						now = nxt;
						left--;
					}
				}				
			}
			printf("%d %d\n", N, v.size());
			for (int i = 0; i < v.size(); i++)
				printf("%d %d\n", v[i].first, v[i].second);
		}
	}
}
//output
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

const int M = 20005;
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
		if (v == p) {
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
	FILE*s;
	freopen_s(&s, "c359_00.out.txt", "w", stdout);
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
		puts(ans ? "Sutefu" : "Sora");
	}
}
