#include<iostream>
#include<string>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
using namespace std;

//set<>讀不到東西


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
int main(int argc, char *args[]){
	ifstream in(args[1]), out(args[3]), fk(args[2]);
	map<string, int>mp;
	while (in >> N){
		if (N == 0)break;
		m.clear();
		mp.clear();
		string q, w, e, qq;
		string b[15][4],g[15][4];
		bool f = 0, ed = 0;
		for (int k = 0; k < N; k++){
			getline(in, q);
			C[k].g.clear();
			stringstream ss(q);
			//ss >> C[k].name >> C[k].race >> C[k].n;
			//mp[C[k].name] = k;
			/*for (int i = 0; i < 15; i++)
				C[k].lng_m[i] = 0;
			for (int i = 0; i < C[k].n; i++){
				ss >> C[k].lng;
				m[C[k].lng] = R(C[k].lng);
				C[k].lng_m[m[C[k].lng]] = 1;
			}*/
			while (ss >> q)
				C[k].g.insert(q);
		}
		for (int i = 0; i < N; i++){
			if (ed)break;
			getline(out, w);
			getline(fk, e);
			stringstream ss(w);
			stringstream tt(e);
			for (int j = 0; j < 4 && !ed; j++){
				ss >> b[i][j];
				tt >> g[i][j];
				if (i + j == 0 && b[0][0] == "IMPOSSIBLE!!!\n"){
					if (b[0][0] == g[0][0]){
						puts("$JUDGE_RESULT=AC\n$MESSAGE=Congratulations~GetAC");
						ed = 1;
					}
					else
						puts("$JUDGE_RESULT=WA\n$MESSAGE=Congratulations~getWA");
					f = 1;
				}			
			}
		}
		bool ck = 0;
		if (!f){//要檢查 out 給b[][]
			for (int i = 0; i < N&&!ck; i++){

				//if (C[mp[b[i][2]]].g.size()<1)
				if (C[i].g.size()<1)
					ck = 1;
				/*if (!C[mp[b[i][2]]].g.count(C[mp[b[(i - 1 + N) % N][2]]].name) || !C[mp[b[(i - 1 + N) % N][2]]].g.count(C[mp[b[i][2]]].name)){
					ck = 1;
				}
				else if (!C[mp[b[i][2]]].iscom(C[mp[b[(i - 1 + N) % N][2]]].race) || !C[mp[b[(i - 1 + N) % N][2]]].iscom(C[mp[b[i][2]]].race))
					ck = 1;
				else if (!C[mp[b[i][2]]].g.count(C[mp[b[(i + 1) % N][2]]].name) || !C[mp[b[(i + 1) % N][2]]].g.count(C[mp[b[i][2]]].name)){
					ck = 1;
				}
				else if (!C[mp[b[i][2]]].iscom(C[mp[b[(i + 1) % N][2]]].race) || !C[mp[b[(i + 1) % N][2]]].iscom(C[mp[b[i][2]]].race))
					ck = 1;*/
			}
			if (ck)
				puts("$JUDGE_RESULT=WA\n$MESSAGE=Congratulations~GetWA");
			else
				puts("$JUDGE_RESULT=AC\n$MESSAGE=Congratulations~GGGetAC");
		}
	}
	in.close(), out.close(), fk.close();
}
