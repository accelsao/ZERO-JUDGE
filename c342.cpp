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
#include <ctime>
using namespace std;



int n, m, k, r;
const int M = 10005;
int mp[105][M];
int tm[105][M];
int dp[105][M];
pair<int, int>pr[105][M];
int smv[105][M], smt[105][M];
struct p {
	int v, t;
};
deque<p>q;
int main() {
	while (cin >> n >> m >> r >> k, n + m + r + k) {

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> mp[i][j];
		for (int i = 1; i <= n; i++) {
			smt[i][0] = 0;
			for (int j = 1; j <= m; j++) {
				cin >> tm[i][j];
				smt[i][j] = smt[i][j - 1] + tm[i][j];
			}
		}
		int a, b;
		for (int i = 0; i < r; i++) {
			cin >> a >> b;
			mp[a][b] = -1e9;//暫定-1e9 視大小調整
		}
		for (int i = 1; i <= n; i++) {
			smv[i][0] = 0;
			for (int j = 1; j <= m; j++)
				smv[i][j] = smv[i][j - 1] + mp[i][j];
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				dp[i][j] = 0, pr[i][j] = { -1,-1 };
		for (int i = 1; i <= n; i++) {
			//左
			q.clear();
			for (int j = 0; j <= m; j++) {
				int tmp = dp[i - 1][j] - smv[i][j];//因為要小到大 所以 -smv[][] 絕對值越小的在後面  
				while (!q.empty() && q.front().v <= tmp)//tmp 相當於從dp[i-1][j]點走來 但往右走  所以之後+smv[i][j] 因為是前綴和 所以要先扣掉這個點 前綴 
					q.pop_front();
				q.push_front(p{ tmp, smt[i][j] });//小到大
				while (!q.empty() && q.front().t - q.back().t>k)//超過長度 把較早近來的退出
					q.pop_back();
				dp[i][j] = q.back().v + smv[i][j];//取最大
				if (i == 1)
					pr[i][j] = { i,j };
				else
					pr[i][j] = { i - 1,j };
			}
			//右 同上 只是方向相反
			q.clear();
			int t = 0;
			for (int j = m; j >= 0; j--) {
				t += tm[i][j + 1];
				int tmp = dp[i - 1][j] + smv[i][j];//+suv[i][j] 由右往左走 同理 之後扣掉smv[i][j]後剩餘為右到左的差距
				while (!q.empty() && q.front().v <= tmp)
					q.pop_front();
				q.push_front(p{ tmp, t });
				while (!q.empty() && q.front().t - q.back().t > k)
					q.pop_back();
				if (q.back().v - smv[i][j] > dp[i][j]) {
					dp[i][j] = q.back().v - smv[i][j];//扣掉從左到右的smv = 剩下右到左的
					if (i == 1)
						pr[i][j] = { i,j + 1 };
					else
						pr[i][j] = { i - 1,j + 1 };

				}
			}
		}
		int ans = -1;
		pair<int, int>pre;
		for (int j = 0; j <= m; j++) {
			if (dp[n][j] > ans) {
				ans = dp[n][j];
				pre = { n,j };
			}
		}
		printf("%d\n", ans);
		for (pair<int, int>i = pre; i.first != -1; i = pr[i.first][i.second]) 
			cout << i.first << ' ' << i.second << endl;
		
	}
}
