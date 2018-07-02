O(nlogn)
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
using namespace std;
const int N=2e5+1;
const int M=1e9+7;
const double eps=1e-6;
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
map<int,int>mp;
int n,q;
int main(){Accel
	cin>>n;
	int ans=0;
	REP(i,n){
		int l,r,k;
		cin>>l>>r>>k;
		auto it=mp.lower_bound(l);
		if(it==mp.end()){
			mp[r]=l;
			ans+=r-l+1;
			cout<<ans<<endl;
			continue;
		}
		while(it!=mp.end()){
			int x=it->S,y=it->F;
			
			
			if(r<x)break;
			
			it=mp.erase(it);
			ans-=y-x+1;
			
			
			if(x<l){
				mp[l-1]=x;
				ans+=l-1-x+1;
			}
			else if(x>l){
				mp[x-1]=l;
				ans+=x-1-l+1;
			}
			if(y<r){
				l=y+1;
			}
			else if(y>r){
				l=r+1;r=y;
			}
			else{
				//delete
				l=r+1;
			}
		}
		if(l<=r){
			mp[r]=l;ans+=r-l+1;
		}
		for(auto x:mp)
			cout<<x.S<<" "<<x.F<<endl;
		cout<<ans<<endl;
		
	}
}
```cpp
