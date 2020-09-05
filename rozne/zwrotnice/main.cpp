#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, bool>>> graf;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, s, t; cin>>n>>s>>t;
	graf.resize(n);
	s--; t--;
	for(int i=  0;i < n; i++){
		int a, b; cin>>a>>b; a--; b--;
		graf[i].push_back(make_pair(a, false));
		graf[i].push_back(make_pair(b, true));	
	}
	
	vector<int> cost(n, 1e9);
	set<pair<int, int>> mp;
	mp.insert(make_pair(0, s));	
	cost[s] = 0;
	while(mp.size()){
		int cur = mp.begin()->second;
		int g = mp.begin()->first;
		mp.erase(mp.begin());
		for(auto it:graf[cur]){
			if(cost[it.first]>g+it.second){
				if(cost[it.first]!=1e9) mp.erase(make_pair(cost[it.first], it.first));
				cost[it.first] = g+it.second;
				mp.insert(make_pair(it.second+g, it.first));
			}
		}
	}
	if(cost[t]==1e9) cout<<"BRAK";
	else cout<<cost[t];	
	
	return 0;
}
