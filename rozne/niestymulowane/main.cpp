#include <bits/stdc++.h>

using namespace std;
vector<vector<long long>> graf;
vector<long long> val, sz;
vector<bool> odw;
long long wyn = 0, n, mod = 1e9+7;

void dfs(long long x){
	odw[x] = true;
	sz[x] = 1;
	for(auto it:graf[x]){
		if(!odw[it]){
			dfs(it);
			sz[x]+=sz[it];
			val[x] += val[it]+sz[it];
		}
	}
}

void solve(long long x, long long p){
	odw[x] = true;
	long long tmp = val[p];
	if(p==-1) tmp = 0;
	else{
		tmp-=val[x]+sz[x];
		tmp+=n-sz[x];
	}
	val[x] += tmp;
	wyn+=(val[x]*val[x])%mod;
	for(auto it:graf[x]){
		if(!odw[it]) solve(it, x);
	}
}
			
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	graf.resize(n); sz.resize(n); val.resize(n); odw.resize(n);
	for(long long i = 0; i < n-1; i++){
		long long a, b; cin>>a>>b; a--; b--;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs(0);
	odw.resize(0);
	odw.resize(n);
	solve(0, -1);	
	wyn%=mod;
	cout<<(wyn*wyn)%mod;
	return 0;
}
