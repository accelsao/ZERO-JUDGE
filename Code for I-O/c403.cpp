#include<vector>
#include<cstdio>
#include<algorithm>
#include<fstream>
#include<ctime>
#define scanf scanf_s
#define LL long long
const int N = (1 << 20) + 5;
using namespace std;
int n, m, w[N], v;
vector<LL>g[N], p[N];
LL h;
LL dis(int v, LL h) {
	if (v > n)return 0;
	int s = lower_bound(g[v].begin(), g[v].end(), h) - g[v].begin();
	return s*h - p[v][s];
}
int main() {
	FILE*f;
	
	/*freopen_s(&f, "c403_00.in.txt", "w", stdout);
	int T=10;
	printf("%d\n", T);
	while (T--){
		srand(time(NULL) + T);
		n = rand() % 1000000 + 1;
		m = rand() % 100000 + 1;
		printf("%d %d\n", n, m);
		for (int i = 1; i < n; i++)
			printf("%d\n", rand() % 100000 + 1);
		for (int i = 0; i < m; i++){
			printf("%d %d\n", rand() % n + 1, rand() % 1000000001);
		}
	}
	return 0;*/
	freopen_s(&f, "c403_00.out.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = n; i >= 1; i--) {
		g[i].push_back(0);
		sort(g[i].begin(), g[i].end());
		p[i].resize(g[i].size() + 1);
		for (int j = 0; j < g[i].size(); j++)
			p[i][j + 1] = p[i][j] + g[i][j];
		if (i > 1)
			for (int k = 0; k < g[i].size(); k++)
				g[i / 2].push_back(g[i][k] + w[i]);
	}
	while (m--) {
		scanf("%d%lld", &v, &h);
		LL s = dis(v, h);
		while (v > 1) {
			h -= w[v];
			if (h < 0)break;
			s += h + dis(v ^ 1, h - w[v ^ 1]);
			v /= 2;
		}
		printf("%lld\n", s);
	}
	return 0;
}
