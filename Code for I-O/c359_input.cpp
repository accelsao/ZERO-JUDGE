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

//input code
/*const int N = 20005;
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
