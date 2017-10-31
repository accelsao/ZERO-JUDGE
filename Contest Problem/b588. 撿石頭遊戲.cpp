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
#include <ctime>
#include<cmath>
using namespace std;



char dp[101][101][101] = {};
void update(int a, int b, int c) {
	int i;
	if (a > c)   a = a + c - (c = a);
	if (b > c)   b = b + c - (c = b);
	if (c > 100)    return;
	if (a > b)   a = a + b - (b = a);
	dp[a][b][c] = 1;
}
int main() {
	int i, j, k, a;
	int cnt = 0;
	for (i = 0; i <= 100; i++)
		for (j = i; j <= 100; j++)
			for (k = j; k <= 100; k++)
				if (!dp[i][j][k]) {
					for (a = 1; a + i <= 100; a++) {
						update(i + a, j, k);
						if (a + j <= 200) {
							update(i, j + a, k);
							update(i + a, j + a, k);
						}
						if (a + k <= 200) {
							update(i, j, k + a);
							update(i + a, j, k + a);
							update(i, j + a, k + a);
							update(i + a, j + a, k + a);
						}
					}
				}
	int b, c;
	while (cin >> a >> b >> c, a) {
		if (a > c)   i = a, a = c, c = i;
		if (b > c)   i = b, b = c, c = i;
		if (a > b)   i = a, a = b, b = i;
		if (!dp[a][b][c])
			printf("%c\n", 'l');
		else
			printf("%c\n", 'w');
	}
}
