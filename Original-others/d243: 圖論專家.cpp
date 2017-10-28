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

const int N = 105;
const int M = 105;
struct edge{
	int to, w;
	bool operator<(const edge &a)const{
		return w > a.w;
	}
};
struct node{
	int p, g, h;
	bool operator <(const node &a)const{
		return g + h > a.g + a.h;
	}
};
vector<edge>g[N];
int n, m;
int d[N];
int head[N], A_head[N], c;
int s, t, k, ans;
void dijkstra(){//先求t 到各點的最短路 作為估價函數h()
	priority_queue<edge>q;
	edge p;
	d[t] = 0;
	q.push(edge{ t, 0 });
	while (!q.empty()){
		edge e = q.top(); q.pop();
		int u = e.to;
		for (int i = 0; i < g[u].size(); i++){
			int v = g[u][i].to;
			if (d[v]>d[u] + g[u][i].w){
				d[v] = d[u] + g[u][i].w;
				q.push(edge{ v, d[v] });
			}
		}
	}
}
void Astar(){
	ans = -1;
	node u, v;
	int num = 0;
	priority_queue<node> q;
	//if (s == t)k++;//s==t 這不算在內
	if (d[s] == 1e9){//無解
		ans = -1;
		return;
	}
	u = { s, 0, d[s] };
	q.push(u);
	while (!q.empty()){
		u = q.top(), q.pop();
		if (u.p == t&&u.g != ans)
			num++, ans = u.g;
		if (num == k){
			ans = u.g;
			return;
		}
		for (int i = 0; i < g[u.p].size(); i++){
			v = { g[u.p][i].to, u.g + g[u.p][i].w, d[g[u.p][i].to] };
			q.push(v);
		}
	}
	return;
}
int T = 1;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m){
		printf("Set #%d\n", T++);
		int u, v, w;
		for (int i = 0; i < m; i++){
			cin >> u >> v >> w;
			g[u].push_back(edge{ v, w });
			g[v].push_back(edge{ u, w });
		}
		int r;
		cin >> r;
		while (r--){
			cin >> s >> t >> k;
			for (int i = 0; i <= n; i++)
				d[i] = 1e9;
			dijkstra();
			Astar();
			if (ans >0)
				printf("%d\n", ans);
			else
				puts("?");
		}
	}
}
