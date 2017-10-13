#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;



struct state {
	long long d, step;
	state* pre;
	void init() {
		d = 9e18, step = 0, pre = 0;
	}
};
char m[25][25];
string dstr[8] = { "E", "ES", "S", "WS", "W", "WN", "N", "EN" };
long long p[25][2];//pick carry
int r, c, t;
int sx, sy, ex, ey;
state dis[20][20][1 << 11];
int v[20][20][1 << 11];
long long w[1 << 11], walk, G;
const int dw[8][2] = { { 0, 1 },{ 1, 1 },{ 1, 0 },{ 1, -1 },{ 0, -1 },{ -1, -1 },{ -1, 0 },{ -1, 1 } };
void spfa() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			for (int k = 0; k < (1 << t); k++)
				dis[i][j][k].init(), v[i][j][k] = 0;
	w[0] = 0;
	for (int i = 1; i < (1 << t); i++) {
		long long sum = 0, k = i, j = 0;
		while (k) {
			if (k & 1)
				sum += p[j][1];
			k >>= 1; j++;
		}
		w[i] = sum;//各種集合 攜帶時所消耗的能量
	}
	int tx, ty, ts, ss;
	queue<int>X, Y, S;
	dis[sx][sy][0].d = 0;
	X.push(sx), Y.push(sy), S.push(0);
	while (!X.empty()) {
		sx = X.front(), X.pop();
		sy = Y.front(), Y.pop();
		ss = S.front(), S.pop();
		v[sx][sy][ss] = 0;
		for (int k = 0; k < 8; k++) {
			tx = sx + dw[k][0]; ty = sy + dw[k][1]; ts = ss;
			if (tx < 0 || ty < 0 || tx >= r || ty >= c || m[tx][ty] == '#')continue;
			long long rg = 0;
			if (m[tx][ty] == '@')rg = walk;
			else if (m[tx][ty] == '.')rg = w[ss] + walk;
			if (dis[tx][ty][ts].d > dis[sx][sy][ss].d + rg) {
				dis[tx][ty][ts].d = dis[sx][sy][ss].d + rg;
				dis[tx][ty][ts].pre = &dis[sx][sy][ss];
				dis[tx][ty][ts].step = 1 << k;
				if (!v[tx][ty][ts]) {
					v[tx][ty][ts] = 1;
					X.push(tx), Y.push(ty), S.push(ts);
				}
			}
			if (m[tx][ty] >= '0'&&m[tx][ty] <= '9') {
				ts = ss | (1 << (m[tx][ty] - '0'));
				if (dis[tx][ty][ts].d > dis[sx][sy][ss].d + w[ss] + walk + p[m[tx][ty] - '0'][0]) {
					dis[tx][ty][ts].d = dis[sx][sy][ss].d + w[ss] + walk + p[m[tx][ty] - '0'][0];
					dis[tx][ty][ts].pre = &dis[sx][sy][ss];
					dis[tx][ty][ts].step = (1 << k) | (1 << 8);
					if (!v[tx][ty][ts]) {
						v[tx][ty][ts] = 1;
						X.push(tx), Y.push(ty), S.push(ts);
					}
				}
			}
		}
	}
	//in
	/*
	if (dis[ex][ey][(1 << t) - 1].d == 9e18)
		G = 9487;
	else {
		G = dis[ex][ey][(1 << t) - 1].d + rand() % 4 - 1;
	}
	printf("%lld\n", G);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if ('0' <= m[i][j]&&m[i][j] <= '9')
				m[i][j] = '*';
			cout << m[i][j];
		}
		cout << endl;
	}
	printf("%lld\n", walk);
	for (int i = 0; i < t; i++) {
		if (i)putchar(' ');
		printf("%d %d", p[i][0], p[i][1]);
	}
	puts("");
	*/
	///*
	if (dis[ex][ey][(1 << t) - 1].d == 9e18)
		puts("Dead");
	else {
		printf("Time required %lld\n", dis[ex][ey][(1 << t) - 1].d);
		if (dis[ex][ey][(1 << t) - 1].d <= G)puts("Save");
		else puts("Not even close");
		state *p = &dis[ex][ey][(1 << t) - 1];
		string ans = "";
		while (p) {
			if ((p->step >> 8) & 1) 
				ans = " " + ans, ans = "P" + ans;
			for (int k = 0; k < 8; k++)
				if (((p->step) >> k) & 1)
					ans = " " + ans, ans = dstr[k] + ans;
			p = p->pre;
			
		}
		puts(ans.c_str());
	}
	//*/
}
char d[7] = { 'S','T','.','#','O','@','*' };
int main() {
	FILE *s;
	/*
	freopen_s(&s, "c301_02.in.txt", "w", stdout);
	int tt = 3;
	while (tt--) {
		srand(tt+132);
		r = 20;
		c = 20;
		printf("%d %d\n", r, c);
		int tr = 10;
		t = 0;
		char R[410] = {};
		for (int i = 0; i < r*c; i++)R[i] = '!';
		int Run = r*c, top = 2 + tr;
		for (int ii = 0; ii < Run;ii++) {
			int s = rand()*777 % r*c;
			while (R[s] != '!') {
				long long S = rand()*17 % 10 + 1;
				s += S < 1 ? 1 : S; S--;
				s = s >= r*c ? 0 : s;
			}
			if (ii < top) {
				R[s] = !ii ? 'S' : ii == 1 ? 'T' : '*';
				int i = s / c, j = s%c;
				
				if (R[s] == 'S')sx = i, sy = j;
				if (R[s] == 'T')ex = i, ey = j;
				m[i][j] = R[s];
				if (R[s] == '*')
					m[i][j] = '0' + t++;
			}
			else {
				R[s] = d[rand() *111 % 4 + 2];
				int i = s / c, j = s%c;
				m[i][j] = R[s];
			}
		}
		walk = 1147483647;
		//pair<int, int>poi[10];
		for (int i = 0; i < t; i++) {
			p[i][0] = rand() * 21 % 122 + 30;
			p[i][1] = rand() * 33 % 832 + 1;
		}
		spfa();
	}
	puts("0 0");
   */
	///*
	freopen_s(&s, "c301_02.out.txt", "w", stdout);
	while (cin >> r >> c, r + c) {
		cin >> G;
		t = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> m[i][j];
		cin >> walk;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if (m[i][j] == '*') {
					m[i][j] = t + '0';
					cin >> p[t][0] >> p[t][1];
					t++;
				}
				if (m[i][j] == 'S')sx = i, sy = j;
				if (m[i][j] == 'T')ex = i, ey = j;
			}
		spfa();
	}
	//*/
}

