#include <bits/stdc++.h>

using namespace std;
vector<vector<long long>> graf;
vector<long long> low, order, wyn, sz;
long long cur = 1, n;

void dfs(long long x, long long parent = -1){
	order[x] = cur++;
	low[x] = order[x];
	sz[x] = 1;
	wyn[x] = n-1;
	long long sum = n-1;
	if(parent==-1) {wyn[x] = 0; sum=n;}
	for(auto it:graf[x]){
		bool nowy = false;
		if(order[it]==0) {
			nowy = true;
			dfs(it, x);
			if(parent==-1) {wyn[x]+=(sz[it]*(sum-sz[it])); sum-=sz[it];}
			low[x] = min(low[x], low[it]);
			sz[x]+=sz[it];
		}else{
			if(it!=parent) low[x] = min(low[x], order[it]);
		}
		if(it!=parent&&nowy){
			if(parent!=-1){
				if(low[it]>=order[x]){
					wyn[x]+=(sum-sz[it])*sz[it];
					sum-=sz[it];
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	long long m; cin>>n>>m;
	graf.resize(n); order.resize(n); sz.resize(n); low.resize(n); wyn.resize(n);
	for(long long i = 0; i < m;i++){
		long long a, b; cin>>a>>b; a--; b--;
		graf[a].push_back(b); graf[b].push_back(a);
	}
	dfs(0);
	for(auto it:wyn) cout<<it*2<<endl;
	return 0;
}
