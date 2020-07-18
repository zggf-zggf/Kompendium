#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; 
	cin>>n>>m;
	vector<vector<int>> dp(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>dp[i][j];
			int tmp = 0;
			if(i>0) tmp = dp[i-1][j];
			if(j>0) tmp = max(tmp, dp[i][j-1]);
			dp[i][j] += tmp;
		}
	}
	cout<<dp[n-1][m-1];
	return 0;
}
