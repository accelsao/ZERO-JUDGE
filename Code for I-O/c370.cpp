#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
const int N=1e3;
const int M=1e9+7;
const int K=1e9;
const double eps=1e-6;
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n,m,k;
vector<PII>g[N];
int sg[N];
int dfs(int u,int t){
	if(~sg[u])return sg[u];
	set<int>val;
	for(auto i:g[u]){
		int v=i.F,d=i.S;
		if(d>=t){
			sg[v]=dfs(v,d);
			val.insert(sg[v]);
		}
	}
	for(int i=0;;i++)
		if(val.find(i)==val.end())return i;
}
int main(){

	/*freopen("c370_04.in.txt","w",stdout);
	srand(time(0));
	n=rand()*rand()%N+1;
	assert(n>=1&&n<=N);//N 1e4
	m=rand()*rand()%(n*(n-1)/2)+1;
	assert(m>=1&&m<=(n-1)*n/2);
	k=rand()%1000+1;
	printf("%d %d %d\n",n,m,k);
	int u,v,d;
	while(m--){
		u=rand()%n+1;
		v=rand()%n+1;
		while(v==u)v=rand()%n+1;
		assert(u!=v);
		d=rand()*rand()%K+1;
		assert(d>=1&&d<=K);
		printf("%d %d %d\n",u,v,d);
	}
	while(k--){
		int t=rand()%n+1;
		printf("%d\n",t);
		set<int>w;
		int c=0,x;
		vector<bool>vis(n);
		while(c<t){
			x=rand()%n+1;
			while(vis[x])x++;
			w.insert(x);
			vis[x]=1;
			c++;
			assert(w.size()==c);
		}
		for(auto x:w)cout<<x<<" ";
		cout<<endl;
	}*/
	//freopen("c370_04.out.txt","w",stdout);
	Re(sg,-1);
	cin>>n>>m>>k;
	int u,v,t;
	while(m--){
		cin>>u>>v>>t;
		g[u].PB({v,t});
	}
	FOR(i,1,n)sg[i]=dfs(i,-1);
	//FOR(i,1,n)cout<<sg[i]<<endl;
	while(k--){
		int t,c=0,x;
		cin>>t;
		REP(i,t){
			cin>>x;
			c^=sg[x];
		}
		if(c)cout<<"N\n";
		else  cout<<"P\n";
	}
}
