#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	vector<int> tab, dp;
	int n; cin>>n;
	for(int i = 0; i < n; i++){
		int a; cin>>a;
		a--;
		tab.push_back(a);
	}
	for(int i= 0; i < n; i++){
		int a; cin>>a; dp.push_back(a);	
	}
	for(int i = n-1; i >= 0; i--){
		if(tab[i]!=-1){
			dp[i] = dp[tab[i]];
		}
	}
	for(auto it:dp) cout<<it<<" ";
	return 0;

}
