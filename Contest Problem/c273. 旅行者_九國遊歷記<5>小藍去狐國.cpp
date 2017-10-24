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

int main() {
	string s;
	bool ppp = 0;
	while (getline(cin, s)) {
		ppp = 1;

		int a, b;
		a = b = 0;//偶,奇
		for (int i = s.size() - 1; i >= 0; i -= 2) {
			b += s[i] - '0';
			if (i > 0)a += s[i - 1] - '0';
		}
		if (s.size() & 1)
			printf("%d\n", b - a);
		else
			printf("%d\n", a - b);
	}
	if (!ppp)
		puts("I finish the homework.");
}
