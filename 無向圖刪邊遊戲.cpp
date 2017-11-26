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
//#define N 1010
#define scanf scanf_s




#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
const int maxn = 20010;
const int maxm = 1000010;

int sd[maxn], rd[maxn], cd[maxn], dian[maxn], head[maxn], low[maxn], dfn[maxn], st[maxn], vis_st[maxn];
int bb[maxm][2], d[maxn], vis[maxn], top = 0, tot = 0, num = 0, numb = 0;
int edgecnt[maxn][maxn];
int mk[maxn];
struct node{
	int to, pre, flag;
}e[maxm * 2];
void ini()
{
	mem(edgecnt, 0);
	mem(mk, 0);
	mem(st, 0); mem(bb, 0); mem(d, 0); mem(vis, 0); mem(dfn, 0); mem(low, 0); mem(vis_st, 0); mem(e, 0); mem(sd, 0); mem(rd, 0); mem(cd, 0); mem(dian, 0); mem(head, -1);
	top = 0, tot = 0, num = 0, numb = 0;
}
void addedge(int h, int a, int b)
{
	e[h].to = b; e[h].pre = head[a]; e[h].flag = 1; head[a] = h;
}
void Tarjan(int u)
{
	st[++top] = u;
	dfn[u] = low[u] = ++tot;
	vis_st[u] = 1;
	for (int i = head[u]; i>-1; i = e[i].pre)
	{
		node t = e[i];
		if (!e[i].flag) continue;
		e[i].flag = e[i ^ 1].flag = 0;
		if (!dfn[t.to])
		{
			Tarjan(t.to);
			low[u] = min(low[u], low[t.to]);
			if (dfn[u]<low[t.to])
			{
				bb[numb][0] = u; bb[numb++][1] = t.to;

			}
		}
		else { if (vis_st[t.to]) low[u] = min(low[u], low[t.to]); }
	}
	if (dfn[u] == low[u])
	{
		sd[num++] = u;
		int a;
		int c = 0;
		int k = top;
		do{
			a = st[top];
			vis_st[a] = 0;
			dian[a] = u;
			for (int i = top + 1; i <= k; i++)
				c += edgecnt[a][st[i]];
			top--;
		} while (u != a);
		if (c>2 && c & 1)
			mk[u] = 1;
		
	}
}
void dfs(int u, int h)
{
	vis[u] = 1;
	for (int i = head[u]; i>-1; i = e[i].pre)
	{
		int t = dian[e[i].to];
		if (!vis[t])
			dfs(t, h + 1);
	}
	d[u] = h;
}
int sg(int u, int p) {
	int ans = 0;
	for (int i = head[u]; ~i; i = e[i].pre){
		int v = e[i].to;
		if (v == p)continue;
		int s = sg(v, u) + 1;
		ans ^= s;
	}
	return ans^mk[u];//mk[]=1代表 奇環 0為偶環
}
int main(){
	int N, M, maxx = 0, k = 0,T;
	while (cin >> T){
		int ans = 0;
		while (T--){
			cin >> N >> M;			
			ini(); int h = 0;
			num = top = tot = 0, maxx = 0, k = 0;;
			for (int i = 0; i < M; i++)
			{
				int a, b;
				scanf("%d %d", &a, &b);
				addedge(h, a, b); h++;
				addedge(h, b, a); h++;
				edgecnt[a][b]++, edgecnt[b][a]++;
			}
			for (int i = 1; i <= N; i++)
				if (!dfn[i])
					Tarjan(i);
			mem(e, 0); h = 0; mem(vis, 0); mem(d, 0); mem(head, -1);
			for (int i = 0; i < numb; i++){
				addedge(h, dian[bb[i][0]], dian[bb[i][1]]); h++;
				addedge(h, dian[bb[i][1]], dian[bb[i][0]]); h++;
			}
			dfs(dian[1], 0);
			mem(vis, 0);
			ans ^= sg(1, -1);
		}
		printf("%d\n", ans);
	}
}
