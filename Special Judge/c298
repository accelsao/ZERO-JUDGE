#include<iostream>
#include<string>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

//還要檢查友好
struct pp{
	int to, u; 
	char c;
};
bool cmp(pp a, pp b){
	if (a.to == b.to)
		return a.c < b.c;
	return a.to < b.to;
}
vector<pp>g[103];
int main(int argc, char *args[]){
	ifstream in(args[1]), out(args[2]), ans(args[3]);
	int T, n, m;
	in >> T;
	string ot, as;
	bool Wa = 0;
	while (T--){
		getline(out, ot); getline(ans, as);
		if (ot == "Game Over"){	
			if (as != ot){
				Wa = 1;
				puts("$JUDGE_RESULT=WA\n$MESSAGE=Congratulations~GetWA");
				break;
			}
			else{
				int a, b, n, m; char c;
				in >> n >> m;
				for (int i = 0; i < m; i++)
					in >> a >> b >> c;
				continue;
			}
		}
		else if (as == "Game Over"){
			Wa = 1;
			puts("$JUDGE_RESULT=WA\n$MESSAGE=Congratulations~GetWA");
			break;
		}
		in >> n >> m;
		for (int i = 1; i <= n; i++){
			g[i].clear();
		}
		int a, b; char c;
		for (int i = 0; i < m; i++){
			in >> a >> b >> c;
			g[a].push_back(pp{ b, 0, c });
		}
		for (int i = 1; i <= n; i++){
			sort(g[i].begin(), g[i].end(), cmp);
		}
		int u, v;
		stringstream ss;
		ss.clear();
		ss.str(as);
		ss >> u;
		bool f = 0;
		while (ss >> v&&!f){
			bool df = 0;
			for (int i = 0; i < g[u].size(); i++)
				if (g[u][i].u == 0 && g[u][i].to == v){
					g[u][i].u = 1;
					u = v;
					df = 1;
					break;
				}
			if (df)continue;
			for (int i = 0; i < g[v].size(); i++)
				if (g[v][i].u == 0 && g[v][i].to == u&&g[v][i].c == 'U'){
					g[v][i].u = 1;
					u = v;
					df = 1;
					break;
				}
			if (df)continue;
			Wa = 1;
			puts("$JUDGE_RESULT=WA\n$MESSAGE=Congratulations~GetWA");
			f = 1;
			break;
		}
		if (f)
			break;
	}
	if (!Wa)
		puts("$JUDGE_RESULT=AC\n$MESSAGE=Congratulations~GetAC");
	in.close(), out.close(), ans.close();
}
