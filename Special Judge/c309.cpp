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
using namespace std;

map<string, int>m;
map<string, int>p;
int R(string s) {
	if (!m[s])
		m[s] = m.size();
	return m[s];
}
struct state {
	string name, lng, race;
	set<string>g;
	int n;
	int lng_m[15];
	void read(ifstream& in,int k) {
		string s;
		getline(in, s);
		g.clear();
		stringstream ss(s);
		ss >> name >> race >> n;
		p[name] = k;
		for (int i = 0; i < 15; i++)
			lng_m[i] = 0;
		for (int i = 0; i < n; i++) {
			ss >> lng;
			m[lng] = R(lng);
			lng_m[m[lng]] = 1;
		}
		//while (ss >> s)
		for (int i = 0; i < 16; i++) {
			ss >> s;
			g.insert(s);
		}
	}
	int iscom(string a) {
		for (int i = 0; i < 15; i++)
			if (lng_m[i] == lng_m[m[a]])
				return 1;
		return 0;
	}
	int com(state a) {
		for (int i = 0; i < 15; i++)
			if (lng_m[i] && a.lng_m[i])
				return i;
	}

}C[16];
int N;
int main(int argc, char *args[]) {
	ifstream in(args[1]), out(args[3]), ans(args[2]);
	bool f = 0;
	while (in >> N, N) {
		m.clear();
		p.clear();
		for (int i = 0; i < N; i++)
			C[i].read(in,i);
		string a[16][4], b[16][4], c;
		bool ed = 0;
		for (int i = 0; i < N&&!ed; i++) {
			for (int j = 0; j < 4&&!ed; j++) {
				out >> a[i][j], b[i][j];
				if (i + j == 0 && a[0][0] == "IMPOSSIBLE!!!") {
					if (b[0][0] != a[0][0]) 
						f = 1;
					ed = 1;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (C[p[b[i][2]]].g.count(C[p[b[(i - 1 + N) % N][2]]].name) && C[p[b[(i - 1 + N) % N][2]]].g.count(C[p[b[i][2]]].name) && C[p[b[i][2]]].iscom(C[p[b[(i - 1 + N) % N][2]]].race) && C[p[b[(i - 1 + N) % N][2]]].iscom(C[p[b[i][2]]].race))
				if (C[p[b[i][2]]].g.count(C[p[b[(i + 1 + N) % N][2]]].name) && C[p[b[(i + 1 + N) % N][2]]].g.count(C[p[b[i][2]]].name) && C[p[b[i][2]]].iscom(C[p[b[(i + 1 + N) % N][2]]].race) && C[p[b[(i + 1 + N) % N][2]]].iscom(C[p[b[i][2]]].race))
					continue;
				else {
					f = 1;
					break;
				}
			else {
				f = 1; break;
			}
			
		}
		if (f)break;
	}
	if (f) 
		puts("$JUDGE_RESULT=WA\n$MESSAGE=Congratulations~GetWA");	
	else
		puts("$JUDGE_RESULT=AC\n$MESSAGE=Congratulations~GGGetAC");
}
