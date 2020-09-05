#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	vector<int> dp(1001);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for(int i = 4; i <= 1000; i++){
		vector<bool> tab(i+1);
		tab[dp[i-2]] = true;
		tab[dp[i-3]] = true;
		for(int j = 1; j <= i; j++){
			if(i-3-j<=0) break;
			int a = dp[j], b = dp[i-3-j];	
			tab[a^b] = true;
		}
		for(int j = 0; j <= i; j++){
			if(!tab[j]){
				dp[i] = j;
				break;
			}
		}
	}
	int q; cin>>q;
	for(int i = 0; i < q; i++){
		int a; cin>>a;
		a-=3;
		if(dp[a]==0) cout<<"Pierwszy\n";
		else cout<<"Drugi\n";
	}
	return 0;
}
