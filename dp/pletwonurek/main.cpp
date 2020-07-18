#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int a, b, n; cin>>a>>b>>n;
	
	vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		int x, y, w; cin>>x>>y>>w;
		for(int j = a; j >= 0; j--){
			for(int k = b; k >= 0; k--){
				int tx = min(x+j, a);
				int ty = min(y+k, b);
				dp[tx][ty] = min(dp[tx][ty], dp[j][k]+w);
			}
		}
	}
	cout<<dp[a][b];
	return 0;
}
