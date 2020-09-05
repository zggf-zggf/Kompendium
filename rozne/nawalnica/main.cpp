#include <bits/stdc++.h>

using namespace std;
vector<int> glb, parent, ranga, roz;
vector<vector<int>> jmp, val;
int n, maksiroz = 0;
vector<vector<pair<int, int>>> graf;

int find(int x){
	if(parent[x]==-1) return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void join(int a, int b){
	int va = find(a), vb = find(b);
	if(va==vb) return;
	if(ranga[va]>ranga[vb]){
		parent[vb] = va;
		roz[va]+=roz[vb];
	}else if(ranga[va]<ranga[vb]){
		parent[va] = vb;
		roz[vb]+=roz[va];
	}else{
		ranga[va]++;
		parent[vb] = va;
		roz[va]+=roz[vb];
	}
	maksiroz = max(maksiroz, max(roz[va], roz[vb]));
}

void dfs(int x, int prnt = -1, int lvl = 0){
	jmp[x][0] = prnt;
	glb[x] = lvl;
	int pt = prnt;
	int v = 0;
	for(int i = 1; i < 20; i++){
		if(pt==-1)break;
		jmp[x][i] = jmp[pt][i-1];
		val[x][i] = max(val[x][i-1], val[pt][i-1]);
		pt = jmp[x][i];
	}
		
	for(auto it:graf[x]){
		if(val[it.first][0]==-1){
			val[it.first][0] = it.second;	
			dfs(it.first, x, lvl+1);
		}
	}
}

int lca(int a, int b){
	if(glb[a]<glb[b]) swap(a, b);
	int maksi = 0;
	for(int i = 19; i >= 0; i--){
		if(glb[a]-(1<<i)>=glb[b]){
			maksi = max(maksi, val[a][i]);
			a = jmp[a][i];		
		}
	}
	if(a==b) return maksi;
	for(int i = 19; i >= 0; i--){
		if(jmp[a][i]!=jmp[b][i]){
			maksi = max(maksi, max(val[a][i], val[b][i]));
			a=jmp[a][i]; b=jmp[b][i];
		}
	}
	maksi = max(maksi, max(val[a][0], val[b][0]));
	return maksi;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int m; cin>>n>>m;
	vector<pair<int, pair<int, int>>> inp;
	glb.resize(n+1);
	parent.resize(n+1, -1); roz.resize(n+1, 1); ranga.resize(n+1);
	jmp.resize(n+1, vector<int>(20, -1));
	graf.resize(n+1);
	val.resize(n+1, vector<int>(20, -1));
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin>>a>>b>>c;
		inp.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(inp.begin(), inp.end());
	int lst = 0;
	long long sum = 0;
	for(int i = 0; i < inp.size(); i++){
		int a = inp[i].second.first, b = inp[i].second.second, c = inp[i].first;
		if(find(a)!=find(b)){
			join(a, b);
			sum+=c;
			graf[a].push_back(make_pair(b, c));
			graf[b].push_back(make_pair(a, c));
			if(maksiroz==n) break;
		}
	}
	val[1][0] = 0;
	dfs(1);
	int best = 1e9;
	for(int i = 0; i < inp.size(); i++){
		int a = inp[i].second.first, b = inp[i].second.second, c = inp[i].first;
		int t = lca(a, b);
		if(c>t) best = min(best, c-t);
	}
	cout<<sum+(long long)best;
	return 0;
}
