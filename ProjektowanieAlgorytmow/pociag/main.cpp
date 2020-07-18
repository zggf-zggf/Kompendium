#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin>>n;
	vector<vector<int>> dp(n+1, vector<int>(2));
	bool pr = false;
	for(int i = 0; i < n; i++){
		char c; cin>>c;
		bool b = c=='b';
		dp[i][b] = 0;
		dp[i][!b] = 1;
		if(i>1){
			dp[i][b] = min(dp[i-1][!b], dp[i-2][!b] + (int)(pr!=b));
			dp[i][!b] = 1+min(dp[i-1][b], dp[i-2][b] + (int)(pr==b));
		}
		pr = b;
	}
	cout<<min(dp[n-1][0], dp[n-1][1]);
	return 0;
}
