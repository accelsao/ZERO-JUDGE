```cpp
#include <bits/stdc++.h>
#define ld long double
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
#define endl "\n" 
//#pragma GCC optimize(2)
using namespace std;
//typedef complex<double>C;
//const double PI(acos(-1.0));
//const double eps(1e-8);
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
const int N=3e5+10;
const LL M=1e9+7;
LL n,a,b,k;
LL f[N];//n!
LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}

/*
N=1e5
A=1e5
B=1e5
K=1e10
*/
LL c[N];
int main(){Accel
	freopen("c567_05.out.txt","w",stdout);

	f[0]=1;
	FOR(i,1,3e5){
		f[i]=f[i-1]*i%M;
	}
	
	int T;
	cin>>T;
	while(T--){
		cin>>n>>a>>b>>k;
		
		c[0]=1;
		c[1]=n;
		FOR(i,2,n){
			c[i]=c[i-1]*(n+1-i)%M*pw(i,M-2)%M;
		}	
		LL ans=0;
		FOR(i,0,n){
			LL t=k-a*i;
			if(t<0)continue;
			//cout<<k<<endl;
			if(t%b==0){
				LL j=t/b;
				//cout<<i<<" "<<j<<endl;
				
				if(j<=n){
					ans=ans+c[i]*c[j]%M;
					ans%=M;
				}
			}
		}
		cout<<ans<<endl;
	}
}
```
