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
#include<unordered_map>
#include<stack>
using namespace std;

//r,c 最多8
int r, c;
char a[8][8], ans[8][8], grid[8][8];
bool solve;
map<long long, int>dp[8][8][2];
const char ch[2] = { 'o','x' };
int ma, mb;
struct state {
	bool color[8];
	bool up_left;
	int ncomps, comp[8];
	int color_ncomps[2];
	void normalize() {
		int ret[9];
		for (int i = 0; i < 9; i++)
			ret[i] = -1;
		ncomps = color_ncomps[0] = color_ncomps[1] = 0;
		for (int i = 0; i < c; i++) {
			if (ret[comp[i]] == -1) {
				ret[comp[i]] = ncomps++;
				color_ncomps[color[i]]++;
			}
			comp[i] = ret[comp[i]];
		}
	}
	 long long encode() {
		 long long key = 0;
		for (int i = 0; i < c; i++)
			key = key * 16 + 8 * color[i] + comp[i];
		return key;
	}
	void merge(int a, int b) {
		if (a == b)return;
		for (int i = 0; i < c; i++)
			if (comp[i] == b)
				comp[i] = a;
	}
};
unsigned long long DP(int row, int col, state & S, int force_color) {
	if (col == c) row++, col = 0;
	S.normalize();
	if (row == r) {
		if (S.color_ncomps[0] > ma || S.color_ncomps[1] >mb)//白 黑
			return 0;
		if (!solve) {
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					ans[i][j] = grid[i][j];
			solve = 1;
		}
		return 1;
	} 
	if (row > 0 && col > 0 && S.color[col] != S.color[col - 1])
		S.up_left = 0;
	long long key;
	if (force_color < 0)
		key = S.encode();
	if (force_color < 0 && dp[row][col][S.up_left].count(key))
		return dp[row][col][S.up_left][key];
	int ret = 0;
	for (int color = 0; color<2; color++) {
		if (force_color == (color ^ 1))  	continue;
		if (a[row][col] == ch[color ^ 1]) continue;
		//Scolor[col] 上 col-1 左 upleft 左上
		if (row>0 && col>0 && color == S.color[col] && color == S.color[col - 1] && color == S.up_left)  continue;//避免2X2
		grid[row][col] = ch[color];
		state T = S;
		T.color[col] = color;
		T.up_left = S.color[col];
		T.comp[col] = row>0 && S.color[col] == color ? S.comp[col] : S.ncomps;
		if (col>0 && S.color[col - 1] == color)
			T.merge(T.comp[col - 1], T.comp[col]);
		if (row>0 && S.color[col] != color) {
			if (find(T.comp, T.comp + c, S.comp[col]) == T.comp + c) {
				if (row<r - 2)  continue;
				if (!color&&S.color_ncomps[color^1] > mb)
					continue;
				else if (color&&S.color_ncomps[color^1] > ma)
					continue;		
				ret += DP(row, col + 1, T, color);
				continue;
			}
		}
		ret += DP(row, col + 1, T, force_color);
	}
	if (force_color < 0)
		dp[row][col][S.up_left][key] = ret;
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> r >> c;
		cin >> ma >> mb;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				cin >> a[i][j];
				dp[i][j][0].clear(), dp[i][j][1].clear();
			}
		solve = 0;
		state S;
		memset(&S, 0, sizeof S);
		printf("%llu\n", DP(0, 0, S, -1));
		if (solve)
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++)
					printf("%c", ans[i][j]);
				puts("");
			}
	}
}
/*
r,c最多8
ma mb 最多3
代表 可連通的分量
ma 白
mb 黑
輸出可能數量
輸出任一種可能
ox 不能出現2X2
然後要塗滿
--
5
2 3
1 1
o..
.##
5 5
2 1
..#..
o....
o...o
o....
.#...
4 5
3 3
.....
..o..
#....
.....
2 3
1 1
###
oo#
6 8
1 1
........
........
........
........
.#......
........
------
4
ooo
oxx
263
ooxoo
oxxxo
oooxo
oxoxo
oxxxo
1130
ooooo
oxoxo
xxoxo
ooooo
1
xxx
oox
71582
oooooooo
oxoxoxox
oxoxoxox
oxoxoxox
oxoxoxox
oxxxxxxx
---
10572
*/
