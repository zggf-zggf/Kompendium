#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n, k, s; cin>>n>>k>>s;
	vector<int> mp(s+1, 1e9);
	mp[0] = 0;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		for(int j = s-a; j>=0; j--){
			mp[j+a] = min(mp[j+a], mp[j]+1);
		}
	}
	for(int i = s; i >= 0; i--){
		if(mp[i]<=k){ cout<<i; return 0;}		
	}
	return 0;
}
