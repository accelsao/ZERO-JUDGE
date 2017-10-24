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


int N;
map<string, int>m;
int R(string s){
	if (!m[s])
		m[s] = m.size();
	return m[s];
}
struct state{
	string name, lng, race;
	set<string>g;
	int n;
	int lng_m[15];
	void read(){
		string s;
		getline(cin, s);
		g.clear();
		stringstream ss(s);
		ss >> name >> race >> n;
		for (int i = 0; i < 15; i++)
			lng_m[i] = 0;
		for (int i = 0; i < n; i++){
			ss >> lng;
			m[lng] = R(lng);
			lng_m[m[lng]] = 1;
		}
		while (ss >> s)
			g.insert(s);
	}
	int iscom(string a){
		for (int i = 0; i < 15; i++)
			if (lng_m[i] == lng_m[m[a]])
				return 1;
		return 0;
	}
	int com(state a){
		for (int i = 0; i < 15; i++)
			if (lng_m[i] && a.lng_m[i])
				return i;
	}

}C[16];
struct P{
	int d, p;
};
int g[16][16];
P dp[1 << 16][16];
bool tsp(int s, int p){
	if (dp[s][p].d != -1)return dp[s][p].d;
	int &ans = dp[s][p].d;
	ans = 0;
	for (int i = 0; i < N; i++)
		if (s&(1 << i) && g[p][i]){
			int f = tsp(s ^ (1 << i), i);
			if (!f)continue;
			dp[s][p].p = i;
			return 1;
		}
	return 0;
}
int main(){
	//ios::sync_with_stdio(0); cin.tie(0);
	FILE* s;
	
	string name[15] = { "Momonga", "Albedo", "Shalltear_Bloodfallen", "Gargantua", "Cocytus", "Aura_Bella_Fiora", "Mare_Bello_Fiore", "Demiurge",
		"Victim", "Sebas_Tian", "Yuri_Alpha", "Lupusregina_Beta", "Narberal_Gamma", "CZ2128_Delta", "Solution_Epsilon" };
	string race[9] = { "Undead", "Evil", "Vampire", "Insect_Warrior", "Human", "Angel", "Zombie", "Werewolf", "Phantom" };

	
	/*freopen_s(&s, "c309_04.in.txt", "w", stdout);

	int T = 300;
	while (T--){
		vector<pair<string, string>>nmr;
		srand(T + 963);
		N = 15;
		printf("%d\n", N);
		int c = rand() % 15;
		for (int i = c; i < c + N; i++)
			nmr.push_back({ name[i % 15], race[rand() * 67 % 9] });
		for (int k = 0; k < N; k++){
			cout << nmr[k].first << ' ' << nmr[k].second << ' ';
			int n = 5;
			cout << n << ' ';
			bool cnt[15] = {};
			cout << nmr[(k - 1 + N) % N].second << ' ';
			if (nmr[(k - 1 + N) % N].second == nmr[(k + 1) % N].second)
				cout << race[rand() * 313 % 9] << ' ';
			else
				cout << nmr[(k + 1) % N].second << ' ';
			for (int i = 2; i < n; i++){
				int c = rand() * 31 % 9;
				while (cnt[c] || race[c] == nmr[(k - 1 + N) % N].second || race[c] == nmr[(k + 1) % N].second)c++, c = c > 8 ? 0 : c;
				cout << race[c] << ' ';
				cnt[c] = 1;
			}
			//輸出友好國家
			n = N - 1;
			cout << nmr[(k + 1) % nmr.size()].first << ' ';
			cout << nmr[(k - 1 + nmr.size()) % nmr.size()].first << ' ';
			for (int i = 0; i < 15; i++)
				cnt[i] = 0;
			for (int i = 2; i < n; i++){
				int c = rand() * 23 % nmr.size();
				while (cnt[c] || nmr[c].first == nmr[(k + 1) % nmr.size()].first || nmr[c].first == nmr[(k - 1 + nmr.size()) % nmr.size()].first)c++, c = c >= nmr.size() ? 0 : c;
				if (i)cout << ' ';
				cout << nmr[c].first;
				cnt[c] = 1;
			}
			puts("");
		}
	}
	puts("0");
	*/
	
	freopen_s(&s, "c309_04.out.txt", "w", stdout);
	while (cin >> N, N){
		getchar();
		m.clear();
		for (int i = 0; i < N; i++)
			C[i].read();
		memset(g, 0, sizeof(g));
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
				if (C[i].g.count(C[j].name) && C[j].g.count(C[i].name) && C[i].iscom(C[j].race) && C[j].iscom(C[i].race))
					g[i][j] = g[j][i] = 1;
		for (int i = 0; i < (1 << N); i++)
			for (int j = 0; j < N; j++)
				dp[i][j].d = -1;
		dp[0][0].d = 1;
		if (tsp((1 << N) - 1, 0)){
			int p = (1 << N) - 1, q = 0;
			int s[15];
			for (int i = 0; i < N; i++){
				s[i] = q;
				q = dp[p][q].p;
				p ^= (1 << q);
			}
			for (int i = 0; i < N; i++){
				cout << i + 1 << ' ';
				cout << C[s[(i - 1 + N) % N]].race << " ";
				cout << C[s[i]].name << " ";
				cout << C[s[(i + 1 + N) % N]].race << '\n';
			}
		}
		else
			cout << "IMPOSSIBLE!!!\n";
	}
}
