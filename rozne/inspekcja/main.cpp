#include <bits/stdc++.h>

using namespace std;
vector<vector<long long>> graf;
vector<bool> odw;
vector<long long> sz, odl, dlg, wyn;
bool skip = true;
long long n; 

void dfs(long long x){
	odw[x] = true;
	sz[x] = 1;
	odl[x] = 0;
	for(auto it:graf[x]){
		if(!odw[it]){
			dfs(it);
			sz[x]+=sz[it];
			odl[x]+=odl[it]+sz[it];
			dlg[x] = max(dlg[x], dlg[it]+1);
		}
	}
}

void solve(long long x, long long p){
	odw[x] = true;
	long long state = 0, maksi = n-sz[x]; 
	long long dmaks = p, dbig = p;
	long long fir = p-1, sec = -1, id1=-1, id2;
	for(auto it:graf[x]){
		if(!odw[it]) {
			if(sz[it]>maksi){
				dbig = dlg[it]+1;
				maksi = sz[it];
			}
			dmaks = max(dmaks, dlg[it]+1);
			if(dlg[it]>sec){
				if(dlg[it]>fir){
					sec = fir;
					id2 = id1;
					fir = dlg[it];
					id1 = it;
				}else{
					sec = dlg[it];
					id2 = it;
				}
			}
		}
	}
	if(maksi-1==n-1-maksi){	
		state = 1;
	}else if(maksi>n-1-maksi) state = -1;

	if(state==-1){
		wyn[x] = -1;
	}else if(state==0){
		wyn[x] = dmaks;
	}else wyn[x] = dbig;
	if(state!=-1) skip = false;
	for(auto it:graf[x]){
		if(!odw[it]){
			odl[it] += odl[x]-(odl[it]+sz[it])+(n-sz[it]);
			if(it==id1){
				solve(it, sec+2);
			}else solve(it, fir+2);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	graf.resize(n); odw.resize(n); sz.resize(n); odl.resize(n); wyn.resize(n); dlg.resize(n);
	for(long long i = 0; i < n-1; i++){
		long long a, b; cin>>a>>b; a--; b--;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs(0);
	odw.resize(0); odw.resize(n);
	solve(0, 0);
	if(skip) return 0;
	for(long long i = 0; i < n; i++){
		if(wyn[i]==-1) cout<<-1<<'\n';
		else cout<<2*odl[i]-wyn[i]<<'\n';
	}
	
	return 0;
}
