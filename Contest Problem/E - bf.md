```cpp
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
#define SZ(a) ((int)a.size())
//#pragma GCC optimize(2)
using namespace std;
const int N=1e6+1;
const int M=1e9+7;
const int inf=1e9+7;
const LL INF=1e18;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
int T;
int n;
int a[N];
int b[N];
int main(){Accel

//	freopen("c655_01.out.txt","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int p;
		FOR(i,1,n){
			cin>>a[i];
			if(a[i]==n)p=i;
		}
		int ans=n*n;
		FOR(k,1,n){
			FOR(i,1,n)b[i]=a[i];
			if(p>k){
				for(int i=p-1;i>=k;i--)
					swap(b[i+1],b[i]);
			}
			else{
				for(int i=p+1;i<=k;i++)
					swap(b[i],b[i-1]);
			}
			int t=abs(p-k);
			
			//FOR(i,1,n)
			//	cout<<b[i]<<" ";cout<<endl;
			
			vector<int>v;
			for(int i=k-1;i>=1;i--){
				for(auto x:v)
					if(b[i]>x)t++;
				v.PB(b[i]);
			}
			v.clear();
			for(int i=k+1;i<=n;i++){
				for(auto x:v)
					if(b[i]>x)t++;
				v.PB(b[i]);
			}
			//cout<<t<<endl;
			ans=min(ans,t);
			
			
		}
		cout<<ans<<endl;
	}
}
```
