#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graf;
vector<int> first; 
vector<long long> val;
vector<bool> odw;
vector<pair<int, int>> eul, tree;
long long n, q, treeSize, wyn = 0;

void dfs(long long x, long long lvl = 0){
	odw[x] = true;
	first[x] = eul.size();
	eul.push_back(make_pair(lvl, x));
	for(auto it:graf[x]){
		if(!odw[it]){
			dfs(it, lvl+1);
		}
		eul.push_back(make_pair(lvl, x));	
	}
}

long long pot(long long x){
	long long tmp = 1;
	while(x){
		tmp*=2;
		x/=2;
	}
	return tmp;
}

void make_lca(){
	treeSize = pot(eul.size());
	tree.resize(treeSize*2+1);
	for(long long i = 0;i < eul.size(); i++){
		tree[i+treeSize] = eul[i];
	}
	for(long long i = treeSize-1; i > 0; i--){
		tree[i] = min(tree[i*2], tree[i*2+1]);
	}
}

long long lca(long long a, long long b){
	a = first[a]; b = first[b];
	if(a>b) swap(a, b);
	a+=treeSize; b+=treeSize;
	pair<int, int> out = min(tree[a], tree[b]);
	while(a/2!=b/2){
		if(a%2==0) out = min(out, tree[a+1]);
		if(b%2==1) out = min(out, tree[b-1]);
		a/=2; b/=2;
	}
	return out.second;
}

void solve(long long x, long long p){
	odw[x] = true;
	for(auto it:graf[x]){
		if(!odw[it]){
			solve(it, x);
		}
	}
	if(p>-1) val[p]+=val[x];
	wyn = max(wyn, val[x]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>q;
	graf.resize(n); odw.resize(n);
	first.resize(n); 
	val.resize(n);
	for(long long i = 0; i < n-1; i++){
		long long a, b; cin>>a>>b; 
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	dfs(0);
	make_lca();
	odw.resize(0); odw.resize(n);
	for(long long i = 0; i < q; i++){
		long long a, b, c; cin>>a>>b>>c;
		long long la = lca(a, b);
		val[la] -= 2*c;
		val[a] += c;
		if(a!=b) val[b]+=c;
	}
	solve(0, -1);
	cout<<wyn;	
	return 0;
}
