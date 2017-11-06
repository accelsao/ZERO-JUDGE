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
using namespace std;

unsigned int seed = 0;
unsigned int p_random() { return seed = (seed * 9301 + 49297); }
unsigned int A[5000005];
unsigned dp[5000005][25];
#define scanf scanf_s
int main() {
	int N, M, S, x, y;
	unsigned int hash = 0;
	scanf("%d %d %d", &N, &M, &S);
	seed = S;
	for (int i = 1; i <= N; i++)
		A[i] = p_random();
	for (int i = 1; i <= N; i++)
		dp[i][0] = A[i];
	for (int j = 1; (1 << j) <= N; j++)
		for (int i = 0; i + (1 << j) - 1 <= N; i++)
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	for (int i = 0; i < M; i++) {
		x = p_random() % N + 1, y = p_random() % N + 1;
		if (x > y)	swap(x, y);
		int k = log(y*1.0 - x + 1) / log(2.0);
		hash ^= max(dp[x][k], dp[y - (1 << k) + 1][k]);
	}
	printf("%lu\n", hash);
}
