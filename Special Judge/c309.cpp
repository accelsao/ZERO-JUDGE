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
	ifstream in(args[1]), out(args[2]), ans(args[3]);
	//ifstream in("c309_05.in.txt"), out("c309_05.out.txt"), ans("c309.txt");
	bool f = 0;
	while (1) {
		string st;
		//getline(in, w);
		//stringstream ww(w);
		//ww >> N;
		in >> N;
		if (!N)break;
		m.clear();
		p.clear();
		getline(in, st);
		for (int i = 0; i < N; i++) {
			string s;
			getline(in, st);
			C[i].g.clear();
			stringstream ss;
			ss << st;
			//in >> C[i].name >> C[i].race >> C[i].n;
			ss >> C[i].name >> C[i].race >> C[i].n;
			p[C[i].name] = i;
			for (int j = 0; j < 15; j++)
				C[i].lng_m[j] = 0;
			for (int j = 0; j < C[i].n; j++) {
				//in >> C[i].lng;
				ss >> C[i].lng;
				m[C[i].lng] = R(C[i].lng);
				C[i].lng_m[m[C[i].lng]] = 1;
			}
			while (ss >> s)
				C[i].g.insert(s);
		}
		string a[16][4], b[16][4], c;
		bool eda = 0, edb = 0;
		for (int i = 0; i < N; i++) {
			string s;
			getline(out, s);
			stringstream ss; ss.clear(); ss.str(s);
			for (int j = 0; j < 4; j++)
				ss >> a[i][j];
			if (a[0][0] == "IMPOSSIBLE!!!")
				break;
		}
		for (int i = 0; i < N; i++) {
			string s;
			getline(ans, s);
			stringstream ss; ss.clear(); ss.str(s);
			for (int j = 0; j < 4; j++)
				ss >> b[i][j];
			if (b[0][0] == "IMPOSSIBLE!!!")
				break;
		}
		bool ed = 0;
		if (a[0][0] == "IMPOSSIBLE!!!") {
			if (b[0][0] != a[0][0])
				f = 1;
			else
				ed = 1;
		}
		else if (b[0][0] == "IMPOSSIBLE!!!") 
			f = 1;
		for (int i = 0; i < N&&!f&&!ed; i++) {
			if (C[p[b[i][2]]].g.count(C[p[b[(i - 1 + N) % N][2]]].name) && C[p[b[(i - 1 + N) % N][2]]].g.count(C[p[b[i][2]]].name) && C[p[b[i][2]]].iscom(C[p[b[(i - 1 + N) % N][2]]].race) && C[p[b[(i - 1 + N) % N][2]]].iscom(C[p[b[i][2]]].race)&&b[i][1]== C[p[b[(i - 1 + N) % N][2]]].race&&b[(i - 1 + N) % N][3] == C[p[b[i][2]]].race)
				if (C[p[b[i][2]]].g.count(C[p[b[(i + 1 + N) % N][2]]].name) && C[p[b[(i + 1 + N) % N][2]]].g.count(C[p[b[i][2]]].name) && C[p[b[i][2]]].iscom(C[p[b[(i + 1 + N) % N][2]]].race) && C[p[b[(i + 1 + N) % N][2]]].iscom(C[p[b[i][2]]].race) && b[i][3] == C[p[b[(i + 1 + N) % N][2]]].race&&b[(i + 1 + N) % N][1] == C[p[b[i][2]]].race)
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
