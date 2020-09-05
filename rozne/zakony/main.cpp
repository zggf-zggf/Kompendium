#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, int>>> graf;
vector<int> odw2, odw, sz, val;
vector<bool> used;
unordered_map<int, int> T;
int n, cnt = 1;
long long wyn = 0;

void precent(int x){
	odw[x] = cnt;
	sz[x] = 1;
	for(auto it:graf[x]){
		if(odw[it.first]!=cnt&&!used[it.first]){
			precent(it.first);	
			sz[x]+=sz[it.first];
		}
	}
}

int troid(int x){
	for(auto it:graf[x]){
		if(!used[it.first]){
			if(sz[x] < 2*sz[it.first]){
				int tmp = sz[x];
				sz[x] -= sz[it.first];
				sz[it.first] = tmp;	
				return troid(it.first);
			}
		}
	}
	return x;
}

int centroid(int x){
	cnt++;
	precent(x);
	x = troid(x);	
	used[x] = true;
	return x;
}

void dfs(int x, int p){
	odw[x] = cnt;
	wyn+=T[-p];
	val.push_back(p);
	for(auto it:graf[x]){
		if(odw[it.first]==cnt-1){
			dfs(it.first, p+it.second);
		}
	}
}

void decomp(int x){
	x = centroid(x);
	cnt++;
	odw[x] = cnt;
	T.clear();
	T[0] = 1;
	for(auto it:graf[x]){
		if(!used[it.first]){
			dfs(it.first, it.second);
			for(auto nwm:val) T[nwm]++;
			val.resize(0);
		}
	}
	cnt++;
	for(auto it:graf[x]){
		if(!used[it.first]) decomp(it.first);
	}	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	odw.resize(n); graf.resize(n); used.resize(n); sz.resize(n);
	for(int i = 0; i < n-1; i++){
		int a, b; char c; cin>>a>>b>>c;
		a--; b--;
		int coc = 0;
		if(c=='W') coc=1;
		else {if(c=='M') coc = -1;}

		graf[a].push_back(make_pair(b, coc));
		graf[b].push_back(make_pair(a, coc));
	}
	decomp(0);	
	cout<<wyn;
	return 0;
}
