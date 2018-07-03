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
const int M=1e9+7;
const int inf=1e9+7;
const LL INF=1e18;
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
int N,X,d,Tm;

int main(){Accel

	//freopen("c654_01.out.txt","w",stdout);

	cin>>T;
	while(T--){
		cin>>N>>X>>Tm;
		vector<PII>b(N);
		REP(i,N)
			cin>>b[i].F>>b[i].S;
		while(Tm--)	{
			REP(i,N){
				if(b[i].S)
					b[i].F--;
				else b[i].F++;
				while(b[i].F<0)b[i].F+=X;
				b[i].F%=X;
			}
			sort(ALL(b));
			int j=0;
			for(int i=1;i<N;i++){
				if(b[i].F!=b[j].F){
					if(i!=j+1){
						for(int k=j;k<i;k++)b[k].S^=1;
					}
					j=i;
				}
				
			}
			if(j!=N-1){
				for(int k=j;k<N;k++)b[k].S^=1;
			}
		}
		sort(ALL(b));
		int mx=abs(b[0].F-b[N-1].F);
		
		
		for(int i=1;i<N;i++)
			mx=max(mx,abs(b[i].F-b[i-1].F));
		cout<<mx<<endl;
	}
}
```
