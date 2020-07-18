#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin>>n;
	int lst = 0;
	vector<int> first(1e6+10), last(1e6+10);
	vector<int> tab(1);
	for(int i = 1; i <= n; i++){
		int a; cin>>a;
		tab.push_back(a);
		if(first[a]==0) first[a] = i;
		last[a] = i;
	}

	int pt = 0;
	int wyn = 0;
	vector<int> dp(n+2);
	
	for(int i = n; i > 0; i--){
		dp[i] = dp[i+1];
		if(first[tab[i]]==i){
			dp[i] = max(dp[i], 1+dp[last[tab[i]]]);
		}
	}
	cout<<dp[1];
	return 0;
}
