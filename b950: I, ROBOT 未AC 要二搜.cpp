#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<string>
#include<vector>
using namespace std;

vector<int>p[2][1000001];
vector<int>::iterator it;
int s[2][1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	int x, y;
	int m, a, b;
	cin >> x >> y;
	cin >> m;
	while (m--) {
		cin >> a >> b;
		p[0][a].push_back(b);//橫的
		p[1][b].push_back(a);//直的 
		s[0][a] = s[1][b] = 1;
	}

	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++)
			if (s[i][j])
				sort(p[i][j].begin(), p[i][j].end());

	cin >> m;
	int w, d;
	while (m--) {
		cin >> w >> d;
		int ss;
		if (w == 3) {
			if (p[0][x].size()) {
				if (y > p[0][x].back())
					ss = y + d;
				else
					ss = *upper_bound(p[0][x].begin(), p[0][x].end(), y);
				y = min(ss, y + d);
			}
			else
				y = min(y + d, n);
		}
		else if (w == 4) {
			d = -d;
			if (p[0][x].size()) {
				if (y > p[0][x].back())
					ss = p[0][x].back();
				else {
					if (y < p[0][x][0])
						ss = 0;
					else {
						it=lower_bound(p[0][x].begin(), p[0][x].end(), y);
						it--;
						ss = *it;
					}
				}
				y = max(ss, y + d);
			}
			else
				y = max(y + d, 1);
		}
		else if (w == 1) {
			if (p[1][y].size()) {
				if (x > p[1][y].back())
					ss = x + d;
				else
					ss = *upper_bound(p[1][y].begin(), p[1][y].end(), x);
				x = min(ss, x + d);
			}
			else
				x = min(x + d, n);
		}
		else {
			d = -d;
			if (p[1][y].size()) {
				if (x > p[1][y].back())
					ss = p[1][y].back();
				else {
					if (y < p[1][y][0])
						ss = 0;
					else {
						it = lower_bound(p[1][y].begin(), p[1][y].end(), x);
						it--;
						ss = *it;
					}
				}
				x = max(ss, x + d);
			}
			else
				x = max(x + d, 1);
		}
		printf("%d %d\n", x, y);
	}
}
