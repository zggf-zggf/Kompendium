#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	vector<vector<int>> dp;
	int n; cin>>n;
	dp.resize(n, vector<int>(n));
	string s; cin>>s;
	int wyn = 0;
	for(int i = 0; i < n; i++){
		for(int j = n-1; j >= i; j--){
			if(s[i]==s[j]) {
				dp[i][j]=(i==j)?1:2;
				if(i>0&&j<n-1) dp[i][j] += dp[i-1][j+1];
			}else{
				if(i>0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
				if(j<n-1) dp[i][j] = max(dp[i][j], dp[i][j+1]);
				if(i>0&&j<n-1) dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
			}
			wyn = max(wyn, dp[i][j]);
		}
	}
	cout<<wyn;
	return 0;
}
