#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
using namespace std;

long long sg(long long x) {//上表觀察所得到的規律
	return x & 1 ? sg(x / 2) : x / 2;
}
const long long M = 1LL << 60;
/*
N=100
S or N
x,y 1<<30
G
A k<=max(x,y)
B
*/
/*
3
S
2 2 G
1 1 A 3
2 3 B
2
S
1 1 A 3
1 0 A 4
2
N
1 1 A 3
1 0 A 4
0
*/
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	FILE *f;
	/*
	freopen_s(&f, "c347_03.in.txt", "w", stdout);
	int TN = 0, TP = 0, G = 0, aa = 10;
	while (TN+TP<aa) {
		G++;
		srand(time(0) + G);
		int n = 1000;
		char s = rand() % 2 ? 'S' : 'N';
		const int sd = 2001;
		long long ans = 0, f = 0, z = 0, r[sd], x[sd], y[sd], d[sd];
		long long k = 0;
		char c[sd];
		int rc = 0;
		for (int i = 0; i < n; i++) {
			x[i] = rand() % M, y[i] = rand() % M;
			//cout << x << ' ' << y;
			k = max(max(x[i], y[i]), k);
			char w[3] = { 'A','B','G' };
			int p = rand() % 3;
			//cout << ' ' << w[p];
			if (w[p] == 'A')
				r[rc] = rand() % k + 1;
				//cout << ' ' << rand() % k + 1;
			//cout << '\n';
			c[i] = w[p];
			if (c[i] == 'A') {
				d[i] = (x[i] % (r[rc] + 1)) ^ (y[i] % (r[rc] + 1));
				rc++;
			}
			else if (c[i] == 'B')
				d[i] = (x[i] & 1) ^ (y[i] & 1);
			else if (c[i] == 'G')
				d[i] = sg(x[i]) ^ sg(y[i]);
			f |= d[i] > 1;
			if (d[i] == 1)
				z++;//算1的個數
			ans ^= d[i];
		}
		bool df = 0;
		if (s == 'N' || f) {//有>1情況 or 正面nim
			//puts(ans ? "N" : "P");
			if (!ans) {
				df = 1;
			}
			else
				df = 0;			
		}
		else {//沒有則判斷 奇偶
			//puts(z & 1 ? "P" : "N");
			if (z & 1)
				df = 1;
			else
				df = 0;
		}
		if (df&&TP >= 5)
			continue;
		if (!df&&TN >= 5)
			continue;
		if (df) {
			TP++;
			//cout << s << ' ' << f <<' '<<ans<< endl;
		}
		else 
			TN++;
		cout << n << '\n' << s << '\n';
		rc = 0;
		for (int i = 0; i < n; i++) {
			cout << x[i] << ' ' << y[i] << ' ' << c[i];
			if (c[i] == 'A')
				cout << ' ' << r[rc++];
			cout << "\n";
		}
	}
	cout << "0\n";
	*/
	///*
	freopen_s(&f, "c347_04.out", "w", stdout);
	
	int n;
	char s;
	while (cin >> n,n) {
		cin >> s;
		long long ans = 0, x, y, r, f = 0, z = 0;
		char c;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> c;
			if (c == 'A') {
				cin >> r;
				x = (x % (r + 1)) ^ (y % (r + 1));
			}
			else if (c == 'B')
				x = (x & 1) ^ (y & 1);
			else if (c == 'G')
				x = sg(x) ^ sg(y);
			f |= x > 1;
			if (x == 1)
				z++;//算1的個數
			ans ^= x;
		}
		if (s == 'N' || f)//有>1情況 or 正面nim
			puts(ans ? "N" : "P");
		else//沒有則判斷 奇偶
			puts(z & 1 ? "P" : "N");
	}
	//*/
}

/*
int mex[1024] = {}, SG[50][50];
SG[0][0] = 0;
for (int i = 0; i < 10; i++)
for (int j = 0; j < 10; j++) {
memset(mex, 0, sizeof(mex));
for (int k = 1; k <= i; k++) {
mex[SG[i - k][j]] = 1;//在後繼集合為1
}
for (int k = 1; k <= j; k++) {
mex[SG[i][j - k]] = 1;//在後繼集合為1
}
int sg = 0;
for (sg = 0; mex[sg]; sg++);//不在集合中的最小值 為sg值
SG[i][j] = sg;
printf("%d %d : %d\n", i,j, SG[i][j]);
}
*/
