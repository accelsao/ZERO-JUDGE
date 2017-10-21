#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>
using namespace std;



struct Q{
	int i, q;
};
vector<Q>lca[30001];
vector<int>adj[30001];
vector<Q>::iterator it;
vector<int>::iterator is;
int vis[30001];
int p[30001];
int dp[30001];
int oput[500000][2];
int n, q;

int find(int x){
	return x == p[x] ? x : p[x] = find(p[x]);
}
void dfs(int x,int dep){
	if (vis[x])return;
	dp[x] = dep;
	vis[x] = 1;
	for (it = lca[x].begin(); it != lca[x].end(); it++){
		if (vis[it->q]){
			oput[it->i][0] = find(it->q);
			oput[it->i][1] = dp[x] + dp[it->q] - 2 * dp[oput[it->i][0]];
		}
	}
	for (int i = 0; i < adj[x].size();i++){
		dfs(adj[x][i], dep + 1);
		int a = find(adj[x][i]);
		int b = find(x);
		p[a] = b;
	}
}
int main(){
	while (cin >> n >> q){
		int c;
		for (int i = 1; i <= n;i++){
			adj[i].clear(), p[i] = i, vis[i] = 0;
			while (cin >> c, c)
				adj[i].push_back(c);
		}
		int a, b;
		for (int i = 0; i < q; i++){
			cin >> a >> b;
			Q tmp;
			tmp.i = i; tmp.q = b;
			lca[a].push_back(tmp);
			tmp.q = a;
			lca[b].push_back(tmp);
		}
		dfs(1, 0);
		for (int i = 0; i < q; i++)
			printf("%d %d\n", oput[i][0], oput[i][1]);
	}
}
