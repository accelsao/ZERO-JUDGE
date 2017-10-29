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
#include<vector>
using namespace std;

char dp[201][201][201] = {};
void update(int a, int b, int c) {
	int i;
	if (a > c)   a = a + c - (c = a);
	if (b > c)   b = b + c - (c = b);
	if (c > 200)    return;
	if (a > b)   a = a + b - (b = a);
	dp[a][b][c] = 1;
}
int main() {
	int i, j, k, a;
	int cnt = 0;
	for (i = 0; i <= 200; i++)
		for (j = i; j <= 200; j++)
			for (k = j; k <= 200; k++)
				if (!dp[i][j][k]) {
					printf("%d %d %d\n", i, j, k);
					for (a = 1; a <= 200; a++) {
						update(i + a, j, k);
						update(i, j + a, k);
						update(i, j, k + a);
						update(i + a, j + a, k);
						update(i + a, j, k + a);
						update(i, j + a, k + a);
						update(i + a, j + a, k + a);
					}
				}
}
