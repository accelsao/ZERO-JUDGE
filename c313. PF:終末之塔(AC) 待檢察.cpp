#include <iostream>
#include <algorithm>
#include <vector>
#define __ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
using namespace std;

struct edge{
	int num,d;
};

vector<edge> child[100050];
int father[20][100050],ma[20][100050],vis[100050],N,r[100050],top;

void dfs(int n)
{
	vis[n]=++top;
	for(edge i:child[n])
		if(!vis[i.num]) dfs(i.num),father[0][i.num]=n,ma[0][i.num]=i.d;	
	r[n]=top;
}

void build()
{
	int i,j,L=__lg(N)+1;
	for(i=1;i<=L;i++)
		for(j=1;j<=N;j++)
			father[i][j]=father[i-1][father[i-1][j]],ma[i][j]=max(ma[i-1][j],ma[i-1][father[i-1][j]]);
}

bool ancestor(int a,int b)
{
	return (vis[a]<=vis[b] && r[a]>=r[b]);
}

int LCA(int a,int b)
{
	if(ancestor(a,b)) return 0;
	int L=__lg(N)+1,re=0;
	for(;L>=0;L--)
		if(!ancestor(father[L][a],b)) 
			re=max(re,ma[L][a]),a=father[L][a];
	return max(re,ma[0][a]);
}

int main()
{__
	int q,i,a,b,d;
	cin >> N;
	for(i=1;i<N;i++)
		cin >> a >> b >> d,child[a].push_back(edge{b,d}),child[b].push_back(edge{a,d});
	father[0][1]=1,ma[0][1]=0,dfs(1),build();
	cin >> q;
	while(q--)
		cin >> a >> b,cout << max(LCA(a,b),LCA(b,a)) << "\n";
}
