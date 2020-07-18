#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin>>n>>m;
	string s, t; cin>>s>>t;
	vector<vector<int>> dp;
	dp.resize(n+1, vector<int>(m+1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i-1]==t[j-1]){
				dp[i][j] = dp[i-1][j] + dp[i][j-1]+1;
			}else dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];

		}
	}
	cout<<dp[n][m];
	return 0;
}
