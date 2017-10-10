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


struct sd{
	int x, y; char c;
};
vector<sd>G;
struct edge{
	int to, cap, pre;
	bool real;
};
struct eg{
	int to, vis;
};
vector<eg>E[103];
vector<edge>g[103];
int d[103];
int v[103], a[103], p[103], con[103];
int n, m;
int s, t;
int bfs(){
	queue<int>q;
	q.push(0);
	for (int i = 0; i <= t; i++)a[i] = -1;
	a[0] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 0; i < g[u].size(); i++){
			edge &e = g[u][i];
			if (e.cap>0 && a[e.to] == -1){
				a[e.to] = a[u] + 1;
				q.push(e.to);
			}
		}
	}
	return ~a[t];//if a[t]==-1 return 0 else return 1
}
int dfs(int u, int f){
	//if (u == t || !f)return f;
	if (u == t)return f;
	for (int &i = v[u]; i < g[u].size(); i++){
		edge &e = g[u][i];
		if (a[e.to] == a[u] + 1 && e.cap > 0){
			int d = dfs(e.to, min(f, e.cap));
			if (d > 0){
				e.cap -= d;
				g[e.to][e.pre].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int mf(){
	int flow = 0, f;
	while (bfs()){
		for (int i = 0; i <= t; i++)v[i] = 0;
		while ((f = dfs(s, 1e9)) >0)flow += f;
	}
	return flow;
}
stack<int>stk;
void euler(int u){
	for (int i = 0; i < E[u].size(); i++){
		eg &e = E[u][i];
		if (!e.vis){
			e.vis = 1;
			euler(e.to);
			stk.push(u);
		}
	}
}
int find(int x){ 
	return x == p[x] ? x :find(p[x]);
}
bool cmp(sd a, sd b){
	srand(a.x + b.x);
	return rand()*(16) % 2;
}
int main(){
	FILE* dd;
	/*freopen_s(&dd, "c298_04.in.txt", "w", stdout);
	int T;
	T = 2;
	char P[2] = { 'D', 'U' };
	printf("%d\n", T);
	int cG = 0, cN = 0, sr = 24;
	while (cG+cN < T){
		//while (!stk.empty())stk.pop();
		G.clear();
		srand(21 + sr++);
		int n, m;
		n = 100;
		m = 500;
		//printf("%d %d\n", n, m);
		for (int i = 0; i <= n + 1; i++)
			d[i] = con[i] = 0, g[i].clear(), E[i].clear(), p[i] = i;
		int x, y; char c;
		s = 0, t = n + 1;
		x = 1; y = rand()*(5+sr) % n + 1;
		while (y == x)y++, y = y > n ? 1 : y;
		for (int i = 0; i < m; i++){
			c = P[rand()*(sr + 12) % 2];
			bool UU = 0;
			int gg = rand()*(sr + 23) % m + 1;
			if (abs(i - gg) <= 3)
				swap(x, y);
			if (c == 'U')swap(x, y),UU = 1;
			//printf("%d %d %c\n", x, y, c);
			G.push_back(sd{ x, y, c });
			if (sr >1000)sr = 0;
			d[x]++, d[y]--;//+為出 -為入
			if (c == 'U'){
				g[x].push_back(edge{ y, 1, g[y].size(), 1 });
				g[y].push_back(edge{ x, 0, g[x].size() - 1, 0 });
			}
			else E[x].push_back(eg{ y, 0 });
			con[x]++, con[y]++;
			p[find(x)] = find(y);
			if (UU)swap(x, y);
			x = y;
			y = rand()*(sr + 21) % n + 1;
			while (y == x)
				y++, y = y > n ? 1 : y;
			if (i == m - 2)
				y = 1;
		}
		//for (int i = 0; i < G.size(); i++)
		//	printf("%d %d %c\n", G[i].x, G[i].y, G[i].c);
		int flag = 0, flow = 0, gp = 0;
		for (int i = 1; i <= n; i++){
			if (d[i] & 1){
				flag = 1; break;
			}
			//出 s->x 入 x->t
			if (d[i]>0){
				g[s].push_back(edge{ i, d[i] / 2, g[i].size(), 1 });//改變一條度數改變2 因此d[i] 要改變d[i]/2條 (d[i]必偶數否則無解)
				g[i].push_back(edge{ s, 0, g[s].size() - 1, 0 });
				flow += d[i] / 2;
			}
			else if (d[i]){
				g[i].push_back(edge{ t, -d[i] / 2, g[t].size(), 1 });
				g[t].push_back(edge{ i, 0, g[i].size() - 1, 0 });
			}
			if (p[i] == i&&con[i])gp++;
		}
		sort(G.begin(), G.end(), cmp);
		if (gp > 1 || flag || mf() != flow){
			//puts("Game Over");
			if (cG >= T / 2)continue;
			cG++;
			printf("%d %d\n", n, m);
			for (int i = 0; i < G.size(); i++)
				printf("%d %d %c\n", G[i].x, G[i].y, G[i].c);
			continue;
		}
		if (cN >= T / 2)continue;
		cN++;
		printf("%d %d\n", n, m);
		for (int i = 0; i < G.size(); i++)
			printf("%d %d %c\n", G[i].x, G[i].y, G[i].c);
		continue;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < g[i].size(); j++){
				edge &e = g[i][j];
				if (e.real&&e.to <= n)//將定向的無向圖加入 dfs找路
					if (e.cap>0)E[i].push_back(eg{ e.to, 0 });
					else E[e.to].push_back(eg{ i, 0 });
			}
		euler(1);
		while (!stk.empty()){
		//	printf("%d ", stk.top());
			stk.pop();
		}
		//puts("1");
	}*/
	freopen_s(&dd, "c298_04.out.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--){
		cin >> n >> m;
		for (int i = 0; i <= n + 1; i++)
			d[i] = con[i] = 0, g[i].clear(), E[i].clear(), p[i] = i;
		int x, y; char c;
		s = 0, t = n + 1;
		for (int i = 0; i < m; i++){
			cin >> x >> y >> c;
			d[x]++, d[y]--;//+為出 -為入
			if (c == 'U'){
				g[x].push_back(edge{ y, 1, g[y].size(), 1 });
				g[y].push_back(edge{ x, 0, g[x].size() - 1, 0 });
			}
			else E[x].push_back(eg{ y, 0 });
			con[x]++, con[y]++;
			p[find(x)] = find(y);
		}
		int flag = 0, flow = 0, gp = 0;
		for (int i = 1; i <= n; i++){
			if (d[i] & 1){
				flag = 1; break;
			}
			//出 s->x 入 x->t
			if (d[i]>0){
				g[s].push_back(edge{ i, d[i] / 2, g[i].size(), 1 });//改變一條度數改變2 因此d[i] 要改變d[i]/2條 (d[i]必偶數否則無解)
				g[i].push_back(edge{ s, 0, g[s].size() - 1, 0 });
				flow += d[i] / 2;
			}
			else if (d[i]){
				g[i].push_back(edge{ t, -d[i] / 2, g[t].size(), 1 });
				g[t].push_back(edge{ i, 0, g[i].size() - 1, 0 });
			}
			if (p[i] == i&&con[i])gp++;
		}
		if (gp>1 || flag || mf() != flow){
			puts("Game Over");
			continue;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < g[i].size(); j++){
				edge &e = g[i][j];
				if (e.real&&e.to <= n)//將定向的無向圖加入 dfs找路
					if (e.cap>0)E[i].push_back(eg{ e.to, 0 });
					else E[e.to].push_back(eg{ i, 0 });
			}
		euler(1);
		while (!stk.empty()){
			printf("%d ", stk.top());
			stk.pop();
		}
		puts("1");
	}
}
