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
const int N=1e5;
const int M=1e9;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }int n;
int n,x;
int main(){Accel
    
    /*freopen("c405_04.in.txt","w",stdout);
	int T=rand()%30+1;
    srand(time(0));
    while(T--){
		int n=rand()%N+1;
		assert(n>=1&&n<=N);
		cout<<n<<endl;
		int c=1;
		set<int>s;
		vector<int>v;
		while(s.size()<n){
			int x=rand()*rand()%M+1;
			assert(x>=1&&x<=M);
			s.insert(x);
			if(s.size()==c)v.PB(x),c++;
		}
		assert(s.size()==n);
		assert(v.size()==n);
		for(int i=0;i<(int)v.size();i++){
			cout<<v[i];
			cout<<endl;
		}
	}*/
    
	
	freopen("c405_04.out.txt","w",stdout);
	while(cin>>n){
	    map<int,int>mp;
	    vector<int>v(n),a(n);
	    int t=0;
	    REP(i,n)cin>>a[i],mp[a[i]]=1;
	    for(auto &x:mp)x.S=t++;
	    
	    //for(auto x:mp)cout<<x.F<<"　"<<x.S<<endl;
	    
	    REP(i,n)v[mp[a[i]]]=i;
	    int l=n,r=0,ans=0,c=0;
	    for(int i=0;i<n;i++,c++){
			l=min(l,v[i]);
			r=max(r,v[i]);
			ans=max(ans,r-l-c+2);
		}
		if(n==1)ans=1;
		cout<<ans<<endl;
	}
}
