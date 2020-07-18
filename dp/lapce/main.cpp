#include <bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin>>t;
	for(int al = 0; al < t; al++){
		int k, n; cin>>k>>n;
		int mod = 1e9+9;
		vector<int> dp(n+1);
		dp[0] = dp[1] = 1;
		if(k==1) {cout<<1<<endl; continue;}
		for(int i = 2; i <= n; i++){
			if(i%k==0) dp[i] = dp[i-1]+dp[i/k];
			else dp[i] = dp[i-1];
			dp[i]%=mod;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
