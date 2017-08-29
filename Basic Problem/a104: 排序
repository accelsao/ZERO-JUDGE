#include<iostream>
#include<sstream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<map>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
#include<set>
#include<functional>
#include<list>
#include<stack>
#include<cstring>
#include<utility>
#include <climits>
using namespace std;
#define printf printf_s
#define sprintf sprintf_s
#define sscanf sscanf_s
#define scanf scanf_s

int p[1001]={};
void quicksort(int L,int R){
    if(L<R){
        int M=p[(L+R)>>1];
        int i=L-1,j=R+1;
        while(i<j){
            do ++i; while (p[i] < M);
            do --j; while (p[j] > M);
            if (i < j) swap(p[i],p[j]);
            }
        quicksort(L,i-1);
        quicksort(j+1,R);
    }    
}
int main(){
    int n;
    while(cin>>n){
    for(int i=0;i<n;i++)
    cin>>p[i];
    quicksort(0,n-1);
    for(int i=0;i<n;i++)
    cout<<p[i]<<' ';
    cout<<endl;
    }
}

sample input
6
7 9 0 4 1 8
output
0 1 4 7 8 9
zj / a104
