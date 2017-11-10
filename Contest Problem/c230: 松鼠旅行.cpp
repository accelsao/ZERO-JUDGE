#include<iostream>
#include<algorithm>
using namespace std;

struct point {
	double d;
	int h;
}p[100001];
double dis(double a, double b) {
	return sqrt(a*a + b*b);
}
bool cmp(point a,point b){
	if (a.d == b.d)return a.h > b.h;
	return a.d < b.d;
}
int L[100001];
int R[100001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			double x, y; int a;
			cin >> x >> y >> a;
			p[i].d = dis(x, y);
			p[i].h = a;
		}
		sort(p, p + n, cmp);
		L[0] = p[0].h;
		for (int i = 1; i < n; i++)
			L[i] = max(p[i].h, L[i - 1]);
		R[n - 1] = p[n - 1].h;
		for (int i = n - 2; i >= 0; i--)
			R[i] = min(R[i + 1], p[i].h);
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
			sum = max(sum, L[i] - R[i]);
		printf("%d\n", sum);
	}
}
