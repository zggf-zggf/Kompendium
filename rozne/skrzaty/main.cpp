#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	unordered_map<int, bool> mp;
	int n, m; cin>>n>>m;
	for(int i = 2; i <= n; i++) mp[i] = true;
	bool pos = false;
	for(int i = 0; i < m; i++){
		int k; cin>>k;
		unordered_map<int, bool> coc;
		bool tmp = false;
		vector<int> nwm;
		for(int j = 0; j < k; j++){
			int a; cin>>a;
			if(!pos) if(a==1) tmp = true;
			if(pos) if(mp[a]) coc[a] = true;;
			if(!pos) nwm.push_back(a);
		}
		if(!tmp) pos = true;
		if(!tmp) for(auto it:nwm) coc[it] = true;
		mp = coc;
		if(pos) if(!mp[n]) {cout<<i; return 0;}	
	}
	cout<<m;
}
